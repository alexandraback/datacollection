#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <complex>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

int cnt[35][20][2];

void Init() {
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) if (abs(j - i) <= 2) {
            for (int k = 0; k <= 10; ++k) if (abs(k - i) <= 2 && abs(k - j) <= 2) {
                int tot = i + j + k;
                int mi = max(max(i, j), k);
                int s = max(max(abs(i - j), abs(i - k)), abs(j - k)) == 2;
                cnt[tot][mi][s]++;
            }
        }
    }
    for (int i = 0; i <= 30; ++i) {
        for (int j = 10; j >= 0; --j) {
            for (int k = 0; k < 2; ++k) {
                cnt[i][j][k] += cnt[i][j + 1][k];
            }
        }
    }
}

int dp[105][105], t[105];
int n, s, p;

void main2() {
    scanf("%d%d%d", &n, &s, &p);
    for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (dp[i][j] >= 0) {
                for (int k = 0; k < 2; ++k) {
                    if (j + k <= s) {
                        dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + (cnt[t[i]][p][k] > 0));
                    }
                }
            }
        }
    }
    printf("%d\n", dp[n][s]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    Init();

    int testCnt;
    scanf("%d", &testCnt);
    for (int caseId = 1; caseId <= testCnt; ++caseId) {
        printf("Case #%d: ", caseId);
        main2();
    }
}

