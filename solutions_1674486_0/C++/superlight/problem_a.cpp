#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> g[1000];
bool used[1000];

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) 
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

bool go(int v) {
    if (used[v]) 
        return true;
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        if (go(g[v][i]))
            return true;
    }
    return false;
}

bool solvecase() {
    int n;
    cin >> n;
    int M = 0;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        used[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            --x;
            g[i].push_back(x);
            //g[x].push_back(i);

        }
        M += m;
    }
    /*int K = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++K;
            dfs(i);
        }
    }*/
    //cout << M << "\t" << n << "\t" << K << endl;
    //return (M != n - K);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            used[j] = false;
        if (go(i))
            return true;
    }
    return false;
}

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        if (solvecase())
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
