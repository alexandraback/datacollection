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

VVI decompose(int x) {
    VVI res;
    VI D(30, 2);
    FORD(i, 29, 0) {
        if (x & (1 << i)) {
            D[i] = 0;
            res.push_back(D);
            D[i] = 1;
        } else {
            D[i] = 0;
        }
    }
    return res;
}

LL solve(const VVI& A, const VVI& B, const VVI& K) {
    LL res = 0;
    FORE(a, A) FORE(b, B) FORE(k, K) {
        VI X(*a), Y(*b), Z(*k);
        LL subres = 1;
        FORD(i, SIZE(X) - 1, 0) {
            int cnt = 0;
            REP(x, 2) REP(y, 2)
                if ((X[i] == 2 || X[i] == x) && (Y[i] == 2 || Y[i] == y) && (Z[i] == 2 || Z[i] == (x & y)))
                    ++cnt;
            subres *= cnt;
        }
        res += subres;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    FOR(ti, 1, t) {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        printf("Case #%d: %lld\n", ti, solve(decompose(a), decompose(b), decompose(k)));
    }
}
