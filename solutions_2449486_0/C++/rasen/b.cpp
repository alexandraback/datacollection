#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int k = 1; k <= n; ++k) {
        int x[10][10];
        int N,M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> x[i][j];
            }
        }

        int maxInRow[10] = {};
        int maxInCol[10] = {};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                maxInRow[i] = max(maxInRow[i], x[i][j]);
                maxInCol[j] = max(maxInCol[j], x[i][j]);
            }
        }

        bool ok = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (x[i][j] < maxInRow[i] &&
                    x[i][j] < maxInCol[j]) {
                    ok = false;
                }
            }
        }

        cout << "Case #" << k << ": ";
        cout << (ok ? "YES" : "NO");
        cout << "\n";
    }
}
