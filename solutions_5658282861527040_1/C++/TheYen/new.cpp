#include<stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
freopen("kanish.in", "r", stdin);
 freopen("kanish.out", "w", stdout);
long long int t,p=0;
scanf("%lld",&t);
while(t--)
{
long long int a,b,k,i,j,c=0,x,pp,y=1;
scanf("%lld %lld %lld",&a,&b,&k);
pp=a*b;
for(i=k;i<a;i++)
{
for(j=k;j<b;j++)
{
x=i&j;
if(x>=k)
{
c++;
}
}
}
printf("Case #%lld: %lld\n",++p,pp-c);
}
return 0;
}
