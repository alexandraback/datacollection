#include <iostream>
#include<string.h>
#include <vector>
using namespace std;
__int64 dp[105][105];
__int64 s1[105][105],s2[105][105];
struct node
{
    __int64 t,v;
} a[105],b[105];
__int64 llmax(__int64 a,__int64 b)
{
    return a>b?a:b;
}
__int64 minn(__int64 a,__int64 b)
{
    return a<b?a:b;
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C.out","w",stdout);
    int i,j,k,t,n,m,co=1,x,y;
    scanf("%d",&t);
    while(t--)
    {
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        scanf("%d%d",&n,&m);
        for (i=0; i<n; i++)
        {
            scanf("%I64d%I64d",&a[i].v,&a[i].t);
            s1[a[i].t][i+1]=a[i].v;
        }
        for (i=0; i<n; i++)
            for (k=0; k<=100; k++)
                s1[k][i+1]+=s1[k][i];
        for (i=0; i<m; i++)
        {
            scanf("%I64d%I64d",&b[i].v,&b[i].t);
            s2[b[i].t][i+1]=b[i].v;
        }
        for (i=0; i<m; i++)
            for (k=0; k<=100; k++)
                s2[k][i+1]+=s2[k][i];
        memset(dp,0,sizeof(dp));

        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
            {
                if (a[i-1].t!=b[j-1].t)
                {
                    dp[i][j]=llmax(dp[i-1][j],dp[i][j-1]);
                }
                else
                {
                    for (x=0; x<i; x++)
                        for (y=0; y<j; y++)
                            dp[i][j]=llmax(dp[i][j],dp[x][y]+minn(s1[a[i-1].t][i]-s1[a[i-1].t][x],s2[b[j-1].t][j]-s2[b[j-1].t][y]));
                }
            }

        __int64 ans=0;
        for (i=0; i<=n; i++)
            for (j=0; j<=m; j++)
                ans=llmax(ans,dp[i][j]);
        printf("Case #%d: %I64d\n",co++,ans);
    }
    system("pause");
    return 0;
}
