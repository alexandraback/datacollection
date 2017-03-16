#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
typedef pair<int, int> PII;

#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define FILLCHAR(a, x) memset(a, x, sizeof(a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()

LL run() {
    int N;
    cin >> N;
    VS trains(N);
    REP(i,N) cin >> trains[i];

    REP(i,N) {
        string newTrain;
        REP(j,SZ(trains[i])) {
            if (j == 0 || trains[i][j] != trains[i][j - 1]) {
                newTrain += trains[i][j];
            }
        }

        trains[i] = newTrain;
    }

    VI p(N);
    REP(i,N) p[i] = i;
    int ret = 0;
    do {
        bool valid = true;
        VS thisTrain(N);
        REP(i,N) {
            thisTrain[i] = trains[p[i]];
        }

        string thisT;
        REP(i,N) thisT += thisTrain[i];

        vector<bool> flag(26, false);
        REP(i,SZ(thisT)) flag[thisT[i] - 'a'] = true;
        FOR(i, 'a', 'z') {
            if (flag[i - 'a'] == false) continue;
            int mini = INT_MAX;
            int maxi = INT_MIN;
            REP(j,SZ(thisT)) {
                if (thisT[j] == i) {
                    mini = min(mini, j);
                    maxi = max(maxi, j);
                }
            }

            if (mini != INT_MAX) {
                FOR(j, mini, maxi) {
                    if (thisT[j] != i)
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) break;
        }

        if (valid) ret++;
    } while (next_permutation(ALL(p)));

    return ret;
}
int main() {
    int t;
    cin >> t;
    REP(i,t) {
        LL ret = run();
        cout << "Case #" << i + 1 << ": " << ret << endl;
    }
}

