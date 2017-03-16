#include <cstdio>
#include <string.h>

using namespace std;

bool g[1010][1010];
int f[1010],n,que[1010];

bool judge(int root)
{
    int head,tail,i;
    memset(f,0,sizeof(f));
    tail=1;que[1]=root;head=0;
    while (head<tail)
    {
        head++;
        for (i = 1;i<=n;i++)
        if (g[que[head]][i])
        {
            f[i]++;
            if (f[i]==2) return true;
            que[++tail]=i;
        }
    }
    return false;
}

int main()
{
    freopen("Diamond.in","r",stdin);
    freopen("Diamond.out","w",stdout);
    int t,tt,i,j,p,m;
    bool ok;
    scanf("%d",&tt);
    for (t = 1;t<=tt;t++)
    {
        scanf("%d",&n);
        memset(g,false,sizeof(g));
        for (i = 1;i<=n;i++)
        {
            scanf("%d",&m);
            for (j = 1;j<=m;j++)
            {
                scanf("%d",&p);
                g[i][p]=true;
            }
        }
        ok=false;
        for (i = 1;i<=n;i++)
        if (judge(i))
        {
            ok=true;
            break;
        }
        printf("Case #%d: ",t);
        if (ok) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}
