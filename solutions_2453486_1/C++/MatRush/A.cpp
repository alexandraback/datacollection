#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char mat[5][5];
char tmp[5][5];
bool check(char c) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp[i][j] = mat[i][j];
            if (tmp[i][j] == 'T') tmp[i][j] = c;
        }
    }
    for (int i = 0; i < 4; i++) {
        bool ok = true;
        for (int j = 0; j < 4; j++) {
            if (tmp[i][j] != c) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    for (int j = 0; j < 4; j++) {
        bool ok = true;
        for (int i = 0; i < 4; i++) {
            if (tmp[i][j] != c) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    bool ok = true;
    for (int i = 0; i < 4; i++) {
        if (tmp[i][i] != c) {
            ok = false;
            break;
        }
    }
    if (ok) return true;
    ok = true;
    for (int i = 0; i < 4; i++) {
        if (tmp[i][3 - i] != c) {
            ok = false;
            break;
        }
    }
    if (ok) return true;
    return false;
}
int main() {
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T++) {
        getchar();
        bool all = true;
        for (int i = 0; i < 4; i++) {
            gets(mat[i]);
            for (int j = 0; j < 4; j++) {
                if (mat[i][j] == '.') all = false;
            }
        }
        //X
        bool Xwin = check('X'), Owin = check('O');
        printf("Case #%d: ", T);
        if (Xwin && !Owin) {
            puts("X won");
        } else if (!Xwin && Owin) {
            puts("O won");
        } else {
            puts(all ? "Draw" : "Game has not completed");
        }
    }
}
