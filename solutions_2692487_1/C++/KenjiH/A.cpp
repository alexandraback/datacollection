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

int A, N;
int x[128];
long long dp[128][128];
const long long oo = 1LL << 60;

pair<int, long long> count(long long x, long long y) {
    if (x < 2)
        return make_pair(256, 256);

    int cnt = 0;
    while (x <= y) {
        x = x + x - 1;
        ++cnt;
    }

    return make_pair(cnt, x);
}

void solve() {
    cin >> A >> N;
    REP (i, N)
        cin >> x[i];

    sort(x, x+N);
    
    REP (i, 128) REP (j, 128) dp[i][j] = -1;
    dp[0][0] = A;

    REP (i, N) {
        REP (j, 128) {
            if (dp[i][j] == -1)
                continue;

            if (dp[i][j] > x[i])
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + x[i]);
            else {
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);   // remove
                pair<int, long long> u = count(dp[i][j], x[i]);  // add some motes

                if (j+u.first < 128)
                    dp[i+1][j+u.first] = max(dp[i+1][j+u.first], x[i] + u.second); 
            }
        }
    }
    
    int ret = 0;
    REP (i, 128) if (dp[N][i] != -1) {
        ret = i;
        break;
    }
    
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
