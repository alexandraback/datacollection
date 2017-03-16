#include <iostream>
using namespace std;

int solve(int C, int W) {
    if (W == C)
        return W;
    if (C <= 2 * W)
        return W + 1;
    return 1 + solve(C - W, W);
}

int solve() {
    int R, C, W;
    cin >> R >> C >> W;
    if (R == 1)
        return solve(C, W);

    return -1;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}

