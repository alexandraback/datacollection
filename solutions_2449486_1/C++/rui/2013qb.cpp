#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int t, n, m, a[102][102];
int check() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 100)
                continue;
            int m1 = 1, m2 = 1;
            for (int k = 0; k < m; ++k)
                if (a[i][k] > a[i][j]) {
                    m1 = 0;
                    break;
                }
            for (int k = 0; k < n; ++k)
                if (a[k][j] > a[i][j]) {
                    m2 = 0;
                    break;
                }
            if (!m1 && !m2)
                return 0;
        }
    return 1;
}
int main() {
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        cout << "Case #" << tt << ": ";
        if (check())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
