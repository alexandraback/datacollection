#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>

using namespace std;

const int maxn = 10010;
int v[maxn], N, R, E;
int dp[2][6];
void solved(int nT) {
    scanf("%d %d %d", &E, &R, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][E] = 0;
    int cur = 1, pre = 0;
    for (int i = 0; i < N; ++i) {
        memset(dp[cur], -1, sizeof(dp[cur]));
        for (int e = 0; e <= E; ++e) {
            if (dp[pre][e] == -1) continue;
            for (int se = 0; se <= e; ++se) {
                int ne = min(E, se + R);
                int de = e - se;
                if (dp[cur][ne] == -1) {
                    dp[cur][ne] = dp[pre][e] + de * v[i];
                } else if (dp[cur][ne] < dp[pre][e] + de * v[i]) {
                    dp[cur][ne] = dp[pre][e] + de * v[i];
                }
            }
        }
        swap(pre, cur);
    }
    int result = *max_element(dp[pre], dp[pre] + E + 1);
    printf("Case #%d: %d\n", nT, result);
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T = 1;
    scanf("%d", &T);
    for (int nT = 1; nT <= T; ++nT) {
        solved(nT);
    }
    return 0;
}