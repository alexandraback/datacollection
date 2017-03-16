#include <bits/stdc++.h>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

typedef pair<int,int> pii;
typedef map<int,int> bstii;
typedef set<int> bsti;

const int MAXN = 1010;

int vis[MAXN], ke[MAXN];
int N;
vector <int> ke2[MAXN];

int resol(int u)
{
    int res = 0;
    while (1)
    {
        if (vis[u] == 2)
        {
            break;
        }
        res++;
        vis[u] = 2;
        u = ke[u];
    }
    return res;
}

int solve(int u)
{
    int j = u, res = 0;
    while (1)
    {
        if (vis[j] == 1)
        {
            res = resol(j);
            break;
        }
        if (vis[j] == 2)
        {
            break;
        }
        vis[j] = 1;
        j = ke[j];
    }
    while (1)
    {
        if (vis[u] == 2)
        {
            break;
        }
        vis[u] = 2;
        u = ke[u];
    }
    return res;
}

int cal()
{
    int res = 0;
    for(int i=1; i<=N; i++)
    {
        if (vis[i] == 0)
        {
            int t = solve(i);
            res = max(res, t);
        }
    }
    return res;
}

int dfs(int u)
{
    int res = 1;
    for(int j=0; j<ke2[u].size(); j++)
    {
        int v = ke2[u][j];
        if (vis[v] == 0)
        {
            vis[v] = 1;
            int t = dfs(v);
            res = max(res, t+1);
        }
    }
    return res;
}

int recal()
{
    for(int i=1; i<=N; i++)
    {
        ke2[i].clear();
    }
    for(int i=1; i<=N; i++)
    {
        ke2[ke[i]].pb(i);
    }
    int res = 0;
    for(int i=1; i<=N; i++)
    {
        if (ke[ke[i]] == i && vis[i] == 0)
        {
            int j = ke[i];
            vis[i] = 1;
            vis[j] = 1;
            int x1 = dfs(i);
            int x2 = dfs(j);
            res += (x1 + x2);
        }
    }
    return res;
}

int main() {
	freopen("C-large.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int k=1; k<=T; k++)
    {
        printf("Case #%d: ", k);
        scanf("%d", &N);
        for(int i=1; i<=N; i++)
        {
            scanf("%d", &ke[i]);
        }
        memset(vis, 0, sizeof(vis));
        int res = cal();
        memset(vis, 0, sizeof(vis));
        int t = recal();
        res = max(res, t);
        printf("%d\n", res);
    }
	return 0;
}
