#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int X, R, C;

bool solve() {
    if (R > C) {
        swap(R, C);
    }
    if (R * C % X != 0) {
        return true;
    }
    if (X >= 7) {
        return true;
    }
    if (X >= R * 2 + 1) {
        return true;
    }

    if (X <= 3) {
        return false;
    }
    if (X == 4) {
        return R == 2;
    }
    if (X == 5) {
        return R == 3 && C == 5;
    }
    if (X == 6) {
        return R == 3;
    }

    return false; // dead code
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> X >> R >> C;
        
        string ans = solve() ? "RICHARD" : "GABRIEL";

        cout << "Case #" << testcase << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
