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
        char buf[128];
        vector<vector<pair<char, int> > > A(n);
        REP(i, n) {
            scanf("%s", buf);
            for (int j = 0; buf[j]; ++j)
                if (A[i].empty() || A[i].back().first != buf[j]) {
                    A[i].push_back(make_pair(buf[j], 1));
                } else {
                    ++A[i].back().second;
                }
        }
        printf("Case #%d: ", ti);

        bool ok = true;
        VVI B(SIZE(A[0]), VI(n));
        REP(i, n) {
            if (SIZE(A[i]) != SIZE(A[0])) {
                ok = false;
                break;
            }
            REP(j, SIZE(A[0])) {
                if (A[i][j].first != A[0][j].first) {
                    ok = false;
                    break;
                }
                B[j][i] = A[i][j].second;
            }
            if (!ok)
                break;
        }

        if (ok) {
            int res = 0;
            REP(j, SIZE(B)) {
                sort(B[j].begin(), B[j].end());
                int m = B[j][n / 2];
                REP(i, n)
                    res += abs(B[j][i] - m);
            }
            printf("%d\n", res);
        } else {
            printf("Fegla Won\n");
        }
    }
}
