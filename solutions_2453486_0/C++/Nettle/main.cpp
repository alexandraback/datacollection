#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXL 6
#define xWin 1
#define oWin 2

char map[ MAXL ][ MAXL ];
int cnt;
bool checkRow(char s, int x) {
    for (int i = 0; i < 4; ++i)
        if (map[x][i] != s && map[x][i] != 'T') return false;
    return true;
}

bool checkCol(char s, int x) {
    for (int i = 0; i < 4; ++i)
        if (map[i][x] != s && map[i][x] != 'T') return false;
    return true;
}

bool checkDiag(char s) {
    bool flag = true;
    for (int i = 0; i < 4; ++i)
        if (map[i][i] != s && map[i][i] != 'T') flag = false;
    if (!flag) {
        flag = true;
        for (int i = 0; i < 4; ++i)
            if (map[i][3 - i] != s && map[i][3 - i] != 'T') flag = false;
    }
    return flag;
}

int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int p = 1; p <= t; ++p) {
	    int winner = 0, end = true;
	    cnt = 0;
	    for (int i = 0; i < 4; ++i)
            scanf("%s", map[i]);

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (map[i][j] == '.') end = false;
        //check
        for (int i = 0; i < 4; ++i) {
            if (checkRow('X', i)) winner = xWin;
            if (checkRow('O', i)) winner = oWin;
        }
        for (int i = 0; i < 4; ++i) {
            if (checkCol('X', i)) winner = xWin;
            if (checkCol('O', i)) winner = oWin;
        }
        if (checkDiag('X')) winner = xWin;
        if (checkDiag('O')) winner = oWin;

        printf("Case #%d: ", p);
        switch (winner) {
            case 0:
                if (!end) printf("Game has not completed\n");
                else printf("Draw\n");
                break;
            case oWin:
                printf("O won\n");
                break;
            case xWin:
                printf("X won\n");
            default:
                break;
        }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

