#include <cstdio>


using namespace std;


int _T, R, C, M, diff;
char grid[100][100];
int lR, lC, cAm;

void reset() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            grid[i][j] = '*';
        }
    }
    lR = lC = cAm = 0;
    return;
}

int main() {
    freopen ("q3.in", "r", stdin);
    freopen ("q3.out", "w", stdout);
    scanf ("%d", &_T);
    for (int _z = 1; _z <= _T; _z++) {
        printf ("Case #%d:\n", _z);
        reset();
        scanf ("%d %d %d", &R, &C, &M);
        diff = (R*C)-M;
        //Corner cases: YAY
        if (M == 0) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (i == 0 && j == 0) printf ("c");
                    else printf (".");
                }
                printf ("\n");
            }
            continue;
        }
        if (diff == 1) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (i == 0 && j == 0) printf ("c");
                    else printf ("*");
                }
                printf ("\n");
            }
            continue;
        }
        if (R == 1) {
            printf ("c");
            for (int i = 1; i < C; i++) {
                if (i < diff) printf (".");
                else printf ("*");
            }
            printf ("\n");
            continue;
        }
        if (C == 1) {
            printf ("c\n");
            for (int i = 1; i < R; i++) {
                if (i < diff) printf (".\n");
                else printf ("*\n");
            }
            continue;
        }      
        if (diff == 2 || diff == 3 || diff == 5 || diff == 7) {
            printf ("Impossible\n");
            continue;
        }
        if (R == 2) {
            if (diff % 2 == 1) printf ("Impossible\n");
            else {
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        if (i == 0 && j == 0) {
                            printf ("c");
                        } else {
                            if (j < diff/2) printf (".");
                            else printf ("*");
                        }
                    }
                    printf ("\n");
                }
            }
            continue;
        }
        if (C == 2) {
            if (diff % 2 == 1) printf ("Impossible\n");
            else {
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        if (i == 0 && j == 0) {
                            printf ("c");
                        } else {
                            if (i < diff/2) printf (".");
                            else printf ("*");
                        }
                    }
                    printf ("\n");
                }
            }
            continue;
        }
        //Every other case: diff should be >= 8 by now:
        if (diff <= 3*R) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (j < 3 && cAm < diff) {
                        grid[i][j] = '.';
                        cAm++;
                    }
                }
            }
            if (diff % 3 == 1) {
                lR = diff/3;
                grid[lR][1] = '.';
                grid[lR-1][2] = '*';
            }
        } else {
            lC = diff/R+1;
            lR = diff%R;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (j < lC-1) {
                        grid[i][j] = '.';
                    }
                    if (j == lC-1 && i < lR) {
                        grid[i][j] = '.';
                    }
                }
            }
            if (lR == 1) {
                grid[lR][lC-1] = '.';
                grid[R-1][lC-2] = '*';
            }
        }
        grid[0][0] = 'c';
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                printf ("%c", grid[i][j]);
            }
            printf ("\n");
        }
    }
    return 0;
}


