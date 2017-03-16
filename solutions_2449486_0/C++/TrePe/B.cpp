#include <stdio.h>

int cases, kejs;
int R, C;
int i, j, k, m;
int a[100][100];
int b[100][100];

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%d%d", &R, &C);
        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                scanf("%d", &a[i][j]);
                b[i][j] = 100;
            }
        }
        for (i = 0; i < R; i++) {
            m = -1;
            for (j = 0; j < C; j++) {
                if (a[i][j] > m) m = a[i][j];
            }
            for (j = 0; j < C; j++) {
                if (b[i][j] > m) b[i][j] = m;
            }
        }
        for (j = 0; j < C; j++) {
            m = -1;
            for (i = 0; i < R; i++) {
                if (a[i][j] > m) m = a[i][j];
            }
            for (i = 0; i < R; i++) {
                if (b[i][j] > m) b[i][j] = m;
            }
        }
        bool ok = true;
        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                if (a[i][j] != b[i][j]) ok = false;
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
