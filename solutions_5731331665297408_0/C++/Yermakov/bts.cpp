#include <iostream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[51], n, m;
vector <int> g[51], ans;
bool used[51];

void dfs(int v) {
    used[v] = true;
    ans.push_back (v);
    for (int i = 0; i < g[v].size (); ++i) {
        int to = g[v][i];
        if (!used[to]) dfs(to);
    }
}

bool cmp(int x, int y) {
    return a[x] < a[y];
}

main () {
    freopen ("c.in", "r", stdin);
    freopen ("c.out", "w", stdout);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cin >> n >> m;
        int best = 0;
        ans.clear ();
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            g[i].clear ();
            used[i] = false;
            if (a[i] < a[best]) best = i;
        }
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            g[x].push_back (y);
            g[y].push_back (x);
        }
        for (int i = 0; i < n; ++i) {
            sort (g[i].begin (), g[i].end (), cmp);
        }
        dfs(best);
        cout << "Case #" << test << ": ";
        for (int i = 0; i < n; i++) cout << a[ans[i]];
        cout << "\n";
    }
}
