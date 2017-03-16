#include <cstdio>

using namespace std;

char board[4][4];
int have_empties;

int has_line(char c) {
    int gotleft = 1, gotright = 1;

    for (int i = 0; i < 4; i++) {
        int gothori = 1, gotvert = 1;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 'T' && board[i][j] != c)
                gothori = 0;
            if (board[j][i] != 'T' && board[j][i] != c)
                gotvert = 0;
        }

        if (gothori || gotvert)
            return 1;

        if (board[i][i] != 'T' && board[i][i] != c)
            gotleft = 0;
        if (board[3-i][i] != 'T' && board[3-i][i] != c)
            gotright = 0;
    }

    if (gotleft || gotright)
        return 1;

    return 0;
}

char *compute(void) {
    int Xhasline = has_line('X');
    int Ohasline = has_line('O');

    if (Xhasline && Ohasline) {
        /* should be impossible? say a draw just in case */
        return "Draw (2 lines)";
    }

    if (Xhasline) {
        return "X won";
    }

    if (Ohasline) {
        return "O won";
    }

    if (have_empties) {
        return "Game has not completed";
    }

    return "Draw";
}

int main() {
    int T; scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        char line[128];

        fgets(line, 128, stdin);
        have_empties = 0;
        for (int j = 0; j < 4; j++) {
            fgets(line, 128, stdin);
            for (int k = 0; k < 4; k++) {
                board[j][k] = line[k];
                if (line[k] == '.')
                    have_empties = 1;
            }
        }

        printf("Case #%d: %s\n", i+1, compute());
    }

    return 0;
}
