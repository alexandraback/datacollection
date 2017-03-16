// Google Code Jam 2015 Qualification ROund D
// Ominous Omino

#include <cstdio>
#include <algorithm>
using namespace std;

int T, X, R, C;

bool check() {
    if (R * C < X) return false;
    if (R * C == X) return X <= 2 ? true : false;
    if (R * C % X != 0) return false;
    if (X > max(R, C)) return false;
    if ((X + 1) / 2 > min(R, C)) return false;
    if ((X + 1) / 2 == min(R, C)) {
        int x = X - (X + 1) / 2; // x is the length of omino's long side
        for (int l = 1; l <= x / 2; l++) {
            int r = x - l;
            // l: the short side outter
            // r: the long side outter
            int s_short = min(R, C) - l;
            int s_long = min(R, C) - r;
            bool bo = false;
            for (int i = 1; i < max(R, C) - x; i++) {
                int a = s_short + i * min(R, C);
                int b = s_long + (max(R, C) - i) * min(R, C);
                if (a % X == 0 && b % X == 0) {
                    bo = true;
                    break;
                }
            }
            return bo;
        }
    }
    return true;
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &X, &R, &C);
        printf("Case #%d: %s\n", cas, check() ? "GABRIEL" : "RICHARD");
    }

    return 0;
}
