#include <bits/stdc++.h>

using namespace std;

vector<int> g;
vector<int> col;
vector<vector<int>> rev_g;
int ans, c;
map<int, int> mp;

int DFS1(int v, int parent) {
    col[v] = c;
    int ans = 0;
    for (int to : rev_g[v]) {
        if (to != parent) {
            ans = max(ans, DFS1(to, v));
        }
    }
    return ans + 1;
}

int DFS2(int v, int step = 0) {
    col[v] = c;
    mp[v] = step;
    int to = g[v];
    if (col[to] == -1) {
        int k = DFS2(to, step + 1);
        mp.erase(v);
        return k;
    } else if (col[v] != col[to]) {
        mp.erase(v);
        return 0;
    } else {
        int k = mp[v] - mp[to] + 1;
        mp.erase(v);
        return k;
    }
}

void clear() {
    g.clear();
    rev_g.clear();
    col.clear();
    mp.clear();
    ans = c = 0;
}

int Solve() {
    clear();
    size_t n;
    cin >> n;
    g.assign(n, -1);
    rev_g.resize(n);
    col.assign(n, -1);
    vector<pair<int, int>> pr;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        --g[i];
        rev_g[g[i]].push_back(i);
        if (g[g[i]] == i) {
            pr.push_back({i, g[i]});
        }
    }
    for (int i = 0; i < pr.size(); ++i) {
        ans += DFS1(pr[i].first, pr[i].second);
        ans += DFS1(pr[i].second, pr[i].first);
        ++c;
    }
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            ans = max(ans, DFS2(i));
            ++c;
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    size_t t;
    cin >> t;
    for (size_t i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << Solve() << endl;
    }
    return 0;
}
