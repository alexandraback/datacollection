#include <stdio.h>

char board[4][5];
char str[10];
int hash_t[256];
int count[4];
void init() {
    hash_t['O'] = 0;
    hash_t['X'] = 1;
    hash_t['T'] = 2;
    hash_t['.'] = 3;
}
int check(char a, char b, char c, char d) {
    for(int i = 0; i < 4; i++) count[i] = 0;
    count[hash_t[a]]++;
    count[hash_t[b]]++;
    count[hash_t[c]]++;
    count[hash_t[d]]++;
    return count[2] + count[0] == 4 ? 'O' :
            count[2] + count[1] == 4 ? 'X' : -1;
}
int checkRow(int i) {
    return check(board[i][0], board[i][1], board[i][2], board[i][3]);
}
int checkColumn(int i) {
    return check(board[0][i], board[1][i], board[2][i], board[3][i]);
}
int checkBoard() {
    int ret = -1;
    for (int i = 0; i < 4; i++) {
        ret = checkRow(i);
        if (ret != -1) {
            return ret;
        }
        ret = checkColumn(i);
        if (ret != -1) {
            return ret;
        }
    }
    ret = check(board[0][0], board[1][1], board[2][2], board[3][3]);
    if (ret != -1) {
        return ret;
    }
    ret = check(board[0][3], board[1][2], board[2][1], board[3][0]);
    if (ret != -1) {
        return ret;
    }
    return -1;
}
bool hasDot() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == '.') return true;
        }
    }
    return false;
}
int main() {
    int T;
    scanf("%d", &T);
    getchar();
    init();
    for (int ncas = 1; ncas <= T; ncas++) {
        // printf("Case %d:\n", ncas);
        for (int i = 0; i < 4; i++) {
            gets(board[i]);
            // puts(board[i]);
        }
        int ret = checkBoard();
        if (ret != -1) {
            printf("Case #%d: %c won\n", ncas, ret);
        } else {
            if (hasDot()) {
                printf("Case #%d: Game has not completed\n", ncas);
            } else {
                printf("Case #%d: Draw\n", ncas);
            }
        }
        gets(str);
    }
    return 0;
}

// (shell-command (format "%s < %s > %s " ts-run-file-name "A-small-attempt2.in" "A-small-attempt2.out"))
// (shell-command (format "%s < %s > %s " ts-run-file-name "A-large.in" "A-large.out"))
