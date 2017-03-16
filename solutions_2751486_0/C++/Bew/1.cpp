#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
char c[1000111];
int T;
int n,m;
int f(int p,int q)
{
  int i,j,k;
  int t,tt,ttt;
  int xx;
  xx=-1;
  k=0;
  for(i=p;i<=q;i++)
   {
     t=0;
     if(c[i]=='a')t=1;
     if(c[i]=='e')t=1;
     if(c[i]=='i')t=1;
     if(c[i]=='o')t=1;
     if(c[i]=='u')t=1;
     if(t==1)
      {
        if(k>xx)xx=k;
        k=0;
      }
     else k++;
   }
  if(k>xx)xx=k;
  return xx;
}
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("A-small-attempt0 (1).out","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    int ans;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%s",c);
    n=strlen(c);
    scanf("%d",&m);
    ans=0;
    for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
        {
          if(i<=j)
           {
             k=f(i,j);
           //  printf("%d %d   %d\n",i,j,k);
             if(k>=m)
              {
                //printf("%d %d   %d\n",i,j,k);
                ans++;
              }
           }
        }
     }
   printf("Case #%d: %d",ii,ans);
   if(ii<=T-1)printf("\n");
}
    
    scanf(" ");
    return 0;
}
