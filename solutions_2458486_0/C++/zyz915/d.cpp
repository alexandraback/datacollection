#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 22;
int T, C;
int tt[N][N + N], t[N], open[N], ans[N];
bool vis[N], cc[1 << N];

bool dfs(int k, int n, int code, vector<int> v) {
    if (k == n) return true;
    if (cc[code]) return false;
    cc[code] = true;
    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            int hasKey = -1;
            for (int j = 0; j < (int)v.size(); j++)
                if (v[j] == open[i])
                    hasKey = j;
            if (hasKey == -1)
                continue;
            vis[i] = true;
            v[hasKey] = -1;
            vector<int> u = v;
            u.insert(u.end(), tt[i], tt[i] + t[i]);
            ans[k] = i + 1;
            if (dfs(k + 1, n, code ^ (1 << i), u))
                return true;
            v[hasKey] = open[i];
            vis[i] = false;
        }
    return false;
}

void run() {
    int k, n, x;
    vector<int> start;
    scanf("%d%d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        start.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &open[i], &t[i]);
        for (int j = 0; j < t[i]; j++)
            scanf("%d", &tt[i][j]);
    }
    memset(vis, 0, sizeof(vis));
    memset(cc, 0, sizeof(cc));
    if (dfs(0, n, 0, start)) {
        printf("Case #%d:", C);
        for (int r = 0; r < n; r++)
            printf(" %d", ans[r]);
        printf("\n");
    } else
        printf("Case #%d: IMPOSSIBLE\n", C);
}

int main() {
    scanf("%d", &T);
    for (C = 1; C <= T; C++)
        run();
    return 0;
}
