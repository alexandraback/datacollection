#include <fstream>
#include <vector>

using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");

int n, a, b;
vector< vector<int> > g;
vector<int> used;

bool dfs(int v) {
    if (used[v]) return true;
    used[v] = 1;
    for (int i = 0; i < (int)g[v].size(); ++i)
        if (dfs(g[v][i])) return true;
    return false;
}

void solve(int t) {
    g.clear();
    cin >> n;
    used.assign(n, 0);
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        for (int j = 0; j < a; ++j) {
            cin >> b;
            g[i].push_back(b-1);
        }
    }
    for (int i = 0; i < n; ++i) {
        used.assign(n, 0);
        if (dfs(i)) {
            cout << "Case #" << t << ": Yes\n";
            return;
        }
    }
    cout << "Case #" << t << ": No\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) solve(i);

    return 0;
}
