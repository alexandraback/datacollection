#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <stack>
#include <assert.h>
// #include <unordered_set>
#include <iomanip>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define mplus(x, y) ((x) == -1 || (y) == -1) ? -1 : ((x) + (y))
#define mmax(x, y) ((x) == -1 || (y) == -1) ? -1 : max((x), (y))
#define mmin(x, y) ((x) == -1) ? (y) : ((y) == -1) ? (x) : min((x), (y))
#define checkbit(n, k) (((1L << (k)) & (n)) != 0)

#define debug(x) cerr << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;


bool can(const vi& d, int res) {
    int n = d.size();
    for (int maxcount = 1; maxcount <= res; ++maxcount) {
        int k = res - maxcount;
        for (int i = 0; i < n; ++i) {
            int c = (d[i] - 1) / maxcount;
            k -= c;
            if (k < 0) break;
        }
        if (k >= 0) return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int n;
        cin >> n;
        vi d(n);
        for (int i = 0; i < n; ++i) cin >> d[i];

        int lo = 0;
        int hi = 0;
        for (int i = 0; i < n; ++i)
            hi = max(hi, d[i]);
        assert(can(d, hi));
        while (lo + 1 < hi) {
            int m = lo + (hi - lo) / 2;
            if (can(d, m))
                hi = m;
            else
                lo = m;
        }
        int res = hi;
        cout << "Case #" << tt << ": " << res << endl;
    }
}
