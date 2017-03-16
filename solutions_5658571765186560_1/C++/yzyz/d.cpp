#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int x,r,c;

bool ok() {
    if (r * c % x != 0) return 0;
    if (r > c) swap(r,c);
    if (x == 1) return 1;
    if (x == 2) return 1;
    if (x == 3) return r > 1;
    if (x == 4) return r > 2;
    if (x == 5) {
        if (r < 3) return 0;
        if (r > 3) return 1;
        return c >= 10;
    }
    if (x == 6) return r > 3;
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> x >> r >> c;
        cout << "Case #" << TC << ": ";
        cout << (ok() ? "GABRIEL" : "RICHARD") << '\n';
    }
}
