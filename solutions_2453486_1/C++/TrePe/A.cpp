#include <stdio.h>

int cases, kejs;
int i, j, k, m;
char a[4][5];

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%s", a[0]);
        scanf("%s", a[1]);
        scanf("%s", a[2]);
        scanf("%s", a[3]);
        for (i = 0; i < 4; i++) {
            k = 0; m = 0;
            for (j = 0; j < 4; j++) {
                k += (a[i][j] == 'X');
                m += (a[i][j] == 'T');
            }
            if (k + m == 4 && m <= 1) {
                printf("X won\n");
                break;
            }
        }
        if (i < 4) continue;
        for (i = 0; i < 4; i++) {
            k = 0; m = 0;
            for (j = 0; j < 4; j++) {
                k += (a[j][i] == 'X');
                m += (a[j][i] == 'T');
            }
            if (k + m == 4 && m <= 1) {
                printf("X won\n");
                break;
            }
        }
        if (i < 4) continue;
        k = 0; m = 0;
        for (i = 0; i < 4; i++) {
            k += (a[i][i] == 'X');
            m += (a[i][i] == 'T');
        }
        if (k + m == 4 && m <= 1) {
            printf("X won\n");
            continue;
        }
        k = 0; m = 0;
        for (i = 0; i < 4; i++) {
            k += (a[i][3-i] == 'X');
            m += (a[i][3-i] == 'T');
        }
        if (k + m == 4 && m <= 1) {
            printf("X won\n");
            continue;
        }

        for (i = 0; i < 4; i++) {
            k = 0; m = 0;
            for (j = 0; j < 4; j++) {
                k += (a[i][j] == 'O');
                m += (a[i][j] == 'T');
            }
            if (k + m == 4 && m <= 1) {
                printf("O won\n");
                break;
            }
        }
        if (i < 4) continue;
        for (i = 0; i < 4; i++) {
            k = 0; m = 0;
            for (j = 0; j < 4; j++) {
                k += (a[j][i] == 'O');
                m += (a[j][i] == 'T');
            }
            if (k + m == 4 && m <= 1) {
                printf("O won\n");
                break;
            }
        }
        if (i < 4) continue;
        k = 0; m = 0;
        for (i = 0; i < 4; i++) {
            k += (a[i][i] == 'O');
            m += (a[i][i] == 'T');
        }
        if (k + m == 4 && m <= 1) {
            printf("O won\n");
            continue;
        }
        k = 0; m = 0;
        for (i = 0; i < 4; i++) {
            k += (a[i][3-i] == 'O');
            m += (a[i][3-i] == 'T');
        }
        if (k + m == 4 && m <= 1) {
            printf("O won\n");
            continue;
        }

        bool ok = true;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (a[i][j] == '.') ok = false;
            }
        }
        if (ok) printf("Draw\n");
        else printf("Game has not completed\n");
    }
    return 0;
}
