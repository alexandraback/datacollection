#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int v[100005];
int dp[105][10];
int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

    int cas,t=1,e,r,n;

    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(int i=1;i<=n;i++)
           scanf("%d",&v[i]);
        memset(dp,-1,sizeof(dp));
        dp[0][e]=0;
        for(int i=1;i<=n;i++)
           for(int j=0;j<=e;j++)
           {
               if(dp[i-1][j]==-1)
                  continue;
               for(int k=0;k<=j;k++)
               {
                   int tmp=min(e,j-k+r);
                   dp[i][tmp]=max(dp[i][tmp],dp[i-1][j]+k*v[i]);
               }
           }
        int ans=0;
        for(int i=0;i<=e;i++)
           if(dp[n][i]>ans)
              ans=dp[n][i];
        printf("Case #%d: %d\n",t++,ans);
    }
    return 0;
}
