#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int t, r, n, m, k, pod[0x10], must[0x10], tot[0x10];

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d%d%d%d", &r, &n, &m, &k);
        printf("Case #%d:\n", cas);
        while (r--) {
            memset(tot, 0, sizeof(tot));
            for (int i = 0; i < k; ++i) {
                scanf("%d", &pod[i]);
                memset(must, 0, sizeof(must));
                int tmp = pod[i];
                for (; tmp > 1 && (tmp % 4 == 0); tmp /= 4) must[4]++;
                for (; tmp > 1 && (tmp % 2 == 0); tmp /= 2) must[2]++;
                for (; tmp > 1 && (tmp % 3 == 0); tmp /= 3) must[3]++;
                for (; tmp > 1 && (tmp % 5 == 0); tmp /= 5) must[5]++;
                for (int c = 2; c <= 5; ++c) tot[c] = max(tot[c], must[c]);
            }
            int cnt = 0;
            for (int i = 2; i <= 5; ++i) cnt += tot[i];
            tot[2] += n - cnt;
            for (int i = 2; i <= 5; ++i) {
                for (int j = 0; j < tot[i]; ++j) printf("%d", i);
            }
            printf("\n");
        }
    }

    return 0;
}
