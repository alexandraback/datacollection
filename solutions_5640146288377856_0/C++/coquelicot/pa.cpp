#include <cstdio>
#include <algorithm>

int dp1[30][30];
int dp2[30][30];

int main() {

    for (int w = 1; w <= 20; w++)
        for (int c = w; c <= 20; c++) {
            if (c >= w * 2) {
                dp1[w][c] = 10000;
                for (int k = 1; k <= c; k++) {
                    int cost = dp1[w][k - 1] + dp1[w][c - k] + 1;
                    dp1[w][c] = std::min(dp1[w][c], cost);
                }
                dp2[w][c] = 10000;
                for (int k = 1; k <= c; k++) {
                    int cost1 = dp1[w][k - 1] + dp2[w][c - k] + 1;
                    int cost2 = dp2[w][k - 1] + dp1[w][c - k] + 1;
                    int cost3 = (c > w ? w + 1 : w);
                    int cost = std::max(cost1, std::max(cost2, cost3));
                    dp2[w][c] = std::min(dp2[w][c], cost);
                }
            } else {
                dp1[w][c] = 1;
                dp2[w][c] = c > w ? w + 1 : w;
            }
        }

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {

        int r, c, w;
        scanf("%d %d %d", &r, &c, &w);

        int ans = 0;
        if (w > 1) {
            ans += (r - 1) * (c / w);
            if (w * 2 > c)
                ans += (c > w ? w + 1 : w);
            else
                //ans += dp[w][c] + w - 1;
                ans += dp2[w][c];
        } else {
            ans = r * c;
        }
        printf("Case #%d: %d\n", t, ans);

    }

}
