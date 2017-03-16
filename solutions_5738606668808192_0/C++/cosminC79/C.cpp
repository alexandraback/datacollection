#include <cstdio>
const int NMAX = 35;
int N, J;
int tests, no[NMAX];

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);

    scanf("%d", &tests);
    scanf("%d%d", &N, &J);
    printf("Case #1:\n");

    no[1] = no[N / 2] = 1;
    for (int i = 0; i < J; i++) {
        for (int j = 1; j <= N / 2 - 2; j++) {
            if (i & (1 << (j - 1))) {
                no[1 + j] = 1;
            } else {
                no[1 + j] = 0;
            }
        }

        // meh ; can't be bothered to do it nicer
        for (int j = 1; j <= N / 2; j++) {
            printf("%d", no[j]);
        }
        for (int j = 1; j <= N / 2; j++) {
            printf("%d", no[j]);
        }

        for (int base = 2; base <= 10; base++) {
            long long divisor = 0;
            for (int j = 1; j <= N / 2; j++) {
                divisor = divisor * base + no[j];
            }
            printf(" %lld", divisor);
        }
        printf("\n");
    }
    return 0;
}