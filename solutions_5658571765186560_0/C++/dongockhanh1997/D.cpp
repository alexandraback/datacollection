#include <bits/stdc++.h>
using namespace std;

const string LOSE = "RICHARD";
const string WIN = "GABRIEL";

string solve(int x, int r, int c) {
    if (r > c) swap(r, c);
    if (x >= 7) return LOSE;
    for (int side = 1; side <= x - side + 1; ++side) if (!(side <= r && x - side + 1 <= c)) return LOSE;
    return r * c % x == 0 ? WIN : LOSE;
}

int main() {
    ios::sync_with_stdio(false);
    int numTests; cin >> numTests;
    for (int test = 0; test < numTests; ++test) {
        int x; cin >> x;
        int r; cin >> r;
        int c; cin >> c;
        cout << "Case #" << test + 1 << ": " << solve(x, r, c) << "\n";
    }
    return 0;
}
