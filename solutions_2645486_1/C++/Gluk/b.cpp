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

        int e, r, n;
        cin >> e >> r >> n;

        vector<long long> v(n);
        REP (i, n)
            cin >> v[i];

        long long res = v[0]*e;

        VI cc(n);
        cc[0] = e;

        FOR (i, 1, n) {
            cc[i] = r;
            res += v[i]*r;

            int s = 0;
            int mm = e-r;

            FORD (j, i-1, 0) {
                s = s + cc[j]-r;
                if (v[j] < v[i]) {
                    int c = min (cc[j], mm);
                    cc[j] -= c;
                    cc[i] += c;
                    mm-=c;

                    res += (v[i] - v[j])*c;
                }

                mm = min (mm, e-r-s);
            }
        }

        cout << res << endl;
    }

    return 0;
}
