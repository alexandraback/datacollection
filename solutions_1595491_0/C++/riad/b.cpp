#include <stdio.h>
#include <string.h>

int sp[33],nm[33],t[103],dp[103][103];

int main()
{
    freopen("b.txt","r",stdin);
    freopen("b.out","w",stdout);
    int i,j,k,cas,test,n,s,p;
    for (i=0;i<=30;i++) sp[i]=nm[i]=-1;
    for (i=0;i<=10;i++)
    {
        for (j=i;j<=10&&j<=i+2;j++)
        {
            for (k=j;k<=10&&k<=i+2;k++)
            {
                if (k==i+2&&k>sp[i+j+k]) sp[i+j+k]=k;
                if (k<i+2&&k>nm[i+j+k]) nm[i+j+k]=k;
            }
        }
    }
    scanf("%d",&test);
    for (cas=1;cas<=test;cas++)
    {
        scanf("%d%d%d",&n,&s,&p);
        for (i=1;i<=n;i++) scanf("%d",&t[i]);
        memset(dp,0,sizeof(dp));
        for (i=1;i<=n;i++)
        {
            for (j=0;j<=s;j++)
            {
                if (j-1>=0&&sp[t[i]]>-1)
                {
                    if (sp[t[i]]>=p&&dp[i-1][j-1]+1>dp[i][j]) dp[i][j]=dp[i-1][j-1]+1;
                    if (sp[t[i]]<p&&dp[i-1][j-1]>dp[i][j]) dp[i][j]=dp[i-1][j-1];
                }
                if (nm[t[i]]>=p&&dp[i-1][j]+1>dp[i][j]) dp[i][j]=dp[i-1][j]+1;
                if (nm[t[i]]<p&&dp[i-1][j]>dp[i][j]) dp[i][j]=dp[i-1][j];
            }
        }
        printf("Case #%d: %d\n",cas,dp[n][s]);
    }
    return 0;
}

