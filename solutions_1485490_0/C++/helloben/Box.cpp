#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

long long ans,f[110][110];
struct dat
{
    long long num,type;
}line[2][110];
int n,m;

void update(int p1,int p2,int key)
{
    int i,j,t1,t2;
    long long sum1,sum2,tmp,s;
    t1=p2;sum2=0;sum1=0;
    for (i = p1;i<=n;i++)
    if (line[0][i].type==key)
    {
        sum1+=line[0][i].num;
        /*t2=m;s=sum2;
        if (sum2<sum1)
        {
            for (j = t1;j<=m;j++)
            if (line[1][j].type==key)
            {
                if (sum2+line[1][j].num>sum1) { t2=j;break; }
                sum2+=line[1][j].num;
            }
        }
        for (j = t1;j<=t2;j++)
        if (line[1][j].type==key)
        {
            s+=line[1][j].num;
            tmp=f[p1][p2]+min(s,sum1);
            if (tmp>f[i+1][j+1])
            {
                f[i+1][j+1]=tmp;
                if (tmp>ans) ans=tmp;
            }
        }
        t1=t2;*/
        //*********************
        s=0;
        for (j = p2;j<=m;j++)
        if (line[1][j].type==key)
        {
            s+=line[1][j].num;
            tmp=f[p1][p2]+min(s,sum1);
            if (tmp>f[i+1][j+1])
            {
                f[i+1][j+1]=tmp;
                if (tmp>ans) ans=tmp;
            }
        }
    }
}

void solve()
{
    int i,j,k;
    for (i = 1;i<=n+2;i++)
        for (j = 1;j<=m+2;j++) f[i][j]=-1;
    ans=0;
    f[1][1]=0;
    for (i = 1;i<=n;i++)
        for (j = 1;j<=m;j++)
        if (f[i][j]>=0)
        {
            for (k = i;k<=n;k++) update(i,j,line[0][k].type);
        }
}

int main()
{
    freopen("Box.in","r",stdin);
    freopen("Box.out","w",stdout);
    int t,tt,i;
    scanf("%d",&tt);
    for (t = 1;t<=tt;t++)
    {
        scanf("%d%d",&n,&m);
        for (i = 1;i<=n;i++) scanf("%I64d%I64d",&line[0][i].num,&line[0][i].type);
        for (i = 1;i<=m;i++) scanf("%I64d%I64d",&line[1][i].num,&line[1][i].type);
        solve();
        printf("Case #%d: %I64d\n",t,ans);
    }
}
