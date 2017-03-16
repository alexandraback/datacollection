#include <bits/stdc++.h>
using namespace std;

int C, D, V;
int d[35];
bool visit[35];

int maxDepth;

bool dp[40];

bool dfs(int depth) {
    if (depth == maxDepth) {
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 0; i < depth; ++i) {
            for (int j = V; j >= d[i]; --j) {
                if (dp[j - d[i]]) {
                    dp[j] = true;
                }
            }
        }
        for (int j = 1; j <= V; ++j) {
            if (not dp[j]) {
                return false;
            }
        }
        return true;
    }
    for (int i = 1; i <= V; ++i) {
        if (not visit[i]) {
            visit[i] = true;
            d[depth] = i;
            if (dfs(depth + 1)) {
                return true;
            }
            visit[i] = false;
        }
    }
    return false;
}

int main() {
    int T;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &C, &D, &V);
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < D; ++i) {
            scanf("%d", &d[i]);
            visit[d[i]] = true;
        }
        int ans = 0;
        for (int i = D; ; ++i) {
            maxDepth = i;
            if (dfs(D)) {
                ans = i - D;
                break;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
