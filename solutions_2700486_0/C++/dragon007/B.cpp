#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define A first
#define B second
#define eps 1e-8

int n, t, x, y, xx, yy;
double dp[1010][1010];

double count(int y, int n) {
    //cout<<n<<" "<<y<<endl;
    if (n < y) return 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= min(xx * 2, i); j ++ ) {
            if (i - j > xx * 2) continue;
            if (i - j == xx * 2) {
                if (j != 0)
                    dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] += dp[i - 1][j] * 0.5;
                continue;
            }
            if (j == xx * 2) {
                dp[i][j] = dp[i - 1][j];
                if (j != 0)
                    dp[i][j] += dp[i - 1][j - 1] * 0.5;
                continue;
            }
            dp[i][j] = dp[i - 1][j] * 0.5;
            if (j != 0)
                dp[i][j] += dp[i - 1][j - 1] * 0.5;
        }
    double ans = 0;
    for (int i = y; i <= xx * 2; i ++ ) {
        ans += dp[n][i];
        //printf("dp[%d][%d] = %lf\n", n, i, dp[n][i]);
    }
    return ans;
}

int main() {
    freopen("B-small-attempt6.in", "r", stdin);
    freopen("B-small-attempt6.out", "w", stdout);
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%d%d%d", &n, &x, &y);
        double ans = 0;
        if (!((abs(x) + abs(y)) & 1)) {
            xx = (abs(x) + abs(y)) / 2;
            yy = abs(y) + 1;
            int cnt = 0;
            while (n >= cnt * 4 + 1) {
                n -= cnt * 4 + 1;
                cnt ++ ;
            }
            if (xx < cnt) ans = 1;
            else if (xx > cnt) ans = 0;
            else ans = count(yy, n);
        }
        printf("Case #%d: %.8lf\n", ca, ans + eps);
    }
    return 0;
}
