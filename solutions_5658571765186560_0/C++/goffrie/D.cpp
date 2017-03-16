#include <iostream>
#include <cassert>

using namespace std;

bool tc() {
    int X, R, C;
    cin >> X >> R >> C;
    if (X > R && X > C) return true;
    if (R*C % X != 0) return true;
    if (X >= 7) return true;
    if (X == 1) return false;
    if (X == 2) return false;
    if (X == 3) {
        if (R < 2 || C < 2) return true;
        else return false;
    }
    if (X == 4) {
        if (R <= 2 || C <= 2) return true;
        else return false;
    }
    if (X == 5) {
    }
    if (X == 6) {
    }
}

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case #" << cas << ": " << (tc()?"RICHARD":"GABRIEL") << endl;
    }
}

