#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[15][6];
int f[15];
int main()
{
    freopen("B0.in","r",stdin);
    freopen("B0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int mt=1;mt<=t;mt++)
    {
        int e,r,n;
        scanf("%d%d%d",&e,&r,&n);
        for(int i=0;i<n;i++) scanf("%d",f+i);
        //for(int i=0;i<e;i++) dp[0][e]=-1;
        memset(dp,0,sizeof(dp));
        dp[0][e]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=e;j++)
                for(int k=0;k<=j;k++)
                    dp[i+1][j-k+r]=max(dp[i+1][j-k+r],dp[i][j]+k*f[i]);
        }
        int ans=dp[n][r];
        printf("Case #%d: %d\n",mt,ans);
    }
}
