#include <iostream>
using namespace std;

int solve() {
    int R, C, W;
    cin >> R >> C >> W;
    return (R - 1) * (C / W) + (C + W - 1) / W + W - 1;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}

