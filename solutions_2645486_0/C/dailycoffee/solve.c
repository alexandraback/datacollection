#include <stdio.h>

int act[10];
int solve(int Ei, int E, int R, int *A, int NA) {
    if (!NA) {
        return 0;
    }
    int *RA = A + 1;
    int payoff = 0;
    for (int i = 0; i <= E; ++i) {
        int newE = E - i + R;
        if (newE > Ei) {
            newE = Ei;
        }
        int p = i * A[0] + solve(Ei, newE, R, RA, NA - 1);
        if (p > payoff) {
            payoff = p;
        }
    }
    return payoff;
}

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        int E, R, A;
        scanf("%d %d %d\n", &E, &R, &A);
        for (int j = 0; j < A; ++j) {
            scanf("%d", act + j);
        }
        scanf("\n");
        printf("Case #%d: %d\n", i + 1, solve(E, E, R, act, A));
    }
}
