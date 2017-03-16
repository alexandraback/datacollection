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

int min(int lhs, int rhs) {
    return lhs < rhs ? lhs : rhs;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int I = 1; I <= T; I++) {
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);

        printf("Case #%d:", I);

        if ((C == 1 && K > S) || (K > S * 2)) {
            printf(" IMPOSSIBLE\n");
            continue;
        }

        if (C == 1) {
            for (int i = 1; i <= K; i++) {
                printf(" %d", i);
            }
            printf("\n");
        } else {
            long long shift = 0;
            for (int i = 1; i < C; i++) {
                shift += pow(K, i);
            }
            for (int i = 0; i < K; i += 2) {
                printf(" %lld", shift * i + min(i + 2, K));
            }
            printf("\n");
        }
    }
}
