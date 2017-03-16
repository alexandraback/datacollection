#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
#define SZ(a) ((int)a.size())
using namespace std;

const double PI = 2.0 * acos (0.0);

typedef pair <int, int> PII;

template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

int n, m, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool dd[25][25];
int a[25][25];

void place(int state) {
    RESET(a, 0);
    REP(i, n) REP(j, m) {
        int x = i * m + j;
        if ((state >> x) & 1) a[i][j] = 1;
    }
}

bool inside(int u, int v) {
    return (0 <= u && u < n && 0 <= v && v < m);
}

bool check() {
    queue<PII> Q;
    RESET(dd, 0);
    REP(i, n) {
        if (!a[i][0] && !dd[i][0]) {
            Q.push(MP(i, 0));
            dd[i][0] = true;
        }
        if (!a[i][m - 1] && !dd[i][m - 1]) {
            Q.push(MP(i, m - 1));
            dd[i][m - 1] = true;
        }
    }
    REP(j, m) {
        if (!a[0][j] && !dd[0][j]) {
            Q.push(MP(0, j));
            dd[0][j] = true;
        }
        if (!a[n - 1][j] && !dd[n - 1][j]) {
            Q.push(MP(n - 1, j));
            dd[n - 1][j] = true;
        }
    }
    int cnt = 0;
    while (!Q.empty()) {
        cnt++;
        PII P = Q.front();
        Q.pop();
        REP(k, 4) {
            int u = P.F + dx[k];
            int v = P.S + dy[k];
            if (inside(u, v) && !a[u][v] && !dd[u][v]) {
                Q.push(MP(u, v));
                dd[u][v] = true;
            }
        }
    }
    return n * m - cnt >= k;
}

void update(int &res, int i) {
    int x = 0;
    while (i) {
        x++;
        i -= i & (-i);
    }
    res = min(res, x);
}

void solve() {
    int num = n * m;
    int res = n * m;
    FOR(i, 1, (1 << num) - 1) {
        place(i);
        if (check())
            update(res, i);
    }
    cout << res << endl;
}

int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.out", "w", stdout);
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    FOR(test, 1, _) {
        cout << "Case #" << test << ": ";
        cin >> n >> m >> k;
        solve();
    }
    return 0;
}
