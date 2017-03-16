/*
 * @author: zhenpeng.fang
 * @nickname: dumpling
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

//%llu
typedef unsigned long long uint64;
typedef long long int64;

const double eps = 1e-8;
int T;
int board[4][4];
char line[8];

void init() {
    gets(line);
    for (int i = 0; i < 4; ++i) {
        gets(line);
        for (int j = 0; j < 4; ++j) {
            switch (line[j]) {
                case 'X': board[i][j] = 1;
                    break;
                case 'O': board[i][j] = 2;
                    break;
                case 'T': board[i][j] = 3;
                    break;
                default: board[i][j] = 0;
            }
        }
    }
}

int checkRow(int r) {
    int ret = board[r][0];
    for (int i = 1; i < 4; ++i)
        ret &= board[r][i];
    return ret;
}

int checkColumn(int c) {
    int ret = board[0][c];
    for (int i = 1; i < 4; ++i)
        ret &= board[i][c];
    return ret;
}

int checkMainDiag() {
    int ret = board[0][0];
    for (int i = 1; i < 4; ++i)
        ret &= board[i][i];
    return ret;
}

int checkWiseDiag() {
    int ret = board[0][3];
    for (int i = 1; i < 4; ++i)
        ret &= board[i][3 - i];
    return ret;
}

bool complete() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (!board[i][j])
                return false;
    return true;
}

int win() {
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        ret = checkRow(i);
        if (ret)
            return ret;
        ret = checkColumn(i);
        if (ret)
            return ret;
    }
    ret = checkMainDiag();
    if (ret)
        return ret;
    ret = checkWiseDiag();
    if (ret)
        return ret;
    if (complete())
        return 3;
    return 0;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        init();
        switch (win()) {
            case 1:printf("Case #%d: X won\n", t);
                break;
            case 2:printf("Case #%d: O won\n", t);
                break;
            case 3:printf("Case #%d: Draw\n", t);
                break;
            default:printf("Case #%d: Game has not completed\n", t);
                break;
        }
    }

    return 0;
}