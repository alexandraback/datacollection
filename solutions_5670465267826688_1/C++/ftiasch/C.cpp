#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 10000;

int table[8][8];
char s[N + 1];
bool can[2][4][8];

int main()
{
    for (int i = 0; i < 8; ++ i) {
        for (int j = 0; j < 8; ++ j) {
            table[i][j] = i ^ j;
            if (i >= 2 && j >= 2 && ((i >> 1) - (j >> 1) + 1) % 3 != 0) {
                table[i][j] ^= 1;
            }
        }
    }
    int test_count;
    scanf("%d", &test_count);
    for (int t = 1; t <= test_count; ++ t) {
        int n;
        long long x;
        scanf("%d%lld%s", &n, &x, s);
        if (x > 12) {
            x = 12 + x % 4;
        }
        memset(can, 0, sizeof(can));
        can[0][0][0] = true;
        for (int i = 0; i < n * x; ++ i) {
            int a = s[i % n] - 'i' + 1 << 1;
            memset(can[i + 1 & 1], 0, sizeof(can[i + 1 & 1]));
            for (int j = 0; j < 3; ++ j) {
                for (int p = 0; p < 8; ++ p) {
                    if (can[i & 1][j][p]) {
                        int pp = table[p][a];
                        can[i + 1 & 1][j][pp] = true;
                        if (pp == (j + 1 << 1)) {
                            can[i + 1 & 1][j + 1][0] = true;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %s\n", t, can[n * x & 1][3][0] ? "YES" : "NO");
    }
    return 0;
}
