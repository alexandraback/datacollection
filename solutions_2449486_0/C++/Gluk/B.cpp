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

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t) {
        std::cout << "Case #" << tt+1 << ": ";

        int n, m;
        cin >> n >> m;
        VVI a(n, VI(m));
        REP (i, n)
            REP (j, m)
                cin >> a[i][j];

        VI b(n);
        VI c(m);

        REP (i, n)
            REP (j, m) {
                b[i] = max(b[i], a[i][j]);
                c[j] = max(c[j], a[i][j]);
            }


        bool ok = true;
        REP (i, n)
            REP (j, m) {
                if (a[i][j] < b[i] && a[i][j] < c[j])
                    ok = false;
            }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
