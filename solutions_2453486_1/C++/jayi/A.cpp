/*
 *     Filename:  A.cpp
 *
 *  Description:  
 *
 *      Version:  1.0
 *      Created:  04/13/2013 12:59:41 PM
 *     Revision:  none
 *     Compiler:  gcc
 *
 *       Author:  Hong Jinyi (hongjy), hongjy@chinanetcenter.com
 * Organization:  chinanetcenter
 */

#include <stdlib.h>
#include <stdio.h>

bool has4(char a[][5], int x, int y, char ch) {
    int i;

    if (y == 0) {
        for (i = 1; i < 4; ++i) {
            if (a[x][i] != ch && a[x][i] != 'T') 
                break;
        }
        if (i == 4) {
            return true;
        }
    }

    if (x == 0) {
        for (i = 1; i < 4; ++i) {
            if (a[i][y] !=ch && a[i][y] != 'T')
                break;
        }
        if (i == 4)
            return true;
    }

    if (x == 0 && y == 0) {
        for (i = 1; i < 4; ++i) {
            if (a[i][i] !=ch && a[i][i] != 'T')
                break;
        }
        if (i == 4)
            return true;
    }

    if (x == 3 && y == 0) {
        for (i = 1; i < 4; ++i) {
            if (a[3 - i][i] !=ch && a[3 - i][i] != 'T')
                break;
        }
        if (i == 4)
            return true;
    }
    
    return false;
}

char judge(char a[][5]) {
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if (a[i][j] == 'X' || a[i][j] == 'T') {
                if (has4(a, i, j, 'X')) {
                    return 'X';
                }
            }
            if (a[i][j] == 'O' || a[i][j] == 'T') {
                if (has4(a, i, j, 'O')) {
                    return 'O';
                }
            }
        }
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if (a[i][j] == '.')
                return 'N';
        }
    }
    return 'D';
}

int main(int argc, char *argv[])
{
    int i;
    char a[5][5];
    int T;

    freopen("in.txt", "r", stdin);
    freopen("A.txt", "w", stdout);
    scanf("%d", &T);
    int cas = 0;
    while (T--) {
        for (i = 0; i < 4; ++i) {
            scanf("%s", a[i]);
        }
        printf("Case #%d: ", ++cas);
        if (judge(a) == 'X') {
            puts("X won");
        }
        else if (judge(a) == 'O') {
            puts("O won");
        }
        else if (judge(a) == 'D') {
            puts("Draw");
        }
        else {
            puts("Game has not completed");
        }
    }

    return EXIT_SUCCESS;
}

