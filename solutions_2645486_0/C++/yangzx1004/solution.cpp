#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    int t,e,r,n,v[12],cnt,i,j,k;
    int dp[12][6];
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&t);
    for(cnt=1;cnt<=t;cnt++)
    {
        scanf("%d %d %d",&e,&r,&n);
        for(i=0;i<n;i++)
            scanf("%d",&v[i]);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            for(j=r;j<=e;j++)
            {
                for(k=0;k<=j;k++)
                    dp[i+1][min(e,j-k+r)]=max(dp[i+1][min(e,j-k+r)],dp[i][j]+v[i]*k);
            }
        }
        for(j=r+1,k=r;j<=e;j++)
            if(dp[n][j]>dp[n][k])
                k=j;
        printf("Case #%d: %d\n",cnt,dp[n][k]);
    }
}
