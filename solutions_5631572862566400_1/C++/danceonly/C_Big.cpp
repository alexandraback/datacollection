#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1005;

int f[N];
int n;
vector<int> G[N], rG[N];
int dp[N];
int vis[N];
int deg[N];

void add_edge(int u, int v) {
    G[u].push_back(v);
}

void dfs1(int u) {
    dp[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        dfs1(v);
        dp[u] = max(dp[v] + 1, dp[u]);
    }
    vis[u] = 1;
    return ;
}

int cnt;

void dfs(int u) {
    ++ cnt;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!vis[v]) {
            dfs(v);
        }
    }
    return ;
}

void work(int cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n; i++) {
        if (i != f[f[i]]) {
            add_edge(f[i], i);
        }
    }
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == f[f[i]] && i < f[i]) {
            dfs1(i);
            dfs1(f[i]);
            ans += dp[i] + dp[f[i]];
        }
    }
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; i++) rG[i].clear();
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        for (int j = 0; j < G[i].size(); j++) {
            int v = G[i][j];
            rG[v].push_back(i);
            deg[i] ++;
        }
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (deg[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int u = que.front(); que.pop();
        vis[u] = 1;
        for (int i = 0; i < rG[u].size(); i++) {
            int v = rG[u][i];
            if (-- deg[v] == 0) {
                que.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        cnt = 0;
        dfs(i);
        ans = max(ans, cnt);
    }
    printf("Case #%d: %d\n", cas, ans);
    return ;
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        work(cas);
    }
    return 0;
}
