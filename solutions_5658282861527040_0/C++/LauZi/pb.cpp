#include <cstdio>

int jizz() {
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);

    int ans = 0;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if ((i & j) < k) ans += 1;
        }
    }
    return ans;
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %d\n", t, jizz());
    }
    return 0;
}
