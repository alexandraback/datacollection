#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int f[100][100];


int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t, e, r, n, ans, a;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        cin >> e >> r >> n;
        memset(f, 0, sizeof(f));
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            for (int j = e; j >= 0; --j) {
                if (j >= r) f[i][j] = max(f[i][j], f[i-1][j-r]);
                if (e-j >= 1) f[i][j] = max(f[i][j], f[i][j+1] + a);
                if (f[i][j] > ans) ans = f[i][j];
            }
        }
        cout << ans << endl;
    }
    
    
    
    return 0;    
}
