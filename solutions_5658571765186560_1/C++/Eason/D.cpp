#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int X, R, C;

bool solve() {
    if (X == 1) return true;
    if ((R * C) % X != 0) return false;
    if (R * C == X && X > 2) return false;
    if (min(R, C) < (X - 1) / 2 + 1) return false;
    if (X >= 7) return false;
    if (X == 4 && min(C, R) <= 2) return false;
    if (X == 6 && min(C, R) <= 3) return false;
    if (X == 5 && min(C, R) == 3) {
        int l = max(C, R);
        if (l >= 10) return true;
        else return false;
    }
    return true;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> X >> R >> C;
        cout << "Case #" << t << ": ";
        if (solve()) {
            cout << "GABRIEL" << endl;
        } else {
            cout << "RICHARD" << endl;
        }
    }
    return 0;
}
