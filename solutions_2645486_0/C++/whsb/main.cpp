#include <iostream>
#include <cstdio>
#include <map>
#include <math.h>
#include <string.h>
using namespace std;

int dp[20][10],N,E,R,v[20];

int cal(int x)
{
    if(x>E) return E;
    return x;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d",&E,&R,&N);
        for(int i=0;i<N;i++) scanf("%d",&v[i]);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            for(int j=1;j<=E;j++)
            {
                for(int k=0;k<=j;k++)
                {
                    dp[i+1][cal(j-k+R)]=max(dp[i+1][cal(j-k+R)],dp[i][j]+k*v[i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=N;i++)
        for(int j=0;j<=E;j++)
        ans=max(ans,dp[i][j]);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
