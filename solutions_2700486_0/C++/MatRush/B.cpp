#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline int sgn(double x) {
    return x < -eps ? -1 : x > eps;
}

const int MAXN = 22;

double dp[MAXN][MAXN][MAXN];

void init() {
    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = 1;
    for (int n = 1; n < MAXN - 1; n++) {
        for (int len = 0; len <= 4 * n; len++) {
            for (int i = 0; i <= 2 * n; i++) {
            //for (int j = 1; j <= 2 * n; j++) {
                int j = len - i;
                if (j > 2 * n) continue;
                if (i == 2 * n && j == 2 * n) {
                    dp[n + 1][0][0] += dp[n][i][j];
                } else if (i == 2 * n) {
                    dp[n][i][j + 1] += dp[n][i][j];
                } else if (j == 2 * n) {
                    dp[n][i + 1][j] += dp[n][i][j];
                } else {
                    dp[n][i + 1][j] += 0.5 * dp[n][i][j];
                    dp[n][i][j + 1] += 0.5 * dp[n][i][j];
                }
            }
        }
    }
}

int getn(int x) {//小于它的
    int l = 0, r = 1000;
    while (l <= r) {
        int mid = l + r >> 1;
        if ((2 * mid + 1) * ((2 * mid + 1) + 1) / 2 > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
    int ans = 2 * l - 1;
    return ans * (ans + 1) / 2;
}

int main() {
    //freopen("A-large-practice.in", "r", stdin);
    //freopen("A-large-practice.out", "w", stdout);
    init();
    /*for (int i = 1; i <= 17; i++) {
        printf("%d %d\n", i, getn(i));
    }*/
    int cas, n, x, y;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T++) {
        scanf("%d %d %d", &n, &x, &y);
        printf("Case #%d: ", T);
        if (x < 0) x = -x;
        int num = x / 2;
        if (x == 0) {
            int sum = 2 * (y / 2 + 1) - 1;
            sum = sum * (sum + 1) / 2;
            if (n >= sum) {
                printf("%.7lf\n", 1.0);
            } else {
                printf("%.7lf\n", 0.0);
            }
            //if (n == 1+2*2+1+2*3+1+2*4
                    //1,6,15  n*(n+1)/2
        } else {
            int l = getn(n);
            int sum = 2 * l - 1;
            sum = sum * (sum + 1) / 2;
            int cnt = n - sum;
            /*if (cnt - (y + 1) >= 0 && cnt - (y + 1) <= 2 * n) {
                printf("%.7lf\n", dp[l][cnt - (y + 1)][(y + 1)]);
            } else {
                printf("%.7lf\n", 0.0);
            }*/
            if (x <= 2 * l - 2 && x + y <= l) {
                printf("%.7lf\n", 1.0);
            }
            double ans = 0;
            for (int i = y + 1; i <= 2 * l; i++) {
                if (cnt - i >= 0 && cnt - i <= 2 * l)
                    ans += dp[l][cnt - i][i];
            }
            printf("%.7lf\n", ans);
        }
        //printf("%.7lf\n", dp[n][)
    }
    return 0;
}
