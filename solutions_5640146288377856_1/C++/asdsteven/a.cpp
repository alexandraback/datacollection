#include <cstdio>

int solve() {
    int R, C, W;
    scanf("%d%d%d", &R, &C, &W);
    if (C % W == 0)
        return C / W * R + W - 1;
    return C / W * R + W;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        printf("Case #%d: %d\n", i, solve());
}
