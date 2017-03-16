#include<stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
freopen("kamal.in", "r", stdin);
freopen("kamal.out", "w", stdout);
long long int t,p=0;
scanf("%lld",&t);
while(t--)
{
long long int aa,bb,kk,i,j,c=0,x,pp;
scanf("%lld %lld %lld",&aa,&bb,&kk);
pp=aa*bb;
for(i=kk;i<aa;i++)
{
for(j=kk;j<bb;j++)
{
x=i&j;
if(x>=kk)
{
c++;
}
}
}
printf("Case #%lld: %lld\n",++p,pp-c);
}
return 0;
}
