// Ã¶¾Ù´ÎÊý
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <queue>

using namespace std;

int D;
int c[1005];

# define testin freopen("B-small-attempt7.in", "r", stdin)
# define testout freopen("outc.txt", "w", stdout)

int main()
{
    testin;
    testout;

    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        scanf("%d", &D);
        memset(c, 0, sizeof(c));
        int mx = 0;
        for (int i = 0, x; i < D; ++i) {
            scanf("%d", &x);
            ++c[x];
            if (x > mx) mx = x;
        }
        int ans = mx;
        int cnt = 0;
        for (int i = 0, j; i < mx; ++i) {
            for (j = mx; j > 0; --j) {
                if (c[j] > 0) {
                    if (j <= 3) break;
                    cnt += c[j];
                    if (j > 4) {
                        c[j-3] += c[j];
                        c[3] += c[j];
                    } else {
                        c[2] += 2*c[j];
                        c[j] = 0;
                    }
                    c[j] = 0;
                    break;
                }
            }
            for (j = mx; j > 0; --j) {
                if (c[j] > 0) {
                    if (ans > j+cnt) ans = j + cnt;
                    break;
                }
            }
            if (j <= 3) break;
        }
        printf("Case #%d: %d\n", ica, ans);
    }

    return 0;
}
