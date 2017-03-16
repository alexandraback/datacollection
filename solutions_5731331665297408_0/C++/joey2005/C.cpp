#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

const int maxn = 111;

string code[maxn];
bool vis[maxn], forbid[maxn], cache[maxn];
bool f[maxn][maxn];
bool g[maxn][maxn];
int n, m;

bool cmp(int a, int b) {
    return code[a] < code[b];
}

bool check(const vector<int> &path) {
    for (int i = 0; i < n; ++i) {
        if (!forbid[i]) {
            f[i][i] = true;
            for (int j = 0; j < n; ++j) {
                if (!forbid[j]) {
                    f[i][j] = g[i][j];
                } else {
                    f[i][j] = false;
                }
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (f[i][k] && f[k][j]) {
                    f[i][j] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            bool ok = false;
            for (int j = 0; j < path.size(); ++j) {
                if (f[path[j]][i]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> code[i];
    }
    memset(g, false, sizeof g);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x][y] = g[y][x] = true;
    }
    int st = 0;
    for (int i = 0; i < n; ++i) {
        if (code[i] < code[st]) {
            st = i;
        }
    }
    memset(vis, false, sizeof vis);
    memset(forbid, false, sizeof forbid);
    vector<int> order, path;
    order.push_back(st);
    path.push_back(st);
    vis[st] = true;
    while (order.size() < n) {
       vector<int> backup = path;
        memcpy(cache, forbid, sizeof cache);
        while (path.size() > 1) {
            int x = path.back();
            forbid[x] = true;
            path.pop_back();
            if (!check(path)) {
                forbid[x] = false;
                path.push_back(x);
                break;
            }
        }
        vector<int> level(n);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                level[i] = -1;
                for (int j = (int)path.size() - 1; j < backup.size(); ++j) {
                    if (g[backup[j]][i]) {
                        level[i] = j;
                        break;
                    }
                }
            }
        }
        int to = -1;
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && level[i] != -1) {
                if (to == -1 || code[i] < code[to]) {
                    to = i;
                }
            }
        }
        vis[to] = true;
        order.push_back(to);
        path = backup;
        memcpy(forbid, cache, sizeof forbid);
        while ((int)path.size() - 1 != level[to]) {
            int x = path.back();
            forbid[x] = true;
            path.pop_back();
        }
        path.push_back(to);
    }
    string res = "";
    for (int i = 0; i < order.size(); ++i) {
        res += code[order[i]];
    }
    cout << res << endl;
    assert(res.size() % 5 == 0 && res.size() / 5 == n);
}

int main() {
    int testCount;
    cin >> testCount;
    for (int testId = 1; testId <= testCount; ++testId) {
        printf("Case #%d: ", testId);
        solve();
    }
}
