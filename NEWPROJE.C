






		       /*project work for data structure
		       SUB:BASIC CALCULATOR
		       date of starting:19/10/16
		       date of finishing:09/11/16
		       written by Sourav Pati */











#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define e 2.71828183
#define ARITHMETIC 4
#define TRIGONMETRY 5
#define COMPLEX 6
#define EQUATION 7
#define INTEGRATION 8
#define DIFFERENTION 9
#define SUMMATION 10
#define MATRIX 40
#define CLEAR 100
#define YES -1
#define NO 0

float trigonmetry(float);
void arith_nvar(int);
void complex();
void squrot(float,float);
float argument(float,float);
float amplitude(float,float);
void po_fm(float,float);
void equation();
void ovod(float,float);
void ovtd(float,float,float);
void ovthd(float,float,float,float);
void tv();
void thv();
long int fact (int);
void integration();
void diff();
void sum();
void com_two();
void matrix();
void trace(float [10][10],int);
void inverse(float [10][10],int ,int);
void transpose(float [10][10],int,int);
void mat_mul(float [10][10],float [10][10],int,int,int,int);
float value(float [10][10],int,int);
void mat_add(float [10][10],float [10][10],int,int);
void mat_sub(float [10][10],float [10][10],int,int);
void mat_adj(float [10][10],int );

void main()
{

int n,ch1,ch2,ch3,ch15;
float deg,val,rad;
clrscr();
	for( ; ; )
	{
	  printf("Welcome\nEnter\n 1 to see list of operation supported by this calculator\n 2 to choose any of the operation\n 3 to exit\n");
	  scanf("%d",ch1);
		switch(ch1)
		{
		case 1:printf("list of operation supported by this calculator are\n1.Basic Arithmetic\n2.Trigonmetric\n3.Complex Nmber\n4.Equation\n5.Integration\n6.Summation\n7.Differention\n8.Matrix\n9.Clear the screen\n");
		      break;
		case 2:printf("Enter \n4.Arithmetic\n5.Trigonometric\n6.Complex Number\n7.Equation\n8.Integration\n9.Differention \n10.Summation\n40.Matrix\n100.to clear screen\n");
		       scanf(" %d",ch2);
			switch(ch2)
			{
			case 4:printf("Enter the number of operands\n");
			      scanf("%d",&n);
			      arith_nvar(n);
			      break;
			case 5:printf("enter the angle in degrees\n");
			       scanf("%f",&deg);
			       val=trigonmetry(deg);
			       if(val!=-1)
			       printf("result is %f\n",val);
			       break;
			case 6:complex();
			       break;
			case 7:equation();
			       break;
			case 8:integration();
			       break;
			case 9:diff();
			       break;
			case 10:sum();
			       break;
			case 40:matrix();
			       break;
			case 100:printf("are you sure ?you want to clear the screen\nYes(90)     NO(91)\n");
				 scanf("%d",ch15);
				 switch(ch15)
				 {
				 case 90:clrscr();
					 break;
				 case 91:printf("Ok!screen will not be cleared\n");
					 break;
				 default:printf("Enter some valid input\n");
				 }//switch for clrscr()
			} //case 2 switch
		      break;
		case 3:printf("Are you sure to Exit?\nYes(-1)   No(0)\n");
		       scanf("%d",&ch3);
				switch(ch3)
				{
				case 0:printf("Thank you !\n");
				       break;
				case -1:exit(0);
				}
		       break;
		default:printf("You have choose an invalid option!\nPlease choose anyone of 1,2,3 for valid operation\n");
		}//main switch
	}//for loop
}//void main
void arith_nvar(int n)
{
int i,ch4,ch5,ope;
long int factn;
double res,op[20],val,m;
	if(n==1)
	{
	printf("enter the operand\n");
	scanf("%lf",&val);
	printf("Enter\n11.x^m   12.Factorial(x) \n",val,val);
	scanf("%d",&ch4);
		switch(ch4)
		{
		case 11:printf("enter the m value\n");
			scanf("%lf",&m);
			res=pow(val,m);
			printf("value of %lf^%lf is %lf\n",val,m,res);
			break;
		case 12:ope=val;
			 factn=fact(ope);
			 printf("value of %d! is %ld\n",ope,factn);
			 break;
		}//switch
	}//closing of if(n==1)
	else
	{
	printf("enter the operand no 1\n");
	scanf("%lf",&res);
		for(i=1;i<n;i++)
		{
		printf("\n13.Add   14.Sub   15.Mul   16.Div\n");
		scanf("%d",&ch5);
		printf("enter the operand no %d\n",i+1);
		scanf("%lf",&op[i]);
			switch(ch5)
			{
			case 13:res=res+op[i];
				break;
			case 14:res=res-op[i];
				break;
			case 15:res=res*op[i];
				break;
			case 16:res=res/op[i];
				break;
			}//switch
		}//for
	printf("final result of your expression is %lf\n",res);
	}//else


}//closing of arithmetic function
float trigonmetry(float deg)
{
int ch6,flag=1;
float rad,val;
rad=((3.14*deg)/180);
printf("17.Sine  18.Cos  19.Tan  20.Cosec  21.Sec  22.Cot\n");
printf("enter your choice\n");
scanf("%d",&ch6);
	switch(ch6)
	{
	case 17:val=sin(rad);
		break;
	case 18:val=cos(rad);
		break;
	case 19:val=tan(rad);
		break;
	case 20:val=(1/sin(rad));
		if(val<1)
		flag=0;
		break;
	case 21:val=(1/cos(rad));
		if(val<1)
		flag=0;
		 break;
	case 22:/*if(deg==0 | 180 | 360 | 540 | 720 | 900 | 1080)
		{
		printf("!!indetermined value\n");
		flag=0;
		}
		else */
		val=(1/tan(rad));

	}     //switch
if(flag!=0)
return val;
else
return -1;
} //trigonometry
void complex()
{
int ch7,n;
float a,b,amp,arg,c,d,res1,res2;
printf("enter the number of complex number(should be maximum 2)\n");
scanf("%d",&n);
if(n==2)
com_two();
else
{
printf("enter the real and imaginary parts\n");
scanf("%f%f",&a,&b);
printf("23.conjugate   24.amplitude  25.argument  26.squre root 27.polar form\n");
scanf("%d",&ch7);
	switch(ch7)
	{
	case 23:printf("conjugate of %.3f+i%.3f is %.3f-i%.3f\n",a,b,a,b);
		break;
	case 24:amp=amplitude(a,b);
		printf("amplitude of %.3f+i%.3f is=%.3f\n",a,b,amp);
		break;
	case 25:arg=argument(a,b);
		if(arg!=NULL)
		{
		arg=arg*(180/3.14);
		printf("argument of %.3f+i%.3f is=%.3f\n",a,b,arg);
		}
		break;
	case 26:squrot(a,b);
		break;
	case 27:po_fm(a,b);
		break;
	}//switch
}
}//complex main function

void squrot(float a,float b)
{
 float res1,res2,res3,res;
 res=sqrt(a*a+b*b);
 res1=sqrt((a+res)/2);
 res2=sqrt((res-a)/2);
 printf("squre root of %.3f+i%.3f if+_(%.3f+i%.3f)\n",a,b,res1,res2);
}     //squre root
float amplitude(float a,float b)
{
return sqrt(a*a+b*b);
}//amplitude
float argument(float a,float b)
{
float val,theta;
if(a>0 && b>0)
return (atan((b/a)));
else if(a<0 && b>=0)
return (3.14+(atan(b/a)));
else if(a<0 &&b<0)
return ((atan(b/a))-3.14);
else if(a==0 && b>0)
return(3.14/2);
else if(a==0 && b<0)
return ((-3.14/2));
else
{
printf("!!indetermined\n");
return NULL;
}
}//argument

void po_fm(float a,float b)
{
float amp,val,arg;
amp=amplitude(a,b);
val=argument(a,b);
arg=(val*(180/3.14));
printf("polar form of %.3f+i%.3f is %.3f(cos(%.3f)+i sin(%.3f))\n",a,b,amp,arg,arg);
}  //polar form
void equation()
{
int var,deg;
float a,b,c,d;
printf("enter the number of variable and degree of the equation\n");
scanf("%d%d",&var,&deg);
	if(var==1 && deg==1)
	{
	printf("General form:ax+b=0\nenter a,b values\n");
	scanf("%f%f",&a,&b);
	ovod(a,b);
	}
	else if(var==1&&deg==2)
	{
	printf("General form:ax^2+bx+c=0\nenter a,b,c values\n");
	scanf("%f%f%f",&a,&b,&c);
	ovtd(a,b,c);
	}
	else if(var==1 && deg==3)
	{
	printf("General form:ax^3+bx^2+cx+d=0\nenter a,b,c,d values\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	ovthd(a,b,c,d);
	}
	else if(var==2 && deg==1)
	tv();
	else if(var ==3 && deg==1)
	thv();
	else
	{
	printf("if number of variable>1(maximum 3) then degree should be =1\n");
	return;
	}
}//equation main function
void tv()
{
float a1,a2,b1,b2,c1,c2,sol1,sol2;
printf("Enter a1 b1 c1 a2 b2 c2\n");
scanf("%f%f%f%f%f%f",&a1,&b1,&c1,&a2,&b2,&c2);
if((a1*b2)==(a2*b1))
{
printf("!!give some valid inputs\n");
return;
}
sol2=((a1*c2-a2*c1)/(a1*b2-a2*b1));
sol1=(((c2)-(b2*sol2))/a2);
printf("solution of %.3fX+%.3fY=%.3f\n",a1,b1,c1);
printf("                             is x=%.3f    and y=%.3f\n",sol1,sol2);
printf("            %.3fX+%.3fY=%.3f\n",a2,b2,c2);
}//two variable equation
void ovod(float a,float b)
{
float sol;
if(a==0)
{
printf("!!give some valid inputs\n");
return ;
}
sol=(-b/a);
printf("solution of %.3fX+%.3f=0 is %.3f\n",a,b,sol);
}
void thv()
{
float a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3,sol1,sol2,sol3,deno,x,y,z;
printf("Enter a1 b1 c1 d1 a2 b2 c2 d2 a3 b3 c3 d3 values\n");
scanf("%f%f%f%f%f%f%f%f%f%f%f%f",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2,&a3,&b3,&c3,&d3);
deno=((a1*b2*c3+a2*b3*c1+a3*b1*c2)-(a1*b3*c2+a2*b1*c3+a3*b2*c1));
x=((b1*c2*d3+b2*c3*d1+b3*c1*d2)-(b1*c3*d2+b2*c1*d3+b3*c2*d1));
y=((a1*c3*d2+a2*c1*d3+a3*c2*d1)-(a1*c2*d3+a2*c3*d1+a3*c1*d2));
z=((a1*b2*d3+a2*b3*d1+a3*b1*d2)-(a1*b3*d2+a2*b1*d3+a3*b2*d1));
if(deno==0)
{
printf("solution can not found\n");
return;
}
sol1=(x/deno);
sol2=(y/deno);
sol3=(z/deno);
printf("solution of %.3fX+%.3fY+%.3fZ=%.3f\n",a1,b1,c1,d1);
printf("            %.3fX+%.3fY+%.3fZ=%.3f      is x=%.3f  y=%.3f  z=%.3f\n",a2,b2,c2,d2,sol1,sol2,sol3);
printf("            %.3fX+%.3fY+%.3fZ=%.3f\n",a3,b3,c3,d3);
}//three variable
void ovtd(float a,float b,float c)
{
float root1,root2,real,imag,disc;
	if(a==0 && b==0)
	{
	printf("!!give valid input\n");
	return;
	}
	else if(a==0)
	ovod(b,c);
	else
	{
	disc=(b*b-4*a*c);
		if(disc==0)
		{
		root1=((-b)/(2*a));
		printf("solution of %.3fX^2+%.3fX+%.3f =0 is X=%.3f and X=%.3f\n",a,b,c,root1,root1);
		}
		else if(disc>0)
		{
		root1=(((-b)+sqrt(disc))/(2*a));
		root2=(((-b)-sqrt(disc))/(2*a));
		printf("solution of %.3fX^2+%.3fX+%.3f=0 is X=%.3f and X=%.3f\n",a,b,c,root1,root2);
		}
		else
		{
		real=((-b)/(2*a));
		imag=((sqrt(fabs(disc)))/(2*a));
		printf("solution of %.3fX^2+%.3fX+%.3f=0 is X=%.3f+i %.3f  and X=%.3f -i %.3f\n",a,b,c,real,imag,real,imag);
		}
	}
}//one variable two degree
void ovthd(float a,float b,float c,float d)
{
int i,flag=0;
float e1,f,g;
	if(a==0 && b==0 && c==0)
	{
	printf("!!give valid inputs\n");
	return;
	}
	else if(a==0 & b==0)
	ovod(c,d);
	else if(a==0)
	ovtd(b,c,d);
	else
	{
		for(i=-4;i<=5;i++)
		{
		if(a*i*i*i+b*i*i+c*i+d==0)
		{
		 printf("roots are X=%d\n",i);
		 e1=a;
		 f=(b+(e1*i));
		 g=(c+(f*i));
		 ovtd(e1,f,g);
		 flag=1;
		  break;
		}

		}
		if(flag ==0)
		{
		printf("!!sorry can not evalute\nin trial-error method first root must be an integer value \n");
		return;
		}
	}
}//three degree one variable
void integration()
{
int n,i;
double expon[10],coeff[10],ul[10],ll[10],val=0;
printf("please give input only for polynomial function\n");
printf("enter the number of terms\n");
scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter the coeffecient of term no %d\n",i+1);
	scanf("%lf",&coeff[i]);
	printf("enter the degree of term no %d\n",i+1);
	scanf("%lf",&expon[i]);
	printf("enter the upper limit of term no %d\n",i+1);
	scanf("%lf",&ul[i]);
	printf("enter the lower limit of term no %d\n",i+1);
	scanf("%lf",&ll[i]);
	}
	for(i=0;i<n;i++)
	{
	val=val+(coeff[i]/(expon[i] +1))*(pow(ul[i],(expon[i] +1))-pow(ll[i],(expon[i] +1)));
	}
	printf("Final result is %lf\n",val);
}//integration function
void sum()
{
double val=0,deg,ul,ll,i;
printf("please enter only for algebric function\n");
printf("enter the degree of the function\n");
scanf("%lf",&deg);
printf("enter the upper and lower limit of the summation\n");
scanf("%lf%lf",&ul,&ll);
	for(i=ll;i<=ul;i++)
	val=val+pow(i,deg);
printf("final result is %lf\n",val);
}//summation function
void diff()
{
float exp[5],coeff[5];
int n,i;
printf("please enter only algebric function\n");
printf("enter the number of terms in the expression\n");
scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter the coefficient of term no %d\n",i+1);
	scanf("%f",&coeff[i]);
	printf("enter the degree of term no %d\n",i+1);
	scanf("%f",&exp[i]);
	}
	printf("final result is\n");
	for(i=0;i<=(n-2);i++)
	printf("%.2f x^%.2f+",(coeff[i]*exp[i]),(exp[i]-1));
	printf("%.2f x^%.2f\n",(coeff[n-1]*exp[n-1]),(exp[n-1]-1));
}//differention function
void com_two()
{
int ch9;
float a,b,c,d,real,imng;
printf("enter the real and imaginary part of the first complex number\n");
scanf("%f%f",&a,&b);
printf("enter the real and imaginary part of the second complex number\n");
scanf("%f%f",&c,&d);
printf("30.Add   31.Sub   32.MUl\nenter your choice\n");
scanf("%d",&ch9);
	switch(ch9)
	{
	case 30:real=a+c;
		imng=b+d;
		printf("result of(%.3f+i %.3f)+(%.3f+i %.3f) is %.3f+i%.3f\n",a,b,c,d,real,imng);
		break;
	case 31:real=a-c;
		imng=b-d;
		printf("result of (%.3f+i %.3f)-(%.3f+i %.3f) if %.3f+i %.3f\n",a,b,c,d,real,imng);
		break;
	case 32:real=(a*c);
		imng=(b*d);
		printf("result of (%.3f+i %.3f)x(%.3f+i %.3f) is %.3f-i %.3f\n",a,b,c,d,real,imng);
	}//switch
}
long int fact(int x)
{
if(x==0)
return 1;
else
return (x*fact(x-1));
} //factorial
void matrix()
{
int mat,m,n,p,q,ch10,ch11,i,j;
float a[10][10],b[10][10],c[10][10],val;
printf("enter the no of matrix(maximum 2)\n");
scanf("%d",&mat);

	if(mat==1)
	{
	printf("enter the order of matrix\n");
	scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
			printf("enter element\n");
			scanf("%f",&a[i][j]);
			}
		} //taking input for matrix
printf("operation on a single matrix are\n41.Transpose   42.value   43.Trace   44.Inverse   45.Adjoint\n");
scanf("%d",&ch10);
		switch(ch10)
		{
		case 41:transpose(a,m,n);
			break;
		case 42:if((m==2 && n==2)|(m==3 && n==3))
			{
			val=value(a,m,n);
			printf("\nvalue is %.1f\n",val);
			}
			else
			printf("Matrix must be a square matrix\n");
			break;
		case 43:if(m==n)
			trace(a,m);
			else
			printf("Matrix must be square matrix\n");
			break;
	       case 44:if(m==n)
			inverse(a,m,n);
			else
			printf("matrix must be square one\n");
			break;
		case 45:if(m==n)
			mat_adj(a,m);
			else
			printf("matrix must be square matrix\n");
			break;
		}//switch for 1 matrix
	}//if mat==1
	else if(mat==2)
	{
	printf("enter the order of matrix a\n");
	scanf("%d%d",&m,&n);
	printf("enter the order of matrix b\n");
	scanf("%d%d",&p,&q);
		if((m==p)&&(n==q))
		{
		printf("enter matrix a\n");
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
				printf("enter element\n");
				scanf("%f",&a[i][j]);
				}
			} //input for matrix a
		printf("\nenter matrix b\n");
			for(i=0;i<p;i++)
			{
				for(j=0;j<q;j++)
				{
				printf("enter elements\n");
				scanf("%f",&b[i][j]);
				}
			} //input for matrix b
		printf("46.Add  47.Sub  48.Mul\n");
		scanf("%d",&ch11);
			switch(ch11)
			{
			case 46:
				mat_add(a,b,m,n);
				break;
			case 47:
				 mat_sub(a,b,m,n);
				 break;
			case 48:if(n==p)
				mat_mul(a,b,p,q,m,n);
				else
				printf("n !=p multiplication is not possible\n");
				break;
			}//switch for 2 matrix
		}//if M==P && N==Q
		else
		printf("order should be same of two matrix\n");
	}//if mat==2
	else
	printf("!!you can enter maximum 2 matrix\n");
}//matrix main function
float value(float a[10][10],int m,int n)
{ float res;
int i,j;
	if(m==2 && n==2)
	{
	res=((a[0][0] *a[1][1])-(a[1][0] *a[0][1]));
	printf("value of given matrix is \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.1f\t",a[i][j]);
		}
		printf("\n");
	}
	}//if m=n=2
	else
	{
	res=(((a[0][0] * a[1][1] * a[2][2])+(a[0][1] * a[2][0] *  a[1][2])+(a[0][2] * a[1][0] *a[2][1])) -((a[0][0] * a[2][1] * a[1][2])+(a[0][1] * a[1][0] *a[2][2])+(a[0][2] * a[2][0] * a[1][1])));
	}
return res;
}//matrix value
void mat_add(float a[10][10],float b[10][10],int m,int n)
{
int i,j;
float c[10][10];
   for(i=0;i<m;i++)
   {
	for(j=0;j<n;j++)
	{
	  c[i][j]=a[i][j]+b[i][j];
	}
   }  //calculating c matrix
printf("result of\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.1f\t",a[i][j]);
		}
		printf("\n");
	}//printing a matrix
printf("\n         +\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.1f\t",b[i][j]);
		}
		printf("\n");
	} //printing b matrix
printf("\n         is \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.1f\t",c[i][j]);
		}
		printf("\n");
	}  //printing c matrix
}//matrix addition  function
void mat_sub(float a[10][10],float b[10][10],int m,int n)
{
int i,j;
float c[10][10];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		c[i][j]=((a[i][j])-(b[i][j]));
		}
	}//calculating c matrix
printf("result of\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.1f\t",a[i][j]);
		}
		printf("\n");
	}//printing matrix a
printf("\n       --\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.1f\t",b[i][j]);
		}
		printf("\n");
	} //printing b matrix
printf("\n       is\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.1f\t",c[i][j]);
		}
		printf("\n");
	}//printing c matrix
}//matrix subtraction function
void trace(float a[10][10],int m)
{
int i=0,j=0;
float res=0;
       while(i<m)
       {
		if(i==j)
		{
		res=res+a[i][j];
		}
	 i++,
	 j++;
       }
printf("Trace of given matrix is %.1f\n",res);
}
void mat_adj(float a[10][10],int m)
{
float c[10][10],b[10][10];
int i,j;
	if(m==2)
	{
	 b[0][0]=a[1][1];
	 b[0][1]=-a[0][1];
	 b[1][0]=-a[1][0];
	 b[1][1]=a[0][0];
	 printf("adj(a)=\n");
	 for(i=0;i<2;i++)
	 {
		for(j=0;j<2;j++)
		{
		printf("%.1f\t",b[i][j]);
		}
		printf("\n");
	 }
	 }// for 2x2 matrix
	 else
	 {
	 b[0][0]=((a[1][1]*a[2][2])-(a[2][1]*a[1][2]));
	 b[0][1]=((a[2][1]*a[0][2])-(a[0][1]*a[2][2]));
	 b[0][2]=((a[0][1]*a[1][2])-(a[1][1]*a[0][2]));
	 b[1][0]=((a[2][0]*a[1][2])-(a[1][0]*a[2][2]));
	 b[1][1]=((a[0][0]*a[2][2])-(a[2][0]*a[0][2]));
	 b[1][2]=((a[1][0]*a[0][2])-(a[0][0]*a[1][2]));
	 b[2][0]=((a[1][0]*a[2][1])-(a[2][0]*a[1][1]));
	 b[2][1]=((a[0][1]*a[2][0])-(a[0][0]*a[2][1]));
	 b[2][2]=((a[0][0]*a[1][1])-(a[1][0]*a[0][1]));
	 printf("adj(a)=\n");
	 for(i=0;i<m;i++)
	 {
		for(j=0;j<m;j++)
		{
		printf("%.1f\t",b[i][j]);
		}
		printf("\n");
	 }
	 }//matrix 3x3

}//adjoint matrix
void transpose(float a[10][10],int m,int n)
{
int i,j;
float c[10][10];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		c[j][i]=a[i][j];
		}
	}  //calculating transpose matrix
printf("Transpose of matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.1f\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\nis\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		printf("%.1f\t",c[i][j]);
		}
		printf("\n");
	}//printing transpose matrix
}//transpose function
void inverse(float a[10][10],int m,int n)
{
int i,j;
float b[10][10],val;
	if(m==2)
	{
	b[0][0]=a[1][1];
	b[0][1]=-a[0][1];
	b[1][0]=-a[1][0];
	b[1][1]=a[0][0];
	}//if m=n=2 then value of b
	else
	{
	b[0][0]=((a[1][1]*a[2][2])-(a[2][1]*a[1][2]));
	b[0][1]=((a[2][1]*a[0][2])-(a[0][1]*a[2][2]));
	b[0][2]=((a[0][1]*a[1][2])-(a[1][1]*a[0][2]));
	b[1][0]=((a[2][0]*a[1][2])-(a[1][0]*a[2][2]));
	b[1][1]=((a[0][0]*a[2][2])-(a[2][0]*a[0][2]));
	b[1][2]=((a[1][0]*a[0][2])-(a[0][0]*a[1][2]));
	b[2][0]=((a[1][0]*a[2][1])-(a[2][0]*a[1][1]));
	b[2][1]=((a[0][1]*a[2][0])-(a[0][0]*a[2][1]));
	b[2][2]=((a[0][0]*a[1][1])-(a[1][0]*a[0][1]));
	} //if m=n=3 then b matrix value
val=value(a,m,n);
	if(val==0)
	{
	printf("inverse matrix cannot be found\n");
	}
	else
	{
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		b[i][j]=((b[i][j])/val);
		}
	}//calculating inverse matrix
	printf("inverse of the matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%0.3f\t",a[i][j]);
		}
		printf("\n");
	}//printing the matrix a
	printf("\n           is\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.3f\t",b[i][j]);
		}
		printf("\n");
	}//printing inverse matrix
	}//if val !=0
}//inverse matrix function
void mat_mul(float a[10][10],float b[10][10],int p,int q,int m,int n)
{
int i,j;
float c[10][10];
	if(n==2 && p==2)
	{
	c[0][0]=((a[0][0]*b[0][0])+(a[0][1]*b[1][0]));
	c[0][1]=((a[0][0]*b[0][1])+(a[0][1]*b[1][1]));
	c[1][0]=((a[1][0]*b[0][0])+(a[1][1]*b[1][0]));
	c[1][1]=((a[1][0]*b[0][1])+(a[1][1]*b[1][1]));
	}//calculating c matrix
	else
	{
	c[0][0]=((a[0][0]*b[0][0])+(a[0][1]*b[1][0])+(a[0][2]*b[2][0]));
	c[0][1]=((a[0][0]*b[0][1])+(a[0][1]*b[1][1])+(a[0][2]*b[2][1]));
	c[0][2]=((a[0][0]*b[0][2])+(a[0][1]*b[1][2])+(a[0][2]*b[2][2]));
	c[1][0]=((a[1][0]*b[0][0])+(a[1][1]*b[1][0])+(a[1][2]*b[2][0]));
	c[1][1]=((a[1][0]*b[0][1])+(a[1][1]*b[1][1])+(a[1][2]*b[2][1]));
	c[1][2]=((a[1][0]*b[0][2])+(a[1][1]*b[1][2])+(a[1][2]*b[2][2]));
	c[2][0]=((a[2][0]*b[0][0])+(a[2][1]*b[1][0])+(a[2][2]*b[2][0]));
	c[2][1]=((a[2][0]*b[0][1])+(a[2][1]*b[1][1])+(a[2][2]*b[2][1]));
	c[2][2]=((a[2][0]*b[0][2])+(a[2][1]*b[1][2])+(a[2][2]*b[2][2]));
	}
	printf("result of \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%.2f\t",a[i][j]);
		}
		printf("\n");
	}//printing a matrix
	printf("       X\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
		printf("%.2f\t",b[i][j]);
		}
		printf("\n");
	}//printing b matrix
	printf("\n      is\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
		printf("%.2f\t",c[i][j]);
		}
		printf("\n");
	}//printing c matrix
}








