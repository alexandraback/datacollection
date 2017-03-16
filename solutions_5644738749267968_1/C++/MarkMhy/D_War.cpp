#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;


int T, N, dp[1005][1005];
float naomi[1005], ken[1005];

int judge(int a, int b) {
    if (naomi[a] > ken[b]) return 1;
    return 0;
}

int DP() {
    int ret = -0x7fffffff;
    for (int i = 1; i <= N; ++i) {
        dp[0][i] = dp[0][i-1] + judge(i, N-i+1);
        dp[i][i] = dp[i-1][i-1] + judge(N-i+1, N-i+1);
        for (int j = 1; j < i; ++j) {
            dp[j][i] = max(dp[j-1][i-1] + judge(N-j+1, N-i+1), dp[j][i-1] + judge(i-j, N-i+1));
        }
    }
    for (int i = 0; i <= N; ++i) {
        ret = max(ret, dp[i][N]);
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%f", naomi+i);
        }
        for (int i = 1; i <= N; ++i) {
            scanf("%f", ken+i);
        }
        sort(naomi+1, naomi+1+N);
        sort(ken+1, ken+1+N);
        printf("Case #%d: %d ", t, DP());
        for (int i = 1; i <= N; ++i) {
            swap(naomi[i], ken[i]);
        }
        printf("%d\n", N-DP());
    }
    return 0;
}

