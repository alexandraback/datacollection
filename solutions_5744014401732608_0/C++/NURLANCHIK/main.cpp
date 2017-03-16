#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x) * (x))
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 6;

int b, m, e;
vi g[N];
ll dp[N];
char res[N][N];
vector <pii> edges;

ll calc(int u) {
    if (u == b - 1) {
        return 1;
    }
    ll &res = dp[u];
    if (res != -1) {
        return res;
    }
    res = 0;
    for (int v : g[u]) {
        res += calc(v);
    }
    return res;
}

bool can(int mask) {
    for (int i = 0; i < N; i++) {
        g[i].clear();
    }
    for (int i = 0; i < e; i++) {
        if (mask & (1 << i)) {
            int u = edges[i].f;
            int v = edges[i].s;
            g[u].pb(v);
        }
    }
    memset(dp, -1, sizeof(dp));
    ll res = calc(0);
    if (res == m) {
        return true;
    }
    return false;
}

void print(int mask) {
    memset(res, '0', sizeof(res));
    for (int i = 0; i < e; i++) {
        if (mask & (1 << i)) {
            int u = edges[i].f;
            int v = edges[i].s;
            res[u][v] = '1';
        }
    }
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            cout << res[i][j];
        }
        if (i < b - 1) {
            cout << "\n";
        }
    }
}

void solve() {
    cin >> b >> m;
    e = b * (b - 1) / 2;
    edges.clear();
    for (int i = 0; i < b - 1; i++) {
        for (int j = i + 1; j < b; j++) {
            edges.pb({i, j});
        }
    }
    for (int mask = 0; mask < (1 << e); mask++) {
        if (can(mask)) {
            cout << "POSSIBLE\n";
            print(mask);
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    freopen("/Users/nurlan/Dropbox/Programming/Google/googleSmall/googleSmall/input", "r", stdin);
    freopen("/Users/nurlan/Dropbox/Programming/Google/googleSmall/googleSmall/output", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}