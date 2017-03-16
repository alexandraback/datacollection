#include <stdio.h>
#include <cstring>

int dp[20][20];
int e,n,r;
int v[100];

int main()
{
    freopen("B.in","r",stdin);
    freopen("B2.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        memset(dp,-1,sizeof(dp));
        dp[0][e]=0;
        
        for(int i=0;i<n;i++)
          for(int j=0;j<=e;j++)
             if(dp[i][j]>=0)
             {
                for(int u=j;u>=0;u--)
                {
                    int tu=j-u+r;
                    if(tu>=e) tu=e;
                    if(dp[i+1][tu]<dp[i][j]+u*v[i])
                       dp[i+1][tu]=dp[i][j]+u*v[i];
                }
             }
        
        int ans=-1;
        for(int j=0;j<=e;j++)
           if(dp[n][j]>ans) ans=dp[n][j];
             
        printf("Case #%d: %d\n",ca,ans);
    }
}
