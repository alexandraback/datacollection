#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

#define mp(a, b) make_pair(a, b)
#define all(a) a.begin(), a.end()

typedef long int int64;

bool more2k(int64 num, int64 deg) {
   int64 val = 1;
   while (deg--) {
       val *= 2;
       if (val >= num) return true;
   }
   return (val >= num);
}

int main() {
    int64 T;
    cin >> T;
    for (int64 t = 1; t <= T; ++t) {
        int64 b, m, buf;
        vector <int64> a;
        cin >> b >> m;
        a.resize(b - 1);
        cout << "Case #" << t << ":";
        if (!more2k(m, b - 2)) {
            cout << " IMPOSSIBLE\n";
            continue;
        } else {
            cout << " POSSIBLE\n";
        }
        buf = m;
        for (int64 i = 0; i < (int64)a.size(); ++i) {
            a[i] = buf % 2;
            buf /= 2;
        }
        if (a[b - 2]) {
            a[b - 2] = 0;
            cout << 0;
            for (int64 i = 1; i < b; ++i) {
                cout << 1;
            }
        } else {
            for (int64 i = b - 2; i >= 0; --i) {
                cout << a[i];
            }
            cout << 0;
        }
        cout << "\n";
        for (int64 j = 1; j < b; ++j) {
            cout << 0;
            for (int64 i = 1; i < b; ++i) {
                if (i > j) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
