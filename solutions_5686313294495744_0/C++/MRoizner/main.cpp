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
#include <iomanip>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define mplus(x, y) ((x) == -1 || (y) == -1) ? -1 : ((x) + (y))
#define mmax(x, y) ((x) == -1 || (y) == -1) ? -1 : max((x), (y))
#define mmin(x, y) ((x) == -1) ? (y) : ((y) == -1) ? (x) : min((x), (y))

#define checkbit(n, k) (((1L << (k)) & (n)) != 0)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cerr << "> " << #x << ": " << (x) << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

int foo(vector<string>& left, vector<string>& right) {
    int res = 0;
    int n = left.size();
    for (int mask = 1; mask < (1L << n); ++mask) {
        int r = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (checkbit(mask, i)) {
                ++r;
                bool ok1 = false, ok2 = false;
                for (int j = 0; j < n; ++j) {
                    if (!checkbit(mask, j)) {
                        if (left[i] == left[j])
                            ok1 = true;
                        if (right[i] == right[j])
                            ok2 = true;
                    }
                }
                if (!ok1 || !ok2) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            res = max(res, r);
        }
    }
    return res;
}

int main() {
     // freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;

    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
        int n;
        cin >> n;
        vector<string> left(n), right(n);
        for (int i = 0; i < n; ++i)
            cin >> left[i] >> right[i];
        auto res = foo(left, right);
        cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}
