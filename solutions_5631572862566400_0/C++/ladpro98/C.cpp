#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

vector<int> a[N], r[N];
int n;

int deg[N];
int deepest[N];

void reset() {
    for (int i = 1; i <= n; ++i) a[i].clear(), r[i].clear();
}


bool was[N];

int dfs(int u, int &size) {
    was[u] = true;
    ++size;
    for (int v : a[u]) {
        if (was[v]) continue;
        if (deg[v] <= 1) continue;
        dfs(v, size);
    }
}

int dfsTree(int u, int p = 0) {
    int ans = 0;
    for (int v : r[u]) if (v != p && deg[v] == 0) {
        ans = max(ans, dfsTree(v, u) + 1);
    }
    return ans;
}

void dfsCycle(int u, vector<int> &C) {
    was[u] = true;
    C.push_back(u);
    for (int v : a[u]) if (deg[v] > 0 && !was[v]) {
        dfsCycle(v, C);
    }
}

int getPath(int u) {
    int first = 0, second = -N;
    for (int v : r[u]) if (deg[v] == 0) {
        if (first <= deepest[v] + 1)
            second = first, first = deepest[v] + 1;
        else if (second < deepest[v] + 1)
            second = deepest[v] + 1;
    }
    return first + second;
}

int solve() {
    queue<int> Q;
    memset(deg, 0, sizeof deg);
    for (int i = 1; i <= n; ++i) ++deg[a[i][0]];
    for (int i = 1; i <= n; ++i) if (deg[i] == 0) Q.push(i);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : a[u]) {
            --deg[v];
            if (deg[v] == 0) Q.push(v);
        }
    }

    memset(was, 0, sizeof was);
    int ans = 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    for (int i = 1; i <= n; ++i) if (deg[i] > 0 && !was[i]) {
        vector<int> C;
        dfsCycle(i, C);
        for (int v : C) deepest[v] = dfsTree(v);
        ans = max(ans, int(C.size()));
        if (C.size() == 2) {
            int more = deepest[C[0]] + deepest[C[1]];
            sum += more + 2;
        }
    }
    return max(ans, sum);
}

int main() {
    ios::sync_with_stdio(false);
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int ntest; cin >> ntest;
    for (int it = 1; it <= ntest; ++it) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int v; cin >> v;
            a[i].push_back(v);
            r[v].push_back(i);
            //cerr << "Edge " << i << ' ' << v << endl;
        }
        cout << "Case #" << it << ": " << solve() << endl;
        reset();
    }
    return 0;
}
