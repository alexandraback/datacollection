#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

int g[1001][1001];
int used[1001];

bool dfs(int v, int n) {
    if (used[v]) return true;
    used[v] = 1;
    for (int i = 1; i <= n; i++)
        if (g[v][i]) {
            if (dfs(i, n)) return true;
        }
    return false;
}

int main()
{
    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        int n, m, d;
        memset(g, 0, sizeof(g));
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> d;
                g[i][d] = 1;
            }
        }

        int i;
        for (i = 1; i <= n; i++) {
            memset(used, 0, sizeof(used));
            if (dfs(i, n)) break;
        }

        cout << "Case #" << test << ": " << (i > n ? "No" : "Yes") << endl;
    }
}
