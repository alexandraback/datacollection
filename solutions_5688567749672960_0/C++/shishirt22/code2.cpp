#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int A[1000100];
int rev(int i)
{
    int ans=0;
    int a=0;
 while(i>0)
 {
     a=i%10;
     ans=ans*10+a;
     i=i/10;
 }
 return ans;
}
int main()
{
int t,i,a,n;
A[0]=0;
for(i=0;i<1000100;i++)
    A[i]=1000000;
    A[0]=0;
scanf("%d",&t);
for(i=1;i<=1000000;i++)
{
    A[i]=min(A[i],A[i-1]+1);
    a=rev(i);
    if(a>i&&A[a]>(A[i]+1))
        A[a]=A[i]+1;
}
for(i=1;i<=t;i++)
{
    scanf("%d",&n);
printf("Case #%d: %d\n",i,A[n]);
}
}
