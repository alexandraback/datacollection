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

int best(int n1, vector<int> d, vector<int> h, vector<int> m) {
    vector< pair<double, int> > hikers;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < h[i]; ++j) {
            int v = m[i] + j;
            double t = (360L - d[i]) * v / 360.0;
            hikers.push_back(mp(t, v));
        }
    }
    sort(hikers.begin(), hikers.end());
    int n = hikers.size();
    int res = n;
    for (int s = 0; s < n; ++s) {
        int r = n - s - 1;
        double t = hikers[s].first;
        for (int i = 0; i < s; ++i) {
            r += (int) ((t - hikers[i].first) / hikers[i].second);
        }
        if (r < res) res = r;
    }
    return res;
}

int main() {
    // for (int N = 1; N <= 100000; ++N) {
    //     if (bfs(N) != bfs2(N)) {
    //         cout << "AAA: " << N << endl;
    //     }
    // }
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        // debug(tt);
        int n;
        cin >> n;
        vector<int> d(n), h(n), m(n);
        for (int i = 0; i < n; ++i)
            cin >> d[i] >> h[i] >> m[i];
        int64 res = best(n, d, h, m);
        cout << "Case #" << tt << ": " << res << endl;
    }
}
