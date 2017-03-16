// {{{
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))
#define DEBUG(x) { cerr << #x << ": " << (x) << endl; }
#define SQR(x) ((x) * (x))
#define INF 1023456789
using namespace std;

typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;
// }}}

double solve() {
    int n, x, y;
    cin >> n >> x >> y;

    int level = 0;
    while (n > 4 * level + 1) {
        n -= 4 * level + 1;
        ++level;
    }

    int w = (abs(x) + y) / 2;
    if (w < level)
        return 1.0;
    if (w > level)
        return 0.0;
    if (n == 4 * level + 1)
        return 1.0;
    if (y == 2 * level)
        return 0.0;

    vector<double> P(2 * level + 1, 0.0);
    P[0] = 1.0;
    REP(i, n) {
        vector<double> T(2 * level + 1, 0.0);
        REP(j, 2 * level + 1)
            if (j == 2 * level) {
                T[j] += P[j];
            } else if (i - j == 2 * level) {
                T[j + 1] += P[j];
            } else {
                T[j] += 0.5 * P[j];
                T[j + 1] += 0.5 * P[j];
            }
        P.swap(T);
    }

    double res = 0.0;
    FOR(i, y + 1, 2 * level)
        res += P[i];
    return res;
}

int main() {
    int T;
    cin >> T;
    FOR(ti, 1, T)
        cout << "Case #" << ti << ": " << setprecision(10) << solve() << endl;
}
