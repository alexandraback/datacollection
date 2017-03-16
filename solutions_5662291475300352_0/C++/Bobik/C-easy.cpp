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

template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os;
}

template<typename T> ostream& operator << (ostream& os, const vector<T>& v) {
    os << "["; FORE(i, v) { if (i != v.begin()) os << ", "; os << *i; } os << "]"; return os;
}

typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;
// }}}

int main() {
    int t;
    scanf("%d", &t);
    FOR(ti, 1, t) {
        int n;
        scanf("%d", &n);
        vector<PI> A;
        REP(i, n) {
            int d, h, m;
            scanf("%d%d%d", &d, &h, &m);
            REP(j, h)
                A.push_back(PI(d, m + j));
        }

        int res;
        if (SIZE(A) == 1) {
            res = 0;
        } else if (SIZE(A) == 2) {
            LL t0 = (LL) A[0].second * (360 - A[0].first);
            LL t1 = (LL) A[1].second * (360 - A[1].first);
            LL q0 = t0 + 360ll * A[0].second;
            LL q1 = t1 + 360ll * A[1].second;
            if (max(t0, t1) >= min(q0, q1)) {
                res = 1;
            } else {
                res = 0;
            }
        } else {
            assert(false);
            res = 0;
        }

        printf("Case #%d: %d\n", ti, res);
    }
}
