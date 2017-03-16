#include <cstdio>

int solve(int R, int C, int W) {
    int res = 0;
    if (R > 1) {
        res += (R-1) * (C/W);
    }

    // last row
    int w1;
    if (C == W) {
        w1 = W;
    } else {
        w1 = W + 1;
    }
    res += w1 + (C-w1)/W;
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int R, C, W;
        scanf("%d", &R);
        scanf("%d", &C);
        scanf("%d", &W);
        int answer = solve(R, C, W);
        printf("Case #%d: %d\n", i, answer);
    }
    return 0;
}