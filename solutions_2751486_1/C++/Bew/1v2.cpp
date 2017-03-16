#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
char c[1000111];
int a[1000111];
int T;
int n,m;
long long ans;
int f(int p,int q)
{
  if(q-p+1<m)return 0;
  int i,j,k;
  j=q-m;
  k=a[q]-a[j];
  if(k==m)return 1;
  return 0;
}
int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("A-large (1).out","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    int *pt;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%s",c);
    n=strlen(c);
    scanf("%d",&m);
    a[0]=0;
    for(i=1;i<=n;i++)
     {
     t=0;
     if(c[i-1]=='a')t=1;
     if(c[i-1]=='e')t=1;
     if(c[i-1]=='i')t=1;
     if(c[i-1]=='o')t=1;
     if(c[i-1]=='u')t=1;
      if(t==1)a[i]=0;
      else a[i]=1;
     }
    for(i=1;i<=n;i++)
     {
       a[i]+=a[i-1];
     }
     a[n+1]=1999999999;
    // for(i=0;i<=n+1;i++)printf("%d ",a[i]);printf("\n");
    ans=0;
    p=1;q=m;
if(m!=1)
{
    while(p<=q)
     {
       k=f(p,q);
     //  printf("> %d %d %d\n",p,q,k);
       if(k==1)
        {
          ans+=(long long)(n-q+1);
          p++;
        }
       else
        {
          if(q==n)break;
          q++;
        }
     }
    while(p<=q)
     {
       k=f(p,q);
       if(k==1)
        {
          ans+=(long long)(n-q+1);
        }
       p++;
     }
}
else if(m==1)
{
    for(i=1;i<=n;i++)
     {
       if(a[i]-a[i-1]==1)
        {
          ans+=(long long)(n-i+1);
        }
       else
        {
          tt=a[i]+1;
          pt=lower_bound(a,a+n,tt);
          t=pt-a;
          if(a[t]==tt)
           {
             ans+=(long long)(n-t+1);
           }
        }
     }
 

}
   printf("Case #%d: %I64d",ii,ans);
   if(ii<=T-1)printf("\n");
}
    
    scanf(" ");
    return 0;
}
