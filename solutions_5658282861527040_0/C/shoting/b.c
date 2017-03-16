#include<stdio.h>


void main() {
    int t, i;
    int a, b, k;
    int m, n, j;

    scanf("%d", &t);

    for (i = 1 ; i <= t ; i++) {
        scanf("%d %d %d", &a, &b, &k);
        j = 0;
        for (m = 0 ;  m < a ; m++) {
            for (n = 0; n < b ; n++) {
                if ( (m & n) < k) {
                    j++;
                }
            }
        }

        printf("Case #%d: %d\n", i, j);
    }
}
