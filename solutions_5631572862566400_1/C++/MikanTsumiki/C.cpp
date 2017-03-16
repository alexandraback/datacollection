#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n, nex[2000], vis[2000], checked[2000];
vector<int> G[2000];
int dfs(int u, int fa) {
    int w = 0;
    for (auto v : G[u])
        if (v != fa) w = max(w, dfs(v, u));
    return w + 1;
}
int main() {
    int cas;
    scanf("%d", &cas);
    for (int _ = 1; _ <= cas; _++) {
        printf("Case #%d:", _);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &nex[i]), G[i].clear();
        for (int i = 1; i <= n; i++) G[nex[i]].push_back(i);
        int ans = 0, cnt = 0;
        memset(checked, 0, sizeof checked);
        for (int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof vis);
            vis[i] = 1;
            int j = nex[i], last = i;
            while (!vis[j]) {
                vis[j] = vis[last] + 1;
                last = j;
                j = nex[j];
            }
            int len = vis[last] - vis[j] + 1;
            if (len > 2)
                ans = max(ans, len);
            else {
                if (checked[j] || checked[last]) continue;
                checked[j] = 1;
                checked[last] = 1;
                cnt += dfs(j, last);
                cnt += dfs(last, j);
            }
        }
        ans = max(ans, cnt);
        printf(" %d\n", ans);
    }
}
