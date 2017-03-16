#include <bits/stdc++.h>

using namespace std;

const int maxN = 1005;

map<string,int> idx, idy;

int x[maxN], y[maxN], p1[maxN], p2[maxN], was[maxN];
vector<int> g[maxN];

bool dfs(int v) {
    if (v == -1) return true;
    if (was[v]) return false;
    was[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (dfs(p2[to])) {
            p1[v] = to;
            p2[to] = v;
            return true;
        }
    }
    return false;
}

void Solve() {
    idx.clear();
    idy.clear();
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        if (!idx.count(a)) idx[a] = c1++;
        if (!idy.count(b)) idy[b] = c2++;
        x[i] = idx[a];
        y[i] = idy[b];
        g[x[i]].push_back(y[i]);
    }
    for (int i = 0; i < n; ++i)
        p1[i] = p2[i] = -1;
    int c;
    do {
        c = 0;
        for (int i = 0; i < c1; ++i)
            was[i] = 0;
        for (int i = 0; i < c1; ++i)
            if (p1[i] == -1)
                c |= dfs(i);
    } while (c);
    int cnt = 0;
    for (int i = 0; i < c1; ++i)
        if (p1[i] != -1)
            ++cnt;
  //  cout << cnt << endl;
    cout << n - (c1 + c2 - cnt) << '\n';
}

int main() {
    int z;
    cin >> z;
    for (int i = 1; i <= z; ++i) {
        cout << "Case #" << i << ": ";
        Solve();
    }
    return 0;
}
