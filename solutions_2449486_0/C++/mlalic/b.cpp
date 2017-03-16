#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int tn;
    cin >> tn;
    for (int tt = 1; tt <= tn; ++tt) {
        int n, m;
        cin >> n >> m;

        int lawn[100][100];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> lawn[i][j];
            }
        }

        int max_r[100];
        memset(max_r, 0, sizeof max_r);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (lawn[i][j] > max_r[i]) max_r[i] = lawn[i][j];
            }
        }

        int max_c[100];
        memset(max_c, 0, sizeof max_c);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (lawn[i][j] > max_c[j]) max_c[j] = lawn[i][j];
            }
        }

        bool fail = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!(lawn[i][j] == max_r[i] || lawn[i][j] == max_c[j])) {
                    fail = true;
                    break;
                }
            }
            if (fail) break;
        }

        cout << "Case #" << tt << ": ";
        if (!fail) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

