#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int vals[55];
int n,m;
vector <int> E[55];
int best[55];
int cur[55];
int mark[55];
int gore[55];

inline int dfs(int dep,int better,int u,int reb)
{
    if (reb==0)
    {
        mark[u]=1;
        cur[dep]=vals[u];
        if (better==0 && cur[dep]>best[dep])
        {
            mark[u]=0;
            return 0;
        }
        if (better==0 && cur[dep]<best[dep])
            better=1;
        if (dep==n && better)
        {
            for (int i=1; i<=n; i++)
                best[i]=cur[i];
            mark[u]=0;
            return 1;
        }
    }
    int naso=0;
    for (int i=0; i<E[u].size(); i++)
    {
        if (mark[E[u][i]]==0)
        {
            gore[E[u][i]]=u;
            naso|=dfs(dep+1,better,E[u][i],0);
            if (naso)
                better=0;
        }
        if (E[u][i]==gore[u])
        {
            naso|=dfs(dep,better,gore[u],1);
            if (naso)
                better=0;
        }
    }
    if (reb==0)
        mark[u]=0;
    return naso;
}

int main()
{
    freopen("D:/in.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int itr=1; itr<=tc; itr++)
    {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++)
            scanf("%d",&vals[i]);
        for (int i=1; i<=n; i++)
            E[i].clear();
        for (int i=1; i<=n; i++)
            gore[i]=0;
        for (int i=1; i<=m; i++)
        {
            int p,k;
            scanf("%d%d",&p,&k);
            E[p].push_back(k);
            E[k].push_back(p);
        }
        int mn=1<<20;
        int pl;
        for (int i=1; i<=n; i++)
            if (vals[i]<mn)
            {
                mn=vals[i];
                pl=i;
            }
        best[1]=1<<20;
        dfs(1,0,pl,0);
        printf("Case #%d: ",itr);
        for (int i=1; i<=n; i++)
            printf("%d",best[i]);
        printf("\n");
    }

}
