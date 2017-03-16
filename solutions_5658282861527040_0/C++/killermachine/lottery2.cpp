#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
int t,x=1,i,j,a,b,k;
scanf("%d",&t);
while(t--){
int ret=0;
cin>>a>>b>>k;
for(i=0;i<a;i++)
for(j=0;j<b;j++)
if((i&j)<k)
ret++;
printf("Case #%d: %d\n",x,ret);
x++;
}
return 0;
}
