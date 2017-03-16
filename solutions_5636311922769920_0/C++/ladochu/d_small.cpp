#include <cstdio>

long long pow(long long base, long long exp)
{
    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return base;
    } else {
        long long sq = pow(base, exp / 2);
        return sq * sq * pow(base, exp % 2);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int I = 1; I <= T; I++) {
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);

        printf("Case #%d:", I);
        long long KToCMinusOne = pow(K, C - 1);
        for (int i = 0; i < S; i++) {
            printf(" %lld", i * KToCMinusOne + 1);
        }
        printf("\n");
    }
}
