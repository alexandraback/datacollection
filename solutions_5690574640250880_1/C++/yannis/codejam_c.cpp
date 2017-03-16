#include <stdio.h>
#include <stdlib.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, j, t, T, R, C, M, r, c, m, mm, n;

    scanf("%d", &T);
    for (t=1; t<=T; ++t) {
        scanf("%d %d %d", &R, &C, &M);
        r = 0; c = 0; m = 0;
        printf("Case #%d:\n", t);

        if ( M == R*C-1 && M != 0 ) {
            for (i=1; i<=R; ++i) {
                for (j=1; j<=C; ++j) {
                    if ( i == R && j == C ) printf("c");
                    else printf("*");
                }
                printf("\n");
            }
            continue;
        }

        if ( R == 1 || C == 1 ) {
            for (i=1; i<=R; ++i) {
                for (j=1; j<=C; ++j) {
                    if ( i == R && j == C ) { printf("c"); }
                    else if ( m < M ) { printf("*"); m++; }
                    else { printf("."); }
                }
                printf("\n");
            }
            continue;
        }

        if ( M <= (R-2)*(C-2) ) {
            for (i=1; i<=R-2; ++i) {
                for (j=1; j<=C-2; ++j) {
                    if ( m < M ) { printf("*"); m++; }
                    else { printf("."); }
                }
                printf("..\n");
            }
            for (i=1; i<=2; ++i) {
                for (j=1; j<=C; ++j) {
                    if ( i == 2 && j == C ) printf("c");
                    else printf(".");
                }
                printf("\n");
            }
            continue;
        }

        m = (R-2)*(C-2);
        if ( (M-m)%2 == 0 ) {
            n = (M-m)/2;
            if ( n > R-2 ) { r = R-2; c = n-r; }
            else { r = n; c = 0; }
            if ( c > C-2 ) { printf("Impossible\n"); continue; }
            for (i=1; i<=R-2; ++i) {
                for (j=1; j<=C-2; ++j) {
                    printf("*");
                }
                if ( i <= r ) { printf("**\n"); }
                else { printf("..\n"); }
            }
            for (i=1; i<=2; ++i) {
                for (j=1; j<=C; ++j) {
                    if ( i == 2 && j == C ) printf("c");
                    else if ( j <= c ) { printf("*"); }
                    else printf(".");
                }
                printf("\n");
            }
        }
        else {
            if ( m == 0 ) { printf("Impossible\n"); continue; }
            m--;
            n = (M-m)/2;
            if ( n > R-3 ) { r = R-3; c = n-r; }
            else { r = n; c = 0; }
            if ( c > C-3 ) { printf("Impossible\n"); continue; }
            for (i=1; i<=R-2; ++i) {
                for (j=1; j<=C-2; ++j) {
                    if ( i == R-2 && j == C-2 ) printf(".");
                    else printf("*");
                }
                if ( i <= r ) { printf("**\n"); }
                else { printf("..\n"); }
            }
            for (i=1; i<=2; ++i) {
                for (j=1; j<=C; ++j) {
                    if ( i == 2 && j == C ) printf("c");
                    else if ( j <= c ) { printf("*"); }
                    else printf(".");
                }
                printf("\n");
            }
        }
    }

    return 0;
}
