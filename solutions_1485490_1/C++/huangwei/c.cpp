#include <iostream>
#include <vector>
using namespace std;
long long dp[105][105];
__int64 suma[105][105],sumb[105][105];

struct node
{
    __int64 t,v;
} s1[105],s2[105];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("c.out","w",stdout);
    int i,j,k,t,n,m,x,y,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(suma,0,sizeof(suma));
        memset(sumb,0,sizeof(sumb));
        scanf("%d %d",&n,&m);
        for (i=0; i<n; i++)
        {
            scanf("%I64d %I64d",&s1[i].v,&s1[i].t);
            suma[s1[i].t][i+1]=s1[i].v;
        }
        for (i=0; i<n; i++)
            for (k=0; k<=100; k++)
                suma[k][i+1]+=suma[k][i];
        for (i=0; i<m; i++)
        {
            scanf("%I64d %I64d",&s2[i].v,&s2[i].t);
            sumb[s2[i].t][i+1]=s2[i].v;
        }
        for (i=0; i<m; i++)
            for (k=0; k<=100; k++)
                sumb[k][i+1]+=sumb[k][i];
        memset(dp,0,sizeof(dp));

        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
            {
                if (s1[i-1].t!=s2[j-1].t)
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                else
                {
                    for (x=0; x<i; x++)
                        for (y=0; y<j; y++)
                            dp[i][j]=max(dp[i][j],dp[x][y]+min(suma[s1[i-1].t][i]-suma[s1[i-1].t][x],sumb[s2[j-1].t][j]-sumb[s2[j-1].t][y]));
                }
            }

        __int64 ans=0;
        for (i=0; i<=n; i++)
            for (j=0; j<=m; j++)
                ans=max(ans,dp[i][j]);
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    return 0;
}
