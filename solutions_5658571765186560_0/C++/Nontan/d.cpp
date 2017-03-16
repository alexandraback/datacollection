#include <cstdio>
#include <algorithm>

using namespace std;

int X, R, C;

// If the rectangle (R x C) can be filled by the X-omino,
// this function will return true, otherwise false.

bool solve() {
    if ((R * C) % X != 0) { return false; }

    for (int i = 1; i <= X; i++) {
        int j = X - i + 1;
        if (min(R, C) < min(i, j) || max(R, C) < max(i, j)) {
            return false;
        }
    }

    if (min(R, C) == 2 && max(R, C) == 4 && X == 4) {
        return false;
    }

    return true;
}

int main() {
    int T;

    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%d%d", &X, &R, &C);
        printf("Case #%d: %s\n", i, (solve() ? "GABRIEL" : "RICHARD"));
    }
}

