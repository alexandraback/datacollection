/*
 * @author: zhenpeng.fang
 * @nickname: dumpling
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

#define mp make_pair

//%llu
typedef unsigned long long uint64;
typedef long long int64;
typedef pair<int, int> pair2;

const double eps = 1e-8;

int T, E, R, N;
int dp[128][128];
int a[128];

void init() {
    memset(dp, 0, sizeof (dp));
    scanf("%d%d%d", &E, &R, &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", a + i);
}

int DP() {
    int k;
    for (int i = 1; i <= N; ++i) {
        for (int j = (i == 1 ? E : 0); j <= E; ++j) {
            for (int b = 0; b <= j; ++b) {
                k = j - b + R;
                k = min(k, E);
                dp[i][k] = max(dp[i][k], dp[i - 1][j] + b * a[i]);
            }
        }
    }
    int ret = 0;
    for (int i = 0; i <= E; ++i)
        ret = max(ret, dp[N][i]);
    return ret;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        init();
        printf("Case #%d: %d\n", t, DP());
    }
    return 0;
}