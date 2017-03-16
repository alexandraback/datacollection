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

vector<int> dp[1<<20];
int cnt[128];

void solve() {
    int K, N;
    cin >> K >> N;

    vector<int> x(K);
    REP (i, K) cin >> x[i];

    vector<int> y(N);
    vector<vector<int> > z(N, vector<int>());
    REP (i, N) {
        int M;
        cin >> y[i] >> M;
        z[i].resize(M);
        REP (j, M)
            cin >> z[i][j];
    }

    REP (i, 1<<20)
        dp[i].clear();
    dp[0].push_back(0);

    REP (k, 1<<20) {
        if (!dp[k].size())
            continue;

        memset(cnt, 0, sizeof(cnt));
        REP (i, K) cnt[x[i]-1]++;
        REP (i, N) if (k & 1 << i) REP (j, z[i].size()) cnt[z[i][j]-1]++;
        REP (i, N) if (k & 1 << i) cnt[y[i]-1]--;

        REP (i, N) {
            if (k & 1<<i)
                continue;

            if (cnt[y[i]-1]) {
                vector<int> tmp = dp[k];
                tmp.push_back(i+1);

                if (!dp[k | 1<<i].size())
                    dp[k | 1<<i] = tmp;
                else if (tmp < dp[k | 1<<i])
                    dp[k | 1<<i] = tmp;
            }
        }
    }
    
    int mask = 1<<N;
    if (!dp[--mask].size())
        cout << " IMPOSSIBLE";
    else {
        FOR (i, 1, dp[mask].size())
            cout << " " << dp[mask][i];
    }
}

int main() {
    int T;
    cin >> T;

    REP (i, T) {
        cout << "Case #" << (i+1) << ":";
        solve();
        cout << endl;
    }

    return 0;
}
