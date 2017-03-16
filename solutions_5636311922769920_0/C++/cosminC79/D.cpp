#include <cstdio>

int tests;
int K, C, S;

long long myPow(long long base, int exp) {
    long long result = 1;
    while (exp) {
        if (exp & 1) {
            result = result * base;
        }
        base = base * base;
        exp >>= 1;
    }

    return result;
}

int main() {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);

    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d:", test);
        scanf("%d%d%d", &K, &C, &S);

        long long v = myPow(K, C - 1);
        for (int i = 1; i <= K; i++) {
            printf(" %lld", v * (i - 1) + 1);
        }
        printf("\n");
    }
    return 0;
}