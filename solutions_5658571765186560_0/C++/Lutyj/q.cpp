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
        if (R == 1) { printf("RICHARD\n"); continue; }
        if (X == 3) { printf("GABRIEL\n"); continue; }

        if (C <= 3) { printf("RICHARD\n"); continue; }
        if (R == 2) { printf("RICHARD\n"); continue; }
        if (X == 4) { printf("GABRIEL\n"); continue; }

        // 3 <= R, 4 <= C, X <= 6, (R * C) % X = 0
    }

    return 0;
}
