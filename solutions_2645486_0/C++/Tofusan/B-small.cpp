#include <stdio.h>
#include <stdlib.h>

int t,e,r,n;
int A[101];
int dp[101][101];
int ans;
main()
{
 freopen("B-small-attempt0.in","r",stdin);
 freopen("B-small.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
   scanf("%d%d%d",&e,&r,&n);
   for(int i=1;i<=n;i++)
   {
    scanf("%d",&A[i]);
   }
   for(int i=0;i<=e;i++)
   {
    dp[0][i]=(-1);
    dp[1][i]=(-1);
   }
   dp[0][e]=0;
   for(int i=1;i<=n;i++)
   {
    for(int j=0;j<=e;j++)
    {
     dp[i][j]=(-1);
    }
    for(int j=e;j>=0;j--)
    {
     if(dp[i-1][j]!=(-1))
     {
      for(int k=j;k>=0;k--)
      {
       if(dp[i-1][j]+(k*A[i])>dp[i][j-k]){dp[i][j-k]=dp[i-1][j]+(k*A[i]);}
      }
     }
    }
    for(int j=e-1;j>=e-r&&j>=0;j--)
    {
     if(dp[i][j]>dp[i][e]){dp[i][e]=dp[i][j];}
    }
    for(int j=e-1;j>=0;j--)
    {
     if(j-r>=0){dp[i][j]=dp[i][j-r];}
     else{dp[i][j]=(-1);}
    }
   }
   ans=(-1);
   for(int i=0;i<=e;i++)
   {
    if(dp[n][i]>ans){ans=dp[n][i];}
   }
   printf("Case #%d: %d\n",tests,ans);
 }

 return 0;
}
