#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 1007;

bool in[N];
bool depth[N];
bool vis[N];
int fa[N];
int res[N];
int bff[N];
vector<int> rbff[N];
bool visLen[N];
int len[N];

int dfs(int v, int d) {
    if (vis[v]) {
        return 0;
    }

    vis[v] = true;
    depth[v] = d;

    int t = bff[v];
    if (vis[t]) {
        if (in[t]) {
            return d - depth[t] + 1;
        }
    }

    in[v] = true;
    int r = dfs(t, d + 1);
    in[v] = false;
    return r;
}

int dfsLen(int v, int exc) {
    if (visLen[v]) {
        return len[v];
    }

    visLen[v] = true;
    int r = 0;
    for (int i = 0; i < rbff[v].size(); ++i) {
        int to = rbff[v][i];
        if (to == exc) {
            continue;
        }
        int tmp = dfsLen(to, v);
        r = max(r, tmp);
    }
    len[v] = r + 1;

    return len[v];
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        for (int j = 1; j <= n; ++j) {
            rbff[j].clear();
        }
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &bff[j]);
            rbff[bff[j]].push_back(j);
        }

        memset(in, 0, sizeof(in));
        memset(depth, 0, sizeof(depth));
        memset(vis, 0, sizeof(vis));

        for (int j = 1; j <= n; ++j) {
            int t = bff[j];
            fa[j] = 0;
            if (bff[t] == j) {
                fa[j] = min(t, j);
            }
        }

        int ans = 0;
        for (int j = 1; j <= n; ++j) {
            if (fa[j] != 0) {
                memset(visLen, 0, sizeof(visLen));
                int t = bff[j];
                dfsLen(j, t);
                dfsLen(t, j);
                //cout << j << ' ' << len[j] << ' ' << t << ' ' << len[t] << endl;
                ans = max(ans, len[j] + len[t]);
            }
        }

        for (int j = 1; j <= n; ++j) {
            int a = dfs(j, 0);
            ans = max(ans, a);
        }
        printf("Case #%d: %d", i + 1, ans);
        if (i + 1 < T) {
            printf("\n");
        }
    }
    return 0;
}
