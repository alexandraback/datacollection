#include <iostream>
#include <vector>

#define long long long

using namespace std;

int main() {
    long t;
    cin >> t;

    for (long q = 1; q <= t; ++q) {
        long b, m;
        cin >> b >> m;

        vector<vector<bool>> slides(b, vector<bool>(b, false));
        for (long i = 1; i < b; ++i) {
            for (long j = i + 1; j < b; ++j) {
                slides[i][j] = true;
            }
        }

        slides[0][b - 1] = true;
        m -= 1;
        for (long i = b - 2; i >= 1; --i) {
            if (m % 2 == 1) slides[0][i] = true;
            m /= 2;
        }

        cout << "Case #" << q << ": ";
        if (m > 0) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            for (long i = 0; i < b; ++i) {
                for (long j = 0; j < b; ++j) {
                    if (slides[i][j]) cout << "1";
                    else cout << "0";
                }
                cout << endl;
            }
        }
    }
}
