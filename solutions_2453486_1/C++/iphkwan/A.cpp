#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char g[5][5];
int t;

bool judgeWon(char ch) {
    if (ch == 'X')
        ch = 'O';
    else
        ch = 'X';

    for (int i = 0; i < 4; i++) {
        bool flag = true;
        for (int j = 0; j < 4; j++)
            if (g[i][j] == ch || g[i][j] == '.') {
                flag = false;
                break;
            }
        if (flag)
            return true;

        flag = true;
        for (int j = 0; j < 4; j++)
            if (g[j][i] == ch || g[j][i] == '.') {
                flag = false;
                break;
            }
        if (flag)
            return true;
    }
    bool flag = true;
    for (int i = 0; i < 4; i++)
        if (g[i][i] == ch || g[i][i] == '.') {
            flag = false;
            break;
        }
    if (flag)
        return true;
    flag = true;
    for (int i = 0; i < 4; i++)
        if (g[i][3 - i] == ch || g[i][3 - i] == '.') {
            flag = false;
            break;
        }
    if (flag)
        return true;
    return false;
}

bool judgeState() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (g[i][j] == '.')
                return true;
    return false;
}

int main() {
    freopen("t.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    scanf("%d\n", &t);
    for (int z = 1; z <= t; z++) {
        for (int i = 0; i < 4; i++)
            scanf("%s", g[i]);

        printf("Case #%d: ", z);
        if (judgeWon('X'))
            printf("X won\n");
        else if (judgeWon('O'))
            printf("O won\n");
        else if (judgeState())
            printf("Game has not completed\n");
        else
            printf("Draw\n");
    }
    return 0;
}
