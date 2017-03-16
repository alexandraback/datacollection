#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Why are you reading this?

void solve()
{
    cout << endl;
    int r, c, m;
    cin >> r >> c >> m;
    int l = r * c - m;
    vector<vector<char> > g(r, vector<char>(c, '*'));
    if (l == 1) {
    } else if (r == 1) {
        for (int i = 0; i < l; ++i) g[0][i] = '.';
    } else if (c == 1) {
        for (int i = 0; i < l; ++i) g[i][0] = '.';
    } else {
        bool f = false;
        for (int x = 2; x <= r && !f; ++x) {
            if (c * x >= l && l / x > 1) {
                if (l % x != 1 || (l / x > 2 && x > 2)) {
                    f = true;
                    for (int j = 0; j < l / x; ++j) for (int i = 0; i < x; ++i) g[i][j] = '.';
                    for (int i = 0; i < l % x; ++i) g[i][l / x] = '.';
                    
                    if (l % x == 1) {
                        g[l % x][l / x] = '.';
                        g[x - 1][l / x - 1] = '*';
                    }
                }
            }
        }
        for (int x = 2; x <= c && !f; ++x) {
            if (r * x >= l && l / x > 1) {
                if (l % x != 1 || (l / x > 2 && x > 2)) {
                    f = true;
                    for (int j = 0; j < l / x; ++j) for (int i = 0; i < x; ++i) g[j][i] = '.';
                    for (int i = 0; i < l % x; ++i) g[l / x][i] = '.';
                    
                    if (l % x == 1) {
                        g[l / x][l % x] = '.';
                        g[l / x - 1][x - 1] = '*';
                    }
                }
            }
        }
        if (!f) {
            cout << "Impossible" << endl;
            return;
        }
    }
    
    g[0][0] = 'c';
    for (auto& v: g) {
        for (char z: v) cout << z;
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    cout.flush();
    return 0;
}
