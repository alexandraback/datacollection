#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

int main() {
    int T;
    assert(scanf("%d", &T) != EOF);

    for (int ti = 1; ti <= T; ++ti) {
        int E, R, N;
        assert(scanf("%d %d %d", &E, &R, &N) != EOF);

        vector<int> v(N);
        for (int i = 0; i < N; ++i)
            assert(scanf("%d", &v[i]) != EOF);

        int dp[N + 1][E + 1];
        memset(dp, -1, sizeof(dp));
        dp[0][E] = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= E; ++j) {
                if (dp[i][j] >= 0) {
                    //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                    for (int k = 0; k <= j; ++k) {
                        int e = min(j - k + R, E);
                        dp[i + 1][e] = max(dp[i + 1][e], dp[i][j] + k * v[i]);
                    }
                }
            }
        }
        int res = 0;
        for (int j = 0; j <= E; ++j)
            res = max(res, dp[N][j]);
        printf("Case #%d: %d\n", ti, res);
    }    
    return 0;
}
