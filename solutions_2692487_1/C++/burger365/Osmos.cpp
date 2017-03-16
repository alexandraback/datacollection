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

#define PRINT_VAL(sx, vx) cout << sx << " = " << vx
#define PRINT1(x, ...) PRINT_VAL(#x, x)
#define PRINT2(x, ...) PRINT_VAL(#x, x); cout << ", "; PRINT1(__VA_ARGS__)
#define PRINT3(x, ...) PRINT_VAL(#x, x); cout << ", "; PRINT2(__VA_ARGS__)
#define PRINT4(x, ...) PRINT_VAL(#x, x); cout << ", "; PRINT3(__VA_ARGS__)
#define PRINT5(x, ...) PRINT_VAL(#x, x); cout << ", "; PRINT4(__VA_ARGS__)
#define PRINT(n, ...)                                                   \
    do {                                                                \
        PRINT##n(__VA_ARGS__);                                          \
        cout << " [" << __func__ << ", " << __LINE__ << "]" << endl;    \
    } while (0)                                                         \

using namespace std;

int add(int c, int t, int *num) {
    if (c == 1)
        return -1;
    int res = 0;
    while (c <= t) {
        c += c - 1;
        ++res;
    }
    *num = res;
    return c;
}
int main() {
    int T;
    assert(scanf("%d", &T) != EOF);

    for (int t = 1; t <= T; ++t) {
        int A, N;
        assert(scanf("%d %d", &A, &N) != EOF);

        vector<int> v(N);
        for (int i = 0; i < N; ++i)
            assert(scanf("%d", &v[i]) != EOF);

        sort(v.begin(), v.end());

        // index, operation
        int dp[N + 1][N + 1];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = A;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dp[i][j] == 0) continue;
                // absorb
                if (dp[i][j] > v[i]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + v[i]);
                } else {
                    int num;
                    int size = add(dp[i][j], v[i], &num);
                    if (size > 0 && j + num <= N) {
                        dp[i + 1][j + num] = max(dp[i + 1][j + num], size + v[i]);
                    }
                    // remove
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                }
            }
        }
        
        for (int j = 0; j <= N; ++j) {
            if (dp[N][j] > 0) {
                printf("Case #%d: %d\n", t, j);
                break;
            }
        }
    }

    return 0;
}
