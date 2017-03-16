#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define f(i,n) for(i=1;i<=n;i++)
#define fa(i,a,n) for(i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define MOD  1000000009ll
int main()
{
int t1,i,j,k,n;
double a,b,t;
j=1;
in(t1);
    while(j<=t1){
	scanf("%lf",&a);scanf("%lf",&b);
	double p[5]={0.0f};double d;
	for(i=0;i<a;i++)scanf("%lf",&p[i]);
	if(a==1){ d=p[0]*(b-a+1)+(1.0f-p[0])*(b-a+1+b+1);
    double t=(b-a+2+1);
    if(t<d)d=t;
    t=b+2;
    if(t<d)d=t;
    }
    
    if(a==2){
             double p2[4];
             p2[0]=p[0]*p[1];
             p2[1]=p[0]*(1-p[1]);
             p2[2]=(1-p[0])*p[1];
             p2[3]=(1-p[0])*(1-p[1]);
             d=p2[0]*(b-a+1)+(p2[1]+p2[2]+p2[3])*(b-a+1+b+1);
             t=(p2[0]+p2[1])*(b-a+3)+(p2[2]+p2[3])*(b-a+3+b+1);
             if(t<d)d=t;
             t=(p2[0]+p2[1]+p2[2]+p2[3])*(b-a+1+4);
             if(t<d)d=t;
             t=(p2[0]+p2[1]+p2[2]+p2[3])*(b+2);if(t<d)d=t;
             }
             
        if(a==3){
                 double p2[8];
                 p2[0]=p[0]*p[1]*p[2];
                 p2[1]=p[0]*p[1]*(1-p[2]);
                 p2[2]=p[0]*(1-p[1])*p[2];
                 p2[3]=p[0]*(1-p[1])*(1-p[2]);
                 p2[4]=(1-p[0])*p[1]*p[2];
                 p2[5]=(1-p[0])*p[1]*(1-p[2]);
                 p2[6]=(1-p[0])*(1-p[1])*p[2];
                 p2[7]=(1-p[0])*(1-p[1])*(1-p[2]);
                 d=p2[0]*(b-a+1)+(p2[1]+p2[2]+p2[3]+p2[4]+p2[5]+p2[6]+p2[7])*(b-a+1+b+1);
                 t=(p2[0]+p2[1])*(b-a+1+2)+(p2[2]+p2[3]+p2[4]+p2[5]+p2[6]+p2[7])*(b-a+3+b+1);if(t<d)d=t;
                 t=(p2[0]+p2[1]+p2[2]+p2[3])*(b-a+1+4)+(p2[4]+p2[5]+p2[6]+p2[7])*(b-a+1+4+b+1);if(t<d)d=t;
                 t=(b-a+1+6)*(p2[0]+p2[1]+p2[2]+p2[3]+p2[4]+p2[5]+p2[6]+p2[7]);if(t<d)d=t;
                 t=(b+2)*(p2[0]+p2[1]+p2[2]+p2[3]+p2[4]+p2[5]+p2[6]+p2[7]);if(t<d)d=t;
                 }   
                 
               printf("Case #%d: %lf\n",j,d); j++;   
	}
    
    return 0;}
