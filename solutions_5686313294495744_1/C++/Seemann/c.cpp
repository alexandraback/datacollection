#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 2100;

string a[MAXN], b[MAXN];
int pr[MAXN];
bool used[MAXN];
vector<int> e[MAXN];

bool dfs(int v) {
    used[v] = true;
    for (auto u : e[v]) {
        if (pr[u] == -1 || (!used[pr[u]] && dfs(pr[u]))) {
            pr[u] = v;
            return true;
        }
    }
    return false;
}

void solve() {
    int m;
    cin >> m;
    map<string, int> numl, numr;
    forn(i, m) {
        string s, t;
        cin >> s >> t;
        numl[s] = 0;
        numr[t] = 0;
        a[i] = s;
        b[i] = t;
    }
    int nl = 0;
    for (auto it = numl.begin(); it != numl.end(); ++it) {
        it->second = nl++;
    }
    int nr = 0;
    for (auto it = numr.begin(); it != numr.end(); ++it) {
        it->second = nr++;
    }
    forn(i, nl) {
        e[i].clear();
    }
    forn(i, m) {
        e[numl[a[i]]].pb(numr[b[i]]);
    }
    forn(i, nr) {
        pr[i] = -1;
    }
    int ans = nl + nr;
    forn(i, nl) {
        clr(used);
        if (dfs(i))
            ans--;
    }
    cout << m - ans << '\n';
}
int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int T;
    cin >> T;
    forn(test, T) {
        printf("Case #%d: ", test + 1);
        solve();
    }
    
    return 0;
}

