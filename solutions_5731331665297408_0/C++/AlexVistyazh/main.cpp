#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int INF = int(1e9 + 5);

int n, m;
vector<int> g[111];
set<int> a;
string z[111];

bool met[111];
string ans;

bool cmp(int i, int j) {
    return z[i] < z[j];
}

void dfs(int v) {
    ans += z[v];
    met[v] = 1;
    sort(g[v].begin(),g[v].end(),cmp);
    for (size_t i=0;i<g[v].size();i++) {
        int to = g[v][i];
        if (!met[to]) dfs(to);
    }
}

void solve() {
    ans.clear();
    a.clear();
    memset(met, 0, sizeof(met));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) cin >> z[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int v = -1;
    for (int i = 1; i <= n; i++) {
        if (v==-1 || z[i]<z[v]) v = i;
    }
    dfs(v);
    if (ans.size()/5 != n) cerr << "WA!!!\n";
    cout << ans << '\n';
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        ++c;
        cout << "Case #" << c << ": ";
        solve();
    }
    return 0;
}
