#include <iostream>
using namespace std;

int T, X, R, C;

int min_width[7] = {0, 1, 1, 2, 3, 4, 4};

void solve_case(int t) {
    cout << "Case #" << t << ": ";
    cin >> X >> R >> C;
    if (R > C) {
        int tmp = R;
        R = C;
        C = tmp;
    }
    bool possible = false;
    if (X < 7
        && (R * C) % X == 0
        && C >= X
        && R >= min_width[X]){
        possible = true;

    }

    if (possible) {
        cout << "GABRIEL\n";
    } else {
        cout << "RICHARD\n";
    }
}

int main() {
    cin >> T;
    for (int i=1; i <= T; ++i) solve_case(i);
    return 0;
}
