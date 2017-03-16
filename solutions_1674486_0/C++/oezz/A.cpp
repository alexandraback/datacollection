#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=1010;
const int MAXM=1010*1010;

struct edge{
    int to, next;
} e[MAXM];

int n;
int vert[MAXN], deg[MAXN];
bool g[MAXN][MAXN], mk[MAXN];

void addedge(int u, int v, int &top)
{
    e[++top].to=v, e[top].next=vert[u], vert[u]=top;
}

bool dfs(int u)
{
    mk[u]=1;
    bool ok=0;
    for (int i=vert[u]; i!=-1&&!ok; i=e[i].next)
    {
        int v=e[i].to;
        if (mk[v]) ok=1;
        else ok=dfs(v);
    }
    return ok;
}

bool solve()
{
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            g[i][j]=0;
    for (int i=1; i<=n; ++i) vert[i]=-1, deg[i]=0;
    int top=-1;
    for (int i=1; i<=n; ++i)
    {
        int x;
        scanf("%d", &x);
        for (int j=0; j<x; ++j)
        {
            int u;
            scanf("%d", &u);
            if (!g[i][u]) addedge(i, u, top);
            ++deg[u];
        }
    }

    for (int i=1; i<=n; ++i)
    {
        memset(mk, 0, sizeof(mk));
        if (!deg[i] && dfs(i)) return 1;
    }
    return 0;
}

int main()
{
    int T;
//	freopen("A.in","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    scanf("%d", &T);
    for (int i=1; i<=T; ++i) printf("Case #%d: %s\n", i, solve()?"Yes":"No");
    return 0;
}
