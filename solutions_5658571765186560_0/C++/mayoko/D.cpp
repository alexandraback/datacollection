#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;

// Richardが勝つ時true
bool solve(int X, int R, int C) {
    if (X >= 7) return true;
    if (X == 1) return false;
    if (X == 2) {
        if (R*C % 2 == 0) return false;
        return true;
    }
    if (X == 3) {
        if (R*C % 3 != 0) return true;
        if (R % 3 != 0) swap(R, C);
        // Rは3
        if (C == 1) return true;
        if (C == 2) return false;
        if (C == 3) return false;
        if (C == 4) return false;
    }
    if (X == 4) {
        if (R*C % 4 != 0) return true;
        if (R == 2 && C == 2) return true;
        if (R % 4 != 0) swap(R, C);
        if (C == 1) return true;
        if (C == 2) return true;
        if (C == 3) return false;
        if (C == 4) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int X, R, C;
        cin >> X >> R >> C;
        printf("Case #%d: ", t);
        if (solve(X, R, C)) printf("RICHARD\n");
        else printf("GABRIEL\n");
    }
    return 0;
}
