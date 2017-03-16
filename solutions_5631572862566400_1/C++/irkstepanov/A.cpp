#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
vector<int> g;
vector<vector<int> > gr;

int start;
vector<char> used;
int cnt;

int dfs(int v)
{
    used[v] = true;
    ++cnt;
    int u = g[v];
    if (used[u]) {
        if (g[u] == v) {
            return 2;
        }
        if (u == start) {
            return 1;
        }
        return 0;
    }
    dfs(u);
}

int a, b;
vector<int> dep;

void dfs_tree(int v)
{
    if (gr[v].empty()) {
        return;
    }
    for (int to : gr[v]) {
        if (to == a || to == b) {
            continue;
        }
        dep[to] = dep[v] + 1;
        dfs_tree(to);
    }
}

int main()
{

    ifstream cin("C-large.in");
    ofstream cout("outcbig.txt");

    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;

    for (int step = 0; step < tt; ++step) {
        cin >> n;
        g.resize(n);
        gr.resize(n);
        for (int i = 0; i < n; ++i) {
            gr[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            cin >> g[i];
            --g[i];
            gr[g[i]].pb(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            used.assign(n, false);
            start = i;
            cnt = 0;
            int x = dfs(i);
            if (x == 1) {
                ans = max(ans, cnt);
                //cout << "!" << ans << "\n";
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (g[g[i]] == i && i < g[i]) {
                a = i, b = g[i];
                dep.assign(n, -1);
                dep[a] = 0;
                dfs_tree(a);
                int v = 0;
                for (int j = 0; j < n; ++j) {
                    if (dep[j] > dep[v]) {
                        v = j;
                    }
                }
                int d = dep[v];
                dep.assign(n, -1);
                dep[b] = 0;
                dfs_tree(b);
                v = 0;
                for (int j = 0; j < n; ++j) {
                    if (dep[j] > dep[v]) {
                        v = j;
                    }
                }
                res += 2 + d + dep[v];
            }
        }
        ans = max(ans, res);
        cout << "Case #" << step + 1 << ": " << ans << "\n";
    }

}
