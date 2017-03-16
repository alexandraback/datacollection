#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <complex>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,start,end) for (int var=(start); var<=(end); ++var)
#define FORD(var,start,end) for (int var=(start); var>=(end); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

// typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector< vector<int> > VVI;
typedef vector< vector<bool> > VVB;

int main() {
    int nTests = 0;
    cin >> nTests;

    FOR (test, 1, nTests) {
        int n = 0; int m = 0; cin >> n >> m;

        int maxi = 0;
        VVI a(n, VI(m, 0));
        REP (i, n) REP (j, m) {
            cin >> a.at(i).at(j);
            maxi = max(maxi, a.at(i).at(j));
        }

        bool possible = true;
        VI rowUsed(n, 0); VI colUsed(m, 0);
        FORD (h, maxi, 1) {
            REP (i, n) REP(j, m) {
                if (a.at(i).at(j) == h) {
                    if (rowUsed.at(i) && colUsed.at(j)) {
                        possible = false;
                    }
                }
            }
            REP (i, n) REP(j, m) {
                if (a.at(i).at(j) == h) {
                    rowUsed.at(i) = true; colUsed.at(j) = true;
                }
            }
        }

        cout << "Case #" << test << ": ";
        cout << (possible ? "YES" : "NO");
        cout << "\n";
    }

    return 0;
}
