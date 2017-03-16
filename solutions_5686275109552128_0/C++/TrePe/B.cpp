#include <stdio.h>

int N, kejs, n, i;
int res, cnt, q, max;
int a[1005];

int main() {
    scanf("%d", &N);
    for (kejs = 1; kejs <= N; kejs++) {
        printf("Case #%d: ", kejs);
        res = 0;
        scanf("%d", &n);
        max = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", a+i);
            if (max < a[i]) max = a[i];
        }
        res = -1;
        for (cnt = 1; cnt <= max; cnt++) {
            q = 0;
            for (i = 0; i < n; i++) {
                q += a[i] / cnt - (a[i] % cnt ? 0 : 1);
            }
            q += cnt;
            if (res == -1) res = q;
            if (res > q) res = q;
        }
        printf("%d\n", res);
    }
    return 0;
}
