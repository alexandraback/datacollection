#include <stdio.h>
#include <string.h>

int test;
int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d", &test);
    for (int t = 1; t <= test; t++) {
        printf("Case #%d:\n", t);
        int j, n;
        scanf("%d%d", &j, &n);
        for (int i = 0; n > 0; i++, n--) {
            printf("11");
            for (int k = 0; k < (j - 4) / 2; k++)
                if (i & (1 << k)) {
                    printf("11");
                } else {
                    printf("00");
                }
            printf("11");
            for (int k = 2; k < 11; k++) { printf(" %d", k + 1); }
            printf("\n");
        }
    }
    return 0;
}
