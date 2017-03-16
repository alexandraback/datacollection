#include<stdio.h>
#include<math.h>
int main()
{
int t,N,A,i,j,k;
float tt,a[10],d,ti[2],x[2],time,l,m;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
scanf("%f%d%d",&d,&N,&A);
for(j=0;j<N;j++)
scanf("%f%f",&ti[j],&x[j]);
for(k=0;k<A;k++)
scanf("%f",&a[k]);
if(N==2)
{l=x[1]-x[0];
m=ti[1]-ti[0];
time=(m*(d-x[0]))/l;}
else
time=ti[0];
printf("Case #%d:\n",i);
for(k=0;k<A;k++)
{
tt=sqrt(2*d/a[k]);
if(tt>time)
printf("%f\n",tt);
else
printf("%f\n",time);
}
}
return 0;
}
 