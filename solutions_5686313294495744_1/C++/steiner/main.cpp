#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std; 

int n, k;
vector <vector<int>> g;
vector<int> match;
vector<bool> used;

bool dfs(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int i = 0; i < sz(g[v]); ++i) {
        int to = g[v][i];
        if (match[to] == -1 || dfs(match[to])) {
            match[to] = v;
            return true;
        }
    }
    return false;
}

vector<pair<int, int>> kuhn() {
    vector<pair<int, int> > result;
    match.assign(k, -1);
    for (int i = 0; i < n; ++i) {
        used.assign(n, false);
        dfs(i);
    }
    for (int i = 0; i < k; ++i)
        if (match[i] != -1)
            result.pb(mp(match[i], i));
    return result;
}


void solve() {
    int m;
    cin >> m;
    vector<string> a(m);
    vector<string> b(m);
    map<string, int> a_map;
    map<string, int> b_map;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        if (a_map.find(a[i]) == a_map.end()) {
            n = a_map.size();
            a_map[a[i]] = n;
        }
        if (b_map.find(b[i]) == b_map.end()) {
            k = b_map.size();
            b_map[b[i]] = k;
        }
    }
    n = a_map.size();
    k = b_map.size();
    g.clear();
    g.assign(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int from = a_map[a[i]];
        int to = b_map[b[i]];
        g[from].pb(to);
    }
    int ans = m;
    ans -= n;
    ans -= k;
    ans += sz(kuhn());
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
