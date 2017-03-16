#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPEQ(i, n) for (int i = 0; i <= (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define FOREQ(i, a, b) for (int i = (a); i <= (int)(b); ++i)

int E, R, N, v[20];
int memo[20][20];

int dp(int i, int e)
{
    if (memo[i][e] != -1)
        return memo[i][e];

    if (i == 0)
        return memo[0][e] = (E - e) * v[0];

    int ans = 0;
    FOREQ(ep, max(0, e - R), E) {
        int curr = min(ep + R, E);
        int use = curr - e;
        ans = max(ans, dp(i - 1, ep) + use * v[i]);
    }
    return memo[i][e] = ans;
}

int main()
{
    int T; cin >> T;
    REP(testcase, T) {
        cout << "Case #" << testcase + 1 << ": ";
        cin >> E >> R >> N;
        REP(i, N) cin >> v[i];
        memset(memo, -1, sizeof(memo));

        int ans = 0;
        FOREQ(e, 0, E)
            ans = max(ans, dp(N - 1, e));
        cout << ans << endl;
    }
}

