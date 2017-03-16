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


int main() {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int n;
        string s;
        cin >> n >> s;
        int res = 0;
        int count = 0;
        for (int i = 0; i <= n; ++i) {
            int c = s[i] - '0';
            // debug(i);
            // debug(c);
            // debug(count);
            if (c > 0 && count < i) {
                res += i - count;
                count = i;
            }
            count += c;
        }
        cout << "Case #" << tt << ": " << res << endl;
    }
}
