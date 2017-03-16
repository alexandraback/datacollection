/*
 * Author: tender
 * Created Time:  2012/4/14 13:20:06
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
int dp[102][102];
int main() {
    int cas;
    //freopen("B-large.in", "r", stdin);
    //freopen("2.txt", "w", stdout);
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d: ", ii);
        int n, s, p, a[105];
        scanf("%d%d%d", &n, &s, &p);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            int tmp = a[i] % 3;
            if (tmp == 0) {
                int d = a[i] / 3;
                for (int j = 0; j <= s && j < i; j++)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + (d >= p));
                d--;
                if (d < 0) continue;
                for (int j = 0; j < s && j < i; j++)
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + (d + 2 >= p));
            }
            else if (tmp == 1) {
                int d = a[i] / 3;
                for (int j = 0; j <= s && j < i; j++)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + (d + 1 >= p));
                d--;
                if (d < 0) continue;
                for (int j = 0; j < s && j < i; j++)
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + (d + 2 >= p));
            }
            else {
                int d = a[i] / 3;
                for (int j = 0; j <= s && j < i; j++)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + (d + 1 >= p));
                for (int j = 0; j < s && j < i; j++)
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + (d + 2 >= p));
            }
        }
        //for (int i = 0; i <= n; i++)
            //for (int j = 0; j <= s; j++)
                //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        printf("%d\n", dp[n][s]); 
    }
    return 0;
}
