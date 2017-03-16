#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n,c[30],ans[30],a[210];
bool vis[1050000];
vector <int> b[30];
bool dfs(int dep,int state)
{
    if (vis[state])
        return(false);
    vis[state]=true;
    if (state==0)
    {
        for (int i=1;i<=n;i++)
            printf(" %d",ans[i]);
        printf("\n");
        return(true);
    }
    for (int i=1;i<=n;i++)
    {
        if (!(state>>i-1&1) || a[c[i]]==0)
            continue;
        a[c[i]]--;
        for (int j=0;j<b[i].size();j++)
            a[b[i][j]]++;
        ans[dep]=i;
        if (dfs(dep+1,state^1<<i-1))
            return(true);
        a[c[i]]++;
        for (int j=0;j<b[i].size();j++)
            a[b[i][j]]--;
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int K;
        scanf("%d%d",&K,&n);
        memset(a,0,sizeof(a));
        for (int i=1;i<=K;i++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d%d",&c[i],&x);
            b[i].resize(x);
            for (int j=0;j<x;j++)
                scanf("%d",&b[i][j]);
        }
        static int id=0;
        printf("Case #%d:",++id);
        memset(vis,0,sizeof(vis));
        if (!dfs(1,(1<<n)-1))
            printf(" IMPOSSIBLE\n");
    }
    return(0);
}

