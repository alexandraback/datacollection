#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int a, b, K, ans = 0;
        scanf("%d%d%d", &a, &b, &K);
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if ((i & j) < K) ans++;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
