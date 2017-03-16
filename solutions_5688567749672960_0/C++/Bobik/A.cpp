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

int reverse(int x) {
    int res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    const int MAXN = 1e6 + 7;
    queue<int> Q;
    VI D(MAXN, INF);
    Q.push(1);
    D[1] = 1;
    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();
        int w = t + 1;
        if (w < MAXN && D[w] == INF) {
            D[w] = D[t] + 1;
            Q.push(w);
        }
        w = reverse(t);
        if (w < MAXN && D[w] == INF) {
            D[w] = D[t] + 1;
            Q.push(w);
        }
    }

    int t;
    scanf("%d", &t);
    FOR(ti, 1, t) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", ti, D[n]);
    }
}
