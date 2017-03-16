#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
double fn(double c,double f,double t,int x)
{
if(x<0)return 1000000000;
double ans=0;
for(int i=0;i<x;++i)
{
ans+=(c/(2+i*f));
}
ans+=t/(2+x*f);
return ans;
}
void doit(int tc)
{
double c,f,t;
cin>>c>>f>>t;
double ans=1000000000;
double x=(t/c)-1-(2/f);
if(x<-1)x=0;
ans=min(ans,fn(c,f,t,x-1));
ans=min(ans,fn(c,f,t,x));
ans=min(ans,fn(c,f,t,x+1));
printf("Case #%d: %0.7lf\n",tc,ans);
}
int main()
{
int t;
cin>>t;
int i=1;
while(t--)
{
doit(i++);
}
return 0;
}
