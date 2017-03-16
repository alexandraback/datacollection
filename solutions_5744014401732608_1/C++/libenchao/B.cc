#include <iostream>
#include <vector>
using namespace std;

#define B 64
bool grid[B][B];
long long buf[B];

void init(int b) {
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < b; ++j) {
            grid[i][j] = false;
        }
    }

    for (int i = 0; i < b; ++i) {
        for (int j = i+1; j < b-1; ++j) {
            grid[i][j] = true;
        }
    }
}

int main() {
    buf[0] = 1;
    buf[1] = 1;
    for (int i = 2; i < B; ++i) {
        buf[i] = 0;
        for (int j = 0; j < i; ++j) {
            buf[i] += buf[j];
        }
    }

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        long long b, m;
        cin >> b >> m;

        init(b);

        for (int i = b-2; i >= 0; --i) {
            if (m >= buf[i]) {
                grid[i][b-1] = true;
                m -= buf[i];
            }
        }

        if (m == 0) {
            cout << "POSSIBLE" << endl;
            for (int i = 0; i < b; ++i) {
                for (int j = 0; j < b; ++j) {
                    if (grid[i][j]) {
                        printf("1");
                    } else {
                        printf("0");
                    }
                }
                cout << endl;
            }
        } else {
             cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
