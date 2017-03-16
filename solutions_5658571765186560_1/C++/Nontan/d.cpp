#include <cstdio>
#include <algorithm>

using namespace std;

int X, R, C;

// If the rectangle (R x C) can be filled by the X-omino,
// this function will return true, otherwise false.

bool solve() {
    int l = max(R, C);
    int s = min(R, C);

    if (X >= 7) { return false; }

    if ((R * C) % X != 0) { return false; }

    for (int i = 1; i <= X; i++) {
        int j = X - i + 1;
        if (s < min(i, j) || l < max(i, j)) {
            return false;
        }
    }

    if (s == 2 && l == 4 && X == 4) { return false; }
    if (s == 3 && l == 6 && X == 6) { return false; }

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

