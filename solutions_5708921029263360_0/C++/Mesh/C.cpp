#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int c1c2[12][12];
int c1c3[12][12];
int c2c3[12][12];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                c1c2[i][j] = c1c3[i][j] = c2c3[i][j] = 0;
            }
        }
        
        int j, p, s, k;
        cin >> j >> p >> s >> k;
        cout << "Case #" << t << ": ";
        if (j == 1 && p == 1 && s == 1) {
            cout << 1 << endl << "1 1 1" << endl;
            continue;
        } else {
            cout << j*p*k << endl;
            int tot = 0;
            int lasti3[12];
            for (int i = 0; i < 12; i++) lasti3[i] = i;
            for (int i1 = 1; i1 <= j; i1++) {
                for (int i2 = 1; i2 <= p; i2++) {
                    for (int count = 0; count < k; count++) {
                        cout << i1 << " " << i2 << " " << lasti3[i2] << endl;
                        tot++;
                        c1c2[i1][i2]++;
                        c1c3[i1][lasti3[i2]]++;
                        c2c3[i2][lasti3[i2]]++;
                        assert(c1c2[i1][i2] <= k);
                        assert(c1c3[i1][lasti3[i2]] <= k);
                        lasti3[i2]++;
                        if (lasti3[i2] == s+1) lasti3[i2] = 1;
                    }
                }
            }
            assert(tot == j*p*k);
        }
    }
}