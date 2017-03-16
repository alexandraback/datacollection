#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define maxn 150
#define maxp 100
#define bigint long long
#define maxx(a,b) (a)>(b)?(a):(b)
#define minn(a,b) (a)>(b)?(b):(a)
using namespace std;

bigint dp[maxn][maxn];
bigint number1[maxn][maxn],number2[maxn][maxn];

struct node
{
    bigint t;
    bigint v;
} node1[maxn],node2[maxn];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);

    int cas,icas,i,j,k,n,m,x,y;
    scanf("%d",&cas);
    for(icas=1; icas<=cas; ++icas)
    {
        memset(number1,0,sizeof(int)*maxn);
        memset(number2,0,sizeof(int)*maxn);
        scanf("%d%d",&n,&m);
        for (i=0; i<n; i++)
        {
            scanf("%lld%lld",&node1[i].v,&node1[i].t);
            number1[node1[i].t][i+1]=node1[i].v;
        }
        for (i=0; i<n; i++)
        {
            for (k=0; k<=maxp; k++)
            {
                number1[k][i+1]+=number1[k][i];
            }
        }
        for (i=0; i<m; i++)
        {
            scanf("%lld%lld",&node2[i].v,&node2[i].t);
            number2[node2[i].t][i+1]=node2[i].v;
        }
        for (i=0; i<m; i++)
        {
            for (k=0; k<=maxp; k++)
            {
                number2[k][i+1]+=number2[k][i];
            }
        }

        memset(dp,0,sizeof(dp));

        for (i=1; i<=n; i++)
        {
            for (j=1; j<=m; j++)
            {
                if (node1[i-1].t!=node2[j-1].t)
                {
                    dp[i][j]=maxx(dp[i-1][j],dp[i][j-1]);
                }
                else
                {
                    for (x=0; x<i; x++)
                    {
                        for (y=0; y<j; y++)
                        {
                            dp[i][j]=maxx(dp[i][j],dp[x][y]+minn(number1[node1[i-1].t][i]-number1[node1[i-1].t][x],number2[node2[j-1].t][j]-number2[node2[j-1].t][y]));
                        }
                    }
                }
            }
        }

        bigint ans=0;
        for (i=0; i<=n; i++)
        {
            for (j=0; j<=m; j++)
            {
                ans=maxx(ans,dp[i][j]);
            }
        }
        printf("Case #%d: %lld\n",icas,ans);
    }
    return 0;
}
