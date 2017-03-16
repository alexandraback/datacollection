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
const int64 MAX = 2000000000000000000;

int64 get(int64 n, int64 r) {
    if (n == 0) return 0;
    if (2 * n > MAX / n) return MAX + 1;
    if (n > MAX / (2 * r - 1)) return MAX + 1;
    if (2 * n * n > MAX - (2 * r - 1) * n) return MAX + 1;
    return 2 * n * n + (2 * r - 1) * n;
}


int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int testCount;
    cin >> testCount;
    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
        cerr << "Case #" << testNumber << "..." << endl;
        int64 r, t;
        cin >> r >> t;
        // int64 res = (-2 * r + 1 + (int64) sqrt((2 * r - 1) * (2 * r - 1) + 8 * t)) / 4;
        int64 lo = 0;
        int64 hi = 2 * (int64) sqrt(2 * t) + 1;
        assert(t <= MAX);
        assert(get(lo, r) <= t);
        assert(get(hi, r) > t);
        while (lo < hi - 1) {
            int64 mid = lo + (hi - lo) / 2;
            if (get(mid, r) <= t)
                lo = mid;
            else
                hi = mid;
        }
        cout << "Case #" << testNumber << ": " << lo << endl;
    }

    return 0;
}