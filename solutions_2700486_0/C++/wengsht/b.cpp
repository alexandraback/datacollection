
/*
ID: wengsht1
LANG: C++
TASK: test
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define MX 100005
#define REP(i,n) for(int i=0;i<(n);i++)
#define OREP(i,n) for(int i=1;i<=(n);i++)

typedef long long          LL;
typedef unsigned long long ULL;
typedef unsigned int       UINT;

int n, m, k, t;
int x, y;

int cnt[MX];
double dp[1500][1500];
void getdp(int sum, int n) {
    dp[0][0] = 10000.0;

    for(int i = 1; i <= sum;i++) {
        if(i > n) break;
        dp[0][i] = dp[i][0] = dp[i-1][0] * 0.5;
    }
    for(int i = 1;i <= sum;i++) {
        for(int j = 1;j <= sum;j++) {
            if(i + j > n) break;
            if(i == sum) {
                dp[i][j] = dp[i-1][j] * 0.5 + dp[i][j-1];
            }
            else if(j == sum)
                dp[i][j] = dp[i-1][j] + 0.5 * dp[i][j-1];
            else 
                dp[i][j] = dp[i-1][j] * 0.5 + dp[i][j-1] * 0.5;
        }
    }
}
double solve() {
    double ret = 0;
    x = abs(x), y = abs(y);
    int sum = x + y;

    if(n >= cnt[sum]) return 1.0;
    if(sum > 0 && n <= cnt[sum-2]) return 0.0;
    n -= cnt[sum-2];

    getdp(sum, n);
    for(int i = y+1;i <= sum;i++) {
        int j = n - i;
        if(j < 0) break;
        if(j <= sum) {
            ret += dp[j][i];
        }
    }
    ret /= 10000;
    return ret;
}
void init() {
    cnt[0] = 1;
    int i;
    int pre = 1;
    for(i = 2;;i+=2) {
        pre = pre + 4;
        cnt[i] = cnt[i-2] + pre;
        if(cnt[i] >= 1000000) break;
    }
}
int main() {
    freopen("2.txt", "w", stdout);
    init();
    scanf("%d", &t);
    for(int c = 1;c <= t;c++) {
        scanf("%d %d %d", &n, &x, &y);

        double ret = solve();

        printf("Case #%d: %lf\n", c, ret);
    }
    return 0;
}

