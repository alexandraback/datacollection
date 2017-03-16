#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int v[0x10], r, e, n, ret;

void dfs(int cur, int rest, int tot) {
    if (cur == n) {
        ret = max(ret, tot);
        return;
    }

    for (int i = 0; i <= rest; ++i) {
        dfs(cur + 1, min(rest - i + r, e), tot + i * v[cur]);
    }
}

int main() {
    int t;

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d%d%d", &e, &r, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
        }
        ret = 0;
        dfs(0, e, 0);
        printf("Case #%d: %d\n", cas, ret);
    }

    return 0;
}
