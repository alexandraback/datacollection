#include <cstdio>

int T;
int R, C, W;

int answer;

int solve(int C, int W) {
    if (C > 2 * W - 1) {
        return 1 + solve(C - W, W);
    } else if (C == W) {
        return W;
    } else {
        return W + 1;
    }
}

int main(void) {
    int t;

    // citirea datelor
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        scanf("%d %d %d", &R, &C, &W);

        // calcularea solutiei
        answer = R * solve(C, W);

        // afisarea solutiei
        printf("Case #%d: %d\n", t, answer);
    }
    return 0;
}
