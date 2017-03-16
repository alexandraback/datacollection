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
    freopen("/Users/ramis/Downloads/C-small-attempt0.in.txt","rt",stdin);
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
#define N 1111
/* --------- END TEMPLATE CODE --------- */

int n;
int f[N], d[N];
vector<int> edges[N];
bool used[N];

int dfs(int v) {
    used[v] = true;
    int u = f[v];
    if (f[u] == v) return 0;
    if (used[u]) return d[v] - d[u] + 1;
    d[u] = d[v] + 1;
    return dfs(u);
}

int dfs1(int v) {
    used[v] = true;
    int res = 0;
    for (auto i : edges[v]) if (!used[i]) {
        res = max(res, dfs1(i));
    }
    return res + 1;
}

int solve() {
    int res = 1, s = 0;
    forn(i, n) edges[i].clear();
    forn(i, n) edges[f[i]].push_back(i);
    forn(i, n) {
        memset(used, 0, sizeof(bool) * n);
        if (f[f[i]] == i) {
            used[i] = used[f[i]] = true;
            int p = dfs1(i) + dfs1(f[i]);
            s += p;
            continue;
        }
        d[i] = 0;
        res = max(res, dfs(i));
    }
    return max(res, s / 2);
}

void smain() {
    string s;
    cin >> n;
    for (int cas = 1; cin >> n; ++cas) {
        forn(i, n) cin >> f[i], f[i] -= 1;
        int res = solve();
        cout << "Case #" << cas << ": " << res << endl;
        cerr << "Case #" << cas << ": " << res << endl;
    }
}
