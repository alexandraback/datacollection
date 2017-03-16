#include <iostream>
#include <cmath>
using namespace std;

int a[100][100], b[100][100], n, m;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("b_out.txt", "w", stdout);
        
    int t;
    cin >> t;
    for (int task = 1; task <= t; task++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0;  j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            int max_ai = 0;
            for (int j = 0; j < m; j++) {
                max_ai = max(max_ai, a[i][j]);
            }
            for (int j = 0; j < m; j++) {
                b[i][j] = max_ai;
            }
        }
        bool c = true;
        for (int j = 0; j < m; j++) {
            int max_aj = 0;
            for (int i = 0; i < n; i++) {
                max_aj = max(max_aj, a[i][j]);
            }
            for (int i = 0; i < n; i++) {
                b[i][j] = min(b[i][j], max_aj);
                if (b[i][j] != a[i][j]) {
                    c = false;
                    break;
                }
            }
            if (!c) {
                break;
            }
        }
        cout << "Case #" << task <<": " << (c ? "YES" : "NO") << endl;
    }
}
