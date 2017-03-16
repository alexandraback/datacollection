#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <utility>

using namespace std;

int T;
unsigned long long r, v, b;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> r >> v;
        b = 2 * r + 1;
        unsigned long long L, R, m;
        for (L = 1, R = v, m = (L + R) >> 1; L < R; m = (L + R) >> 1) {
            ((2 * (m - 1))<= double(v) / m - b) ? L = m + 1 : R = m;
        }
        cout << "Case #" << t << ": " << L - 1 << endl;
    }
    return 0;
}

