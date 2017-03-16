#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 105;

int vis[N];
int f[N];
int n;

int dfs(int s, int now, int fp) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (!fp && f[now] != i) continue;
        if (i == s) {
            ret = max(1, ret);
        }else {
            vis[i] = 1;
            int tmp = dfs(s, i, f[i] == now);
            if (tmp > 0) {
                ret = max(ret, tmp + 1);
            }
            vis[i] = 0;
        }
    }
    return ret;
}

void work(int cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i, i, 0));
    }
    printf("Case #%d: %d\n", cas, ans);
    return ;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        work(cas);
    }
    return 0;
}
