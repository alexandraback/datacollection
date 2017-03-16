#include <bits/stdc++.h>
using namespace std;

int use[3000];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        memset(use, 0, sizeof(use));
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                scanf("%d", &x);
                use[x]++;
            }
        }
        printf("Case #%d:", cas);
        for (int i = 1; i <= 2500; i++) {
            use[i] %= 2;
            if (use[i]) {
                printf(" %d", i);
            }
        }
        puts("");
    }
    return 0;
}