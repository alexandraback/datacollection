#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  

int dp[16][16];

void solve() { 
    int E, R, N;
    cin >> E >> R >> N;
    vector<int> v(N);
    REP (i, N)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));
    dp[0][E] = 0;

    REP (i, N) {
        REP (j, 16) {
            if (dp[i][j] == -1)
                continue;

            REP (k, j+1) {
                int nv = dp[i][j] + k * v[i];
                dp[i+1][min(E, j-k+R)] = max(dp[i+1][min(E, j-k+R)], nv);
            }
        }
    }

    int ret = 0;
    REP (i, 16) ret = max(ret, dp[N][i]);
    cout << ret << endl;
}

int main() {
    int T;
    cin >> T;

    REP (i, T) {
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}
