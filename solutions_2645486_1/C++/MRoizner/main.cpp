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
#include <assert.h>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cout << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

// bool bit(int64 mask, int k) {
//     return ((1LL << k) & mask) != 0;
// }

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int testCount;
    cin >> testCount;
    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
        cerr << "Case #" << testNumber << "..." << endl;
        int64 e, r, n;
        cin >> e >> r >> n;
        if (r > e) {
            cerr << "r > e:" << r << " " << e << endl;
            r = e;
        }
        vector<int64> vv(n);
        for (int i= 0 ; i < n; ++i)
            cin >> vv[i];
        vector<int64> xx(n);
        vector<int64> need(n);
        vector< pair<int64, int> > pp(n);
        for (int i = 0; i < n; ++i) {
            pp[i].first = vv[i];
            pp[i].second = i;
        }
        sort(pp.begin(), pp.end());
        reverse(pp.begin(), pp.end());
        for (int k = 0; k < n; ++k) {
            int i = pp[k].second;
            int64 v = pp[k].first;

            int64 s = e;
            for (int j = 0; j < i; ++j) {
                s -= xx[j];
                assert(s >= 0);
                s += r;
                if (s > e) s = e;
            }

            need[i] = s;
            int64 left = 0;
            s = 0;
            for (int j = i + 1; j < n; ++j) {
                s += r;
                if (s > e) s = e;
                if (s < need[j]) {
                    left += need[j] - s;
                    s = need[j];
                }
                s -= xx[j];
            }
            assert(left <= need[i]);
            xx[i] = need[i] - left;
        }
        int64 res = 0;
        for (int i= 0 ; i < n; ++i)
            res += xx[i] * vv[i];
        cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}