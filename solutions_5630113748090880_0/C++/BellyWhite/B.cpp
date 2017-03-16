#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        bool cnt[2505] = {};
        scanf("%d", &n);
        for (int x, i = 0; i < 2 * n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &x);
                cnt[x] = !cnt[x];
            }
        }
        printf("Case #%d:", cas);
        for (int i = 1; i <= 2500; ++i) {
            if (cnt[i]) printf(" %d", i);
        }
        puts("");
    }
}
