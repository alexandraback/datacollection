// {{{
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
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

int solve() {
    int a, n;
    cin >> a >> n;
    VI B(n);
    REP(i, n)
        cin >> B[i];
    sort(B.begin(), B.end());
    if (a == 1)
        return n;
    int res = n, cur = 0;
    REP(i, n) {
        while (a <= B[i]) {
            ++cur;
            a += a - 1;
        }
        a += B[i];
        res = min(res, cur + n - i - 1);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    FOR(ti, 1, T) {
        cout << "Case #" << ti << ": " << solve() << endl;
    }
}
