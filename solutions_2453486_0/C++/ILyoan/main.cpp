#include <cstdlib>
#include <cstdio>

char B[5][5];
bool isWin(char p) {
    for (int y = 0; y < 4; ++y) {
        bool finish = true;
        for (int x = 0; x < 4; ++x) {
            if (!(B[y][x] == 'T' || B[y][x] == p)) {
                finish = false;
                break;
            }
        }
        if (finish) return true;
    }
    for (int x = 0; x < 4; ++x) {
        bool finish = true;
        for (int y = 0; y < 4; ++y) {
            if (!(B[y][x] == 'T' || B[y][x] == p)) {
                finish = false;
                break;
            }
        }
        if (finish) return true;
    }
    bool finish1 = true;
    bool finish2 = true;
    for (int y = 0; y < 4; ++y) {
        int x1 = y;
        int x2 = 3 - y;
        if (!(B[y][x1] == 'T' || B[y][x1] == p)) finish1 = false;
        if (!(B[y][x2] == 'T' || B[y][x2] == p)) finish2 = false;
    }
    if (finish1 || finish2) return true;
    return false;
}
bool isThereEmpty() {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (B[y][x] == '.') return true;
        }
    }
    return false;
}
int main() 
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        for (int i = 0; i < 4; ++i) scanf("%s", B[i]);
        printf("Case #%d: ", t);
        if (isWin('X')) printf("X won\n");
        else if (isWin('O')) printf("O won\n");
        else if (isThereEmpty()) printf("Game has not completed\n");
        else printf("Draw\n");
    }
    return 0;
}
