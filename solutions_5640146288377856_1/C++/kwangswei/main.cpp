#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int R, C, W;
int CANT;

int solve(int left) {
    if (C - left >= 2*W)
        return 1 + solve(left + W);

    if (C - left > W)
        return 1 + W;

    if (left + W == C)
        return W;

    return CANT;
}

int solve() {
    int r = solve(0);
    int other = r - W + 1;
    return (R-1)*other + r;
}


int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        cin >> R >> C >> W;
        printf("Case #%d: %d\n", i, solve());
    }

    return 0;
}
