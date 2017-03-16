#include <stdio.h>
#include <stdlib.h>
#define MAX 111

// -1 %0 * (avg > 0)
// -1 %1
// -1 %2
// -2 %2 *

int cmp(int *x, int *y) {
    return *y - *x;
}

int main() {
    int t, T, N, S, p, i, avg, r, count, a[MAX];

    scanf("%d", &T);

    for(t = 1; t <= T; t++) {
        count = 0;

        scanf("%d %d %d", &N, &S, &p);

        for(i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }

        qsort(a, N, sizeof(int), cmp);

        for(i = 0; i < N; i++) {
            avg = a[i] / 3;
            r = a[i] % 3;
            //printf("%d,%d,%d ", a[i],avg,r);

            if(avg >= p || (avg == p - 1 && r)) {
                ++count;
            } else if(S && (avg && avg == p - 1 || avg == p - 2 && r == 2)) {
                --S;
                ++count;
            } else {
                break;
            }
        }

        printf("Case #%d: %d\n", t, count);
    }
}
