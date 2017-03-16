#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int T, b, m;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        cout << "Case #" << tc + 1 << ": ";
        cin >> b >> m;
        if (1 << (b - 2) < m) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "POSSIBLE" << endl;
        if (1 << (b - 2) == m) {
            for (int i = 0; i < b; ++i) {
                for (int j = 0; j < b; ++j) {
                    if (i < j) cout << "1";
                    else cout << "0";
                }
                cout << endl;
            }
            continue;
        }
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < b - 1; ++j) {
                if (i < j) cout << "1";
                else cout << "0";
            }
            if (i == 0) cout << "0";
            else if ((m >> (i - 1)) & 1) cout << "1";
            else cout << "0";
            cout << endl;
        }

    }
}