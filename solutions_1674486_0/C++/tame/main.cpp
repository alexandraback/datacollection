#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[10000],u[100000],v[100000],next[100000],tote;
int vis[10000];
int dfs(int u)
{
    if(vis[u]) return 1;
    vis[u]=1;
    int ee=f[u];
    while(ee!=-1)
    {
        if(dfs(v[ee])) return 1;
        ee=next[ee];
    }
    return 0;
}


int main()
{
    freopen("4.in","r",stdin);
    freopen("4.out","w",stdout);
    int cas,g;
    scanf("%d",&cas);
    for(g=1;g<=cas;g++)
    {
        int n;
        scanf("%d",&n);
        memset(f,-1,sizeof(f));
        tote=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            for(int j=1;j<=a;j++)
            {
                scanf("%d",&v[++tote]);
                next[tote]=f[i];
                f[i]=tote;
            }
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("Case #%d: Yes\n",g);
        else
            printf("Case #%d: No\n",g);
    }
    return 0;
}