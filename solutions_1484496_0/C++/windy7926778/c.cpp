#include <stdio.h>

int z[1<<20] = { 0 };

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int c = 0, o = 0, i = 0, n = 0, v[20] = { 0 }, j = 0, k = 0;
    scanf("%d", &c);
    for (o = 1; o <= c; o ++) {
        printf("Case #%d:\n", o);

        scanf("%d", &n);
        for (i = 0; i < n; i ++) {
            scanf("%d", v + i);
        }
        for (i = 1; i < (1 << n); i ++) {
            z[i] = 0;
            for (j = 0; j < n; j ++) {
                if (i & (1 <<j)) {
                    z[i] += v[j];
                }
            }
        }
        for (i = 1; i < (1 << n); i ++) {
            for (j = 1; j < (1 << n); j ++) {
                if (i & j) {
                    continue;
                }
                if (z[i] == z[j]) {
                    break;
                }
            }
            if (j < (1 << n)) {
                break;
            }
        }
        if (i < (1 << n)) {
            for (k = 0; k < n; k ++) {
                if (i & (1 << k)) {
                    printf("%d ", v[k]);
                }
            }
            printf("\n");
            for (k = 0; k < n; k ++) {
                if (j & (1 << k)) {
                    printf("%d ", v[k]);
                }
            }
            printf("\n");
        }
        else {
            printf("Impossible\n");
        }
    }
    return 0;
}

