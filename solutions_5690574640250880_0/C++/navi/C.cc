#include <cstdio>
#include <cstring>

int T, R, C, M, W;
char ans[50][51];

bool gao() {
    if (M == 0) {
        memset(ans, '.', sizeof(ans));
        return true;
    }

    memset(ans, '*', sizeof(ans));
    if (W == 1) {
        return true;
    } else if (R == 1 || C == 1) {
        for (int i = 0; i < R && i < W; ++i) {
            for (int j = 0; j < C && j < W; ++j) {
                ans[i][j] = '.';
            }
        }
        return true;
    } else if (R == 2 || C == 2) {
        if (W % 2 == 1 || W == 2) {
            return false;
        } else {
            for (int i = 0; i < W / 2; ++i) {
                ans[0][i] = '.';
                ans[1][i] = '.';
            }
            return true;
        }
    } else if (W == 2 || W == 3 || M == R * C - 5 || M == R * C - 7) {
        return false;
    } else {
        ans[0][0] = '.';
        ans[0][1] = '.';
        ans[1][0] = '.';
        ans[1][1] = '.';
        W -= 4;
        for (int i = 2; (i < R || i < C) && W >= 2; ++i) {
            if (W >= 2 && i < R) {
                ans[i][0] = '.';
                ans[i][1] = '.';
                W -= 2;
            }
            if (W >= 2 && i < C) {
                ans[0][i] = '.';
                ans[1][i] = '.';
                W -= 2;
            }
        }
        for (int i = 4; W > 0; ++i) {
            for (int j = 2; i - j >= 2; ++j) {
                if (j < R && i - j < C && W > 0) {
                    ans[j][i - j] = '.';
                    --W;
                }
            }
        }
        return true;
    }
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        scanf("%d%d%d", &R, &C, &M);
        W = R * C - M;
        printf("Case #%d:\n", caseNum);
        if (gao()) {
            ans[0][0] = 'c';
            for (int i = 0; i < R; ++i) {
                ans[i][C] = '\0';
                puts(ans[i]);
            }
        } else {
            puts("Impossible");
        }
    }
    return 0;
}

/*
--
c......
.......
....***
******* <- yes

....
...*
**** <- no


.......*
.......*
......**
.....***
....****
...*****
..******
******** <- yes

.........*
.........*
..********
..********
..********
..********
..********
********** <- yes

...***
...***
******
****** <- no

c.....***** <- yes

c
.
.
.
.
*
*
*
* <- yes

*/
