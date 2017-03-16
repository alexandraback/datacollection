#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;

void smain();
int main(){
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/B-large.in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    const clock_t start = clock();
#endif
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

#ifndef M_PI
#define M_PI 3.14159265358979311599796346854418516
#endif
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define int long long
#define LL __int128
#define mp(a,b) make_pair(a,b)
#define INF 2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-6
#define N 55
/* --------- END TEMPLATE CODE --------- */
int n, m;
bool g[N][N];

void print(ostream &out, int cas, bool ok) {
    out << "Case #" << cas << ": " << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    if (!ok) return;
    forn(i, n) { forn(j, n) out << g[i][j]; out << endl; }
}


bool used[N];
int d[N];
void dfs(int v) {
    used[v] = 1;
    if (v == n - 1) return void(d[v] = 1);
    forn(i, n) if (!used[i] && g[v][i]) dfs(i);
    forn(i, n) if (g[v][i]) d[v] += d[i];
}
void check() {
    memset(used, 0, sizeof(used));
    memset(d, 0, sizeof(d));
    dfs(0);
    if (d[0] != m) {
        cerr << "Expected " << m << " Found " << d[0] << endl;
        assert(false);
    }
}

int cnt[N];
int solve() {
    int cur = 1;
    memset(g, 0, sizeof(g));
    memset(cnt, 0, sizeof(cnt));
    g[0][n-1] = 1;
    cnt[n-1] = 1;
    for (int i = 1; i < n - 1; ++i) {
        g[0][i] = 1;
        if (cur + cur <= m) {
            cur += cur;
            forn(j, n) if (i != j && cnt[j]) g[i][j] = 1, cnt[i] += cnt[j];
            continue;
        }
        int diff = m - cur;
        for (int l = 0; diff; diff >>= 1, l += 1) if (diff & 1) {
            int k = -1;
            forn(j, i) if (cnt[j] == (1ll << l)) k = j;
            assert(k != -1 && !g[i][k]);
            g[i][k] = 1;
            cur += cnt[k];
            cnt[i] += cnt[k];
        }
    }
    return cur;
}

void smain() {
    cin >> n;
    forn(t, 0) {
        n = rand() % 20 + 2;
        m = rand() % 10000 + 1;
        int cur = solve();
        if (cur < m) continue;
        assert(cur == m);
        check();
    }
    for (int cas = 1; cin >> n >> m; ++cas) {
        int cur = solve();
        if (cur < m) {
            print(cout, cas, false);
            print(cerr, cas, false);
            continue;
        }
        assert(cur == m);
        check();
        print(cout, cas, true);
        print(cerr, cas, true);
    }
}
