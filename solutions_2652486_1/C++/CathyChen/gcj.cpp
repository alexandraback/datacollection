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
                int tmp = pod[i], cc = 0;
                for (; tmp > 1 && (tmp % 5 == 0); tmp /= 5) { cc++; must[5]++; }
                for (; tmp > 1 && (tmp % 7 == 0); tmp /= 7) { cc++; must[7]++; }
//                for (; tmp > 1 && (tmp % 8 == 0); tmp /= 8) must[8]++;
//                for (; tmp > 1 && (tmp % 6 == 0); tmp /= 6) must[6]++;
//                for (; tmp > 1 && (tmp % 4 == 0); tmp /= 4) must[4]++;
                for (; tmp > 1 && (tmp % 2 == 0); tmp /= 2) { cc++; must[2]++; }
                for (; tmp > 1 && (tmp % 3 == 0); tmp /= 3) { cc++; must[3]++; }
                while (cc > n && must[2] >= 3) { must[2] -= 3; must[8]++; cc -= 2; }
                while (cc > n && must[2] >= 1 && must[3] >= 1) { must[2]--; must[3]--; must[6]++; cc--; }
                while (cc > n && must[2] >= 2) { must[2] -= 2; must[4]++; cc--; }
                for (int c = 2; c <= 8; ++c) tot[c] = max(tot[c], must[c]);
            }
            int cnt = 0;
            for (int i = 2; i <= 8; ++i) cnt += tot[i];
            tot[2] += n - cnt;
            for (int i = 2; i <= 8; ++i) {
                for (int j = 0; j < tot[i]; ++j) printf("%d", i);
            }
            printf("\n");
        }
    }

    return 0;
}
