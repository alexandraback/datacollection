#include<iostream>
#include<cstdio>
using namespace std;
int dp[20][10];
int a[20];
const int inf=10000000;
int main()
{
    int T;
    int e,r,n;
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=e;j++)
            dp[i][j]=-inf;
        dp[0][e]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=r;j<e;j++)
            {
                dp[i][j]=-inf;
                for(int k=max(j-r,min(r,e));k<=e;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+(k-(j-r))*a[i]);
                }
            }
            dp[i][e]=-inf;
            for(int j=max(e-r,0);j<=e;j++)
            {
                for(int k=max(j,min(e,r));k<=e;k++)
                    dp[i][e]=max(dp[i][e],dp[i-1][k]+(k-j)*a[i]);
            }
        }
        int ans=0;
        for(int i=0;i<=e;i++){
            if(dp[n][i]>ans)ans=dp[n][i];
            //cout<<dp[n][i]<<",";
        }
        printf("Case #%d: %d\n",cas,dp[n][min(r,e)]);
    }
    return 0;
}
