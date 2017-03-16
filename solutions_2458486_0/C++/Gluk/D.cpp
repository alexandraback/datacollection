#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <memory.h>

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define INF 1000000000
#define X first
#define Y second
#define pb push_back

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

int r[1<<20];
vector <int> res;
int N;

VI a;
int K[20][256];
int KK[256];

bool solve(int mask) {
    if (mask == 0)
        return true;
    if (r[mask])
        return false;

    REP (i, N)
        if (mask & (1 << i)) {
            int c = KK[a[i]];
            REP (j, N)
                if (!(mask & (1 << j)))
                    c += K[j][a[i]];

            if (c && solve(mask ^ (1 << i))) {
                res.pb(i);
                return true;
            }
        }

    r[mask] = 1;

    return false;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t) {
        std::cout << "Case #" << tt+1 << ":";

        memset(r, 0, sizeof(r));
        memset(K, 0, sizeof(K));
        memset(KK, 0, sizeof(KK));
        res.clear();

        int k;
        cin >> k >> N;
        a.resize(N);

        while (k--) {
            int kk;
            cin >> kk;
            KK[kk] ++;
        }
        REP (i, N) {
            cin >> a[i];
            cin >> k;
            while (k--) {
                int kk;
                cin >> kk;
                K[i][kk]++;
            }
            K[i][a[i]] --;
        }

        if (solve((1<<N)-1)) {
            reverse(ALL(res));
            REP (i, res.size())
                cout << " " << res[i] + 1;
            cout << endl;
        } else {
            cout << " IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
