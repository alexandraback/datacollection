#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector <vector <int> > g;
vector <char> act;

bool dfs(int v) {
    act[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (act[u]) return true;
        bool good = dfs(u);
        if (good) return true;
    }
    return false;
}

string solve() {
    for (int i = 0; i < n; ++i) {
        act.assign(n, false);
        bool ans = dfs(i);
        if (ans) return "Yes";
    }
    return "No";
}

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cin >> n;
        g.assign(n, vector <int> ());
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int to;
                cin >> to; --to;
                g[to].push_back(i);
            }
        }
        cout << "Case #" << tt << ": " << solve() << '\n';
    }

    return 0;
}
