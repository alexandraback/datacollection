/*
 * Author: tender
 * Created Time:  2013/4/27 10:01:26
 * File Name: b.cpp
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace std;
const double pi = acos(-1.0);
const int maxn = 10;
int v[maxn + 5];
int dp[maxn + 2][6];
int main() {
    int cas;
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d: ", ii);
        int e, r, n;
        scanf("%d%d%d", &e, &r, &n);
        if (r > e) r = e;
        for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
        int t[15];
        memset(t, 0, sizeof(t));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= e; i++) t[i] = v[1] * (e - i);
        for (int i = 0; i + r <= e; i++)
            dp[1][i + r] = t[i];
        for (int i = e - r + 1; i <= e; i++)
            dp[1][e] = max(dp[1][e], t[i]);
        for (int i = 2; i <= n; i++) {
            memset(t, 0, sizeof(t));
            for (int j = 0; j <= e; j++) {
                for (int k = j; k <= e; k++)
                    t[j] = max(t[j], dp[i - 1][k] + v[i] * (k - j));
            }
            for (int k = 0; k + r <= e; k++)
                dp[i][k + r] = t[k];
            for (int k = e - r + 1; k <= e; k++)
                dp[i][e] = max(dp[i][e], t[k]);
        }
        int ans = -1;
        for (int i = 0; i <= e; i++)
            ans = max(ans, dp[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}
