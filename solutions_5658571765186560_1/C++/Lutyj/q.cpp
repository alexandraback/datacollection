#include <algorithm>
#include <cstdio>
using namespace std;

int X, R, C;

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        printf("Case #%d: ", t + 1);

        scanf("%d%d%d", &X, &R, &C);
        if (R > C) swap(R, C);

        if (X >= 7 || (R * C) % X != 0) { printf("RICHARD\n"); continue; }
        if (X == 1 || X == 2) { printf("GABRIEL\n");  continue; }

        if (R == 1) { printf("RICHARD\n"); continue; } // V-shape
        if (C == 2) { printf("RICHARD\n"); continue; } // I-shape
        if (X == 3) { printf("GABRIEL\n"); continue; }

        if (R == 2) { printf("RICHARD\n"); continue; } // T-shape
        if (C == 3) { printf("RICHARD\n"); continue; } // I-shape
        if (X == 4) { printf("GABRIEL\n"); continue; }

        if (R == 3) { printf("RICHARD\n"); continue; } // W-shape
        if (C == 4) { printf("RICHARD\n"); continue; } // I-shape
        if (X == 5) { printf("GABRIEL\n"); continue; }

        if (C == 5) { printf("RICHARD\n"); continue; } // I-shape
        if (X == 6) { printf("GABRIEL\n"); continue; }
    }

    return 0;
}
