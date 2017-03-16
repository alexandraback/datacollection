#include <stdio.h>
#include <stdlib.h>

int mult(int a, int b) {
    int sign = 1;
    if (a < 0) {
        sign = -1;
        a = -a;
    }

    if (a == 1) return sign * b;
    if (a == b) return -sign;
    
    if (b == a - 1 || b == a + 2) sign = -sign;

    return sign * (9 - a - b);
}

int main () {
    int t, T;
    scanf("%d", &T);

    for (t = 1; t <= T; t++) {
        int L, X, s[10000];

        scanf("%d %d", &L, &X);
        if (X > 12 + X % 4) X = 12 + X % 4;

        int i, j;
        char c;

        for (i = 0; i < L; i++) {
            scanf(" %c", &c);
            s[i] = c - 'i' + 2;
        }

        int acc = 1;
        i = 0;
        j = 1;
        int next = 2;

        while (i < L) {
            acc = mult(acc, s[i++]);
            if (acc == next) {
                next++;
                acc = 1;
            }
            if (i == L && j < X) {
                i = 0;
                j++;
            }
        }

        if (acc == 1 && next == 5)
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }
    return 0;
}
