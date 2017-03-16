#include <cstdio>

char board[4][4];
bool foundEmpty;

int checkBoard(int startX, int startY, int dX, int dY) {
    int X = 0, O = 0, steps = 0;
    int x = startX, y = startY;
    while (steps < 4) {
        switch (board[x][y]) {
            case '.':
                foundEmpty = true;
                return 0;

            case 'X':
                X++;
                break;

            case 'O':
                O++;
                break;

            case 'T':
                X++;
                O++;
                break;
        }

        steps++;
        x += dX;
        y += dY;
    }

    if (X == 4) {
        return 1;
    }

    if (O == 4) {
        return 2;
    }

    return 0;
}

int main(int argc, char const *argv[]) {
    int cas = 0, T;
    scanf("%d\n", &T);

    while (T--) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                scanf("%c", &board[i][j]);
            }
            getchar();
        }
        getchar();

        foundEmpty = false;

        int result = 0;
        for (int i = 0; i < 4; ++i) {
            if ((result = checkBoard(0, i, 1, 0))) {
                goto end;
            }
            if ((result = checkBoard(i, 0, 0, 1))) {
                goto end;
            }
        }

        if ((result = checkBoard(0, 0, 1, 1))) {
            goto end;
        }

        if ((result = checkBoard(3, 0, -1, 1))) {
            goto end;
        }

        end:
            char resultS[80];
            switch(result) {
                case 0:
                    printf("Case #%d: %s\n", ++cas, foundEmpty ? "Game has not completed" : "Draw");
                    break;

                case 1:
                    printf("Case #%d: %s\n", ++cas, "X won");
                    break;

                case 2:
                    printf("Case #%d: %s\n", ++cas, "O won");
                    break;
            }

    }
    return 0;
}