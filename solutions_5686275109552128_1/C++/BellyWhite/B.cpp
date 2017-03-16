#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n, a[1005];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", a+i);
        int m = *max_element(a, a+n);
        int ans = m;
        for (int t = 1; t <= m; t++) {
            int move = 0;
            for (int i = 0; i < n; ++i) {
                move += (a[i] + t - 1) / t - 1;
            }
            ans = min(ans, move + t);
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
