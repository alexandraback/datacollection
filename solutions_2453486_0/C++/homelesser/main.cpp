#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s[5][5];

bool check(char c, int x, int y, int dx, int dy) {
    bool ret = 1;
    for (int i = 0; i < 4 && ret; i++) {
        ret &= (s[x][y] == c || s[x][y] == 'T');
        x += dx;
        y += dy;
    }
    return ret;
}

int main() {
    freopen("in.1.txt", "r", stdin);
    freopen("out.1.txt", "w", stdout);
    int TT;
    scanf("%d", &TT);
    for (int cas = 1; cas <= TT; cas++) {
        for (int i = 0; i < 4; i++)
            scanf(" %s", s[i]);
        bool X = 0, O = 0, E = 0;
        for (int i = 0; i < 4; i++) {
            X |= check('X', 0, i, 1, 0);
            O |= check('O', 0, i, 1, 0);
        }
        for (int i = 0; i < 4; i++) {
            X |= check('X', i, 0, 0, 1);
            O |= check('O', i, 0, 0, 1);
        }
        X |= check('X', 0, 0, 1, 1);
        O |= check('O', 0, 0, 1, 1);
        X |= check('X', 0, 3, 1, -1);
        O |= check('O', 0, 3, 1, -1);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                E |= (s[i][j] == '.');
        printf("Case #%d: ", cas);
        if (X) puts("X won");
        else if (O) puts("O won");
        else if (E) puts("Game has not completed");
        else puts("Draw");
    }
    return 0;
}