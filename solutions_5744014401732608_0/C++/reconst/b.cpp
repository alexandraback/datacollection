#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <array>

using namespace std;

int n, m;

void check(vector<vector<int>> &g)
{
    // cerr << "check" << " ";
    vector<int> v(n, 0);
    v[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            v[j] += (g[i][j] ? v[i] : 0);
        }
    }
    // cerr << v[n - 1] << endl;
    if (v[n - 1] == m) {
        cout << "POSSIBLE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
        g.resize(0);
    } else {
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << g[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
}

void gen(int v, int w, vector<vector<int>> &g)
{
    // cerr << v << " " << w << endl;
    if (g.size() == 0) {
        return;
    }
    if (v == n - 1) {
        check(g);
        return;
    }
    g[v][w] = 0;
    if (w >= n - 1) {
        gen(v + 1, v + 2, g);
    } else {
        gen(v, w + 1, g);
    }
    if (g.size() == 0) {
        return;
    }
    g[v][w] = 1;
    if (w >= n - 1) {
        gen(v + 1, v + 2, g);
    } else {
        gen(v, w + 1, g);
    }
}

void solve()
{
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, 0));
    gen(0, 1, g);
    if (g.size() != 0) {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}