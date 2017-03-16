#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int MAXN = 1010;

int n, to[MAXN];
vector<int> back[MAXN];
int ans;
bool visited[MAXN];
int sz[MAXN];
int lead[MAXN];

int dfs(int u) {
    int q = to[u];
    int tot = 0;
    while (q != u && !visited[q]) {
        visited[q] = 1;
        tot++;
        q = to[q];
    }
    if (q != u) return 0;
    return tot + 1;
}

int dfs2(int v) {
    int ret = 1;
    for (auto u: back[v]) {
        if (sz[u] == 0) ret = max(ret, 1 + dfs2(u));
    }
    return ret;
}

int main(void) {
    if (fopen("c-small.in", "r")) {
        freopen("c-small.in", "r", stdin);
        freopen("c-small.out", "w", stdout);
    }
    if (fopen("c-large.in", "r")) {
        freopen("c-large.in", "r", stdin);
        freopen("c-large.out", "w", stdout);
    }
    int t;
    cin >> t;
    for (int ii = 1; ii <= t; ii++) {
        ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            back[i].clear();
            sz[i] = 0;
            lead[i] = 0;
            to[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> to[i];
            to[i]--;
            back[to[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            memset(visited, 0, sizeof(visited));
            sz[i] = dfs(i);
            ans = max(ans, sz[i]);
        }
        for (int i = 0; i < n; i++) lead[i] = dfs2(i) - 1;
        vector<pii> v;
        int ex = 0;
        for (int i = 0; i < n; i++) {
            if (i < to[i] && sz[i] == 2) {
                v.push_back(pii(i, to[i]));
                ex += lead[i] + lead[to[i]];
            }
        }
        ans = max(ans, 2 * (int)v.size() + ex);
        printf("Case #%d: %d\n", ii, ans);
    }
    return 0;
}
