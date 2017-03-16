#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;



double solvequad(double a, double b, double c)
{
return ((-b+sqrt(b*b-4.0*a*c))/(2.0*a));
}


double findtime(int l, int n, double t[2000], double x[2000], double ax[250], double d)
{
double a;
a=ax[l];


double s=0;
double u=0;
double time=0;
double timebar,sbar,ubar;
timebar=sbar=ubar=0;
int i;
for(i=1;i<n;i++)
{
double tt,xx;
double xi;



tt=t[i]-t[i-1];
xx=x[i]-x[i-1];

if(s+u*tt+0.5*a*tt*tt < x[i])
{

timebar=time+tt;
ubar=u+a*tt;
sbar=s+u*tt+0.5*a*tt*tt;
if(abs(sbar-d)<=0.000000001)
return timebar;
else if(s<=d && (x[i]<=d && abs(x[i]-d)>0.000000001))
{
time=timebar;
u=ubar;
s=sbar;

}
else if(sbar<=d && (x[i]>d || abs(x[i]-d)<0.000000001))
{
return time+solvequad(0.5*a,u,s-d);
}
else if(sbar>d)
{
return time+solvequad(0.5*a,u,s-d);
}

}



else
{
/*
double tbar;
double aq=o.5*a;
double bq=u-xx/tt;
double cq=-x[i-1];
tbar=solvequad(aq,bq,cq);
*/

sbar=x[i];
ubar=xx/tt;
timebar=time+tt;


if(abs(sbar-d)<=0.000000001)
return timebar;
else if(sbar<d)
{
time=timebar;
u=ubar;
s=sbar;
}
else if(sbar>d)
{
return time+max(solvequad(0.5*a,u,s-d),(d-s)/(xx/tt));
}
}
}
return 0;

}
int main()
{
int n,a1;
double d;
double t[2000],x[2000];
double ax[250];

int tests,testno;
int i,j;
cin>>tests;
for(testno=1;testno<=tests;testno++)
{
cout<<"Case #"<<testno<<":"<<endl;

cin>>d>>n>>a1;

for(i=0;i<n;i++)
{cin>>t[i]>>x[i];
/*
if(x[i]>d || abs(d-x[i])<=0.000001)
{
n=i+1;
break;
}
*/
}
for(i=0;i<a1;i++)
cin>>ax[i];


int k;
for(k=0;k<a1;k++)
printf("%lf\n",findtime(k,n,t,x,ax,d));




}

return 0;
}
