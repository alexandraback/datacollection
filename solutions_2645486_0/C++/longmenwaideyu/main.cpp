#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#define N 15
#define INF 0x6f6f6f6f
#define debug(a) cout<<#a<<' '<<a<<endl;
typedef long long LL;
using namespace std;
int dp[N][N];
int v[N];
int e,r,n;
int main()
{
#ifndef ONLINE_JUDGE
  //  freopen("/home/longmenwaideyu/下载/3.in","r",stdin);
   // freopen("out.txt","w",stdout);
#endif

    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&e,&r,&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&v[i]);
        }
        for(int i=0; i<=n; i++)
            for(int j=0; j<=e; j++)
                dp[i][j]=-INF;
        if(r>e)r=e;
        dp[0][e]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=e; j++)
            {
                for(int k=0; j+k<=e; k++)
                {
                    dp[i][j]=max(dp[i-1][j+k]+v[i]*k,dp[i][j]);
                }
                //if(i==1 && j==0)cout<<dp[i][j]<<endl;


            }
            for(int k=0; k<=r; k++)
                dp[i][e]=max(dp[i][e],dp[i][e-k]);
            for(int k=e-1; k>=0; k--)
            {
                if(k-r>=0)
                    dp[i][k]=dp[i][k-r];
                else dp[i][k]=-INF;
                //if(i==1 && k==2)cout<<dp[i][k]<<endl;
            }
        }

       // cout<<dp[1][2]<<endl;
        int ans=-INF;
        for(int i=0; i<=e; i++)
            ans=max(dp[n][i],ans);
        printf("Case #%d: %d\n",cas++,ans);
    }

    return 0;
}
