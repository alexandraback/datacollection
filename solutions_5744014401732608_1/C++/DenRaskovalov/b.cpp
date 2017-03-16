#include <iostream>

using namespace std;

int main() {
    int nT;
    cin >> nT;
    for (int t = 0; t < nT; ++t) {
        int64_t b;
        int64_t m;
        cin >> b >> m;
        cout << "Case #" << (t + 1) << ": ";
        int64_t max = 1ULL << (b - 2);
        if (b == 1) {
            max = 1;
        } else if (b == 2) {
            max = 1;
        }
        cerr << b << " " << max << endl;
        if (m <= max) {
            cout << "POSSIBLE" << endl;
            for (int i = 0; i < b; ++i) {
                for (int j = 0; j < b; ++j) {
                    bool has = false;
                    if (j > i) {
                        if (j + 1 == b) {
                            if (m == max) {
                                has = true;
                            } else {
                                if (i > 1) {
                                    has = 0 != (m & (1ULL << (i - 1)));
                                } else if (i == 0) {
                                    has = 0 != (m & 1);
                                }
                            }
                        } else {
                            has = true;
                        }
                    }
                    cout << ((has) ? "1" : "0");
                }
                cout << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
