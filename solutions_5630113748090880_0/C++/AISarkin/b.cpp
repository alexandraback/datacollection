#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

#define TASKNAME ""

void solve(int test_number);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i);
    }
}

const int MAX_N = 105;

int heights[MAX_N][MAX_N], rows[MAX_N], columns[MAX_N], label[MAX_N];
vector<int> e[MAX_N];
bool used[MAX_N];

void dfs(int u, int l) {
    if (label[u] >= 0) {
        return;
    }
    label[u] = l;
    for (int v : e[u]) {
        if (label[v] < 0) {
            dfs(v, 1 - l);
        }
    }
}

void solve(int test_number) {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n - 1; i++) {
        e[i].clear();
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            cin >> heights[i][j];
        }
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < n; k++) {
                if (heights[i][k] == heights[j][k]) {
                    e[i].push_back(j);
                    e[j].push_back(i);
                    break;
                }
            }
        }
    }
    memset(label, -1, sizeof(label));
    memset(rows, -1, sizeof(rows));
    memset(columns, -1, sizeof(columns));
    memset(used, false, sizeof(used));
    int ans[MAX_N][MAX_N];
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; i++) {
        int mn = MAX_N * MAX_N;
        for (int j = 0; j < 2 * n - 1; j++) {
            if (used[j]) {
                continue;
            }
            for (int k = i; k < n; k++) {
                mn = min(mn, heights[j][k]);
            }
        }
        vector<int> q;
        for (int j = 0; j < 2 * n - 1; j++) {
            if (heights[j][i] == mn) {
                q.push_back(j);
                used[j] = true;
            }
        }
        if (q.size() == 1) {
            int lb = 0;
            for (int j = 0; j < n; j++) {
                if (ans[i][j] != heights[q[0]][j]) {
                    lb = 1;
                    break;
                }
            }
            if (label[q[0]] < 0) {
                dfs(q[0], lb);
                if (lb) {
                    columns[i] = q[0];
                } else {
                    rows[i] = q[0];
                }
            }
        } else {
            if (label[q[0]] >= 0) {
                dfs(q[1], 1 - label[q[0]]);
            }
            if (label[q[1]] >= 0) {
                dfs(q[0], 1 - label[q[1]]);
            }
            if (label[q[0]] < 0) {
                int lb = 0;
                for (int j = 0; j < n; j++) {
                    if (ans[i][j] >= 0 && ans[i][j] != heights[q[0]][j]) {
                        lb = 1;
                        break;
                    }
                }
                for (int j = 0; j < n; j++) {
                    if (ans[j][i] >= 0 && ans[j][i] != heights[q[1]][j]) {
                        lb = 0;
                    }
                }
                dfs(q[0], lb);
                dfs(q[1], 1 - lb);
            }
            if (label[q[0]] == 0) {
                rows[i] = q[0];
                columns[i] = q[1];
                for (int j = 0; j < n; j++) {
                    ans[i][j] = heights[rows[i]][j];
                    ans[j][i] = heights[columns[i]][j];
                }
            } else {
                rows[i] = q[1];
                columns[i] = q[0];
                for (int j = 0; j < n; j++) {
                    ans[i][j] = heights[columns[i]][j];
                    ans[j][i] = heights[rows[i]][j];
                }
            }
        }
    }
    cout << "Case #" << test_number + 1 << ": ";
    for (int i = 0; i < n; i++) {
        if (rows[i] < 0) {
            for (int j = 0; j < n; j++) {
                cout << heights[columns[j]][i] << " ";
            }
            cout << endl;
            break;
        } if (columns[i] < 0) {
            for (int j = 0; j < n; j++) {
                cout << heights[rows[j]][i] << " ";
            }
            cout << endl;
            break;
        }
    }
}
