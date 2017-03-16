#include <bits/stdc++.h>
using namespace std;

const int D = 105;
const int V = 35;
int T, c, d, v;

bool check(int mask) {
    bool f[V] = {};
    f[0] = true;
    for (int i = 1; i <= v; ++i) {
        if (mask & 1 << i) {
            for (int j = v - i; j >= 0; --j) {
                if (f[j]) f[j + i] = true;
            }
        }
    }
    for (int i = 1; i <= v; ++i) {
        if (!f[i]) return false;
    }
    return true;
}
bool dfs(int mask, int dep) {
    if (!dep) return check(mask);
    for (int i = 1; i <= v; ++i) {
        if (mask & 1 << i) continue;
        if (dfs(mask | 1 << i, dep - 1)) return true;
    }
    return false;
}
int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d%d%d", &c, &d, &v);
        int mask = 0;
        for (int a, i = 0; i < d; ++i) {
            scanf("%d", &a);
            mask |= 1 << a;
        }
        int ans;
        for (ans = 0; ans < 5; ++ans) {
            if (dfs(mask, ans)) break;
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
