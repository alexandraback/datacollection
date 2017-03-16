#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXN = 11, MAXE = 11, inf = 1023456789;

int T, E, R, N, vals[MAXN], dp[MAXN][MAXE];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &E, &R, &N);
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= E; j++) {
                dp[i][j] = -inf;
            }
        }
        dp[0][E] = 0;

        for (int i = 1; i <= N; i++) {
            scanf("%d", &vals[i]);

            for (int e = 0; e <= E; e++) {
                for (int use = 0; use <= E; use++) {
                    int gain = use * vals[i];
                    int init = e + use;
                    int prev = init - (i == 1 ? 0 : R);
                    if (prev < 0 || prev > E || init > E) {
                        continue;
                    }

                    dp[i][e] = max(dp[i][e], dp[i - 1][prev] + gain);
                    //cout << (dp[i - 1][prev] + gain) << " " << prev << " " << gain << "(" << use << ")" << endl;
                }
                //cout << i << " " << e << ": " << dp[i][e] << endl;
            }
        }

        int ans = 0;
        for (int e = 0; e <= E; e++) {
            ans = max(ans, dp[N][e]);
        }
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
