// Google Code Jam Qualification Round 2013
// A
// by A Code Rabbit

#include <cstdio>
#include <cctype>

char board[4][4];
int cnt_x, cnt_o, cnt_t, cnt_d;
bool exist_dot;
bool got;

void compute(char x) {
    switch (x) {
        case 'X': cnt_x++; break;
        case 'O': cnt_o++; break;
        case 'T': cnt_t++; break;
        case '.': cnt_d++; break;
    }
}

void judge(char a, char b, char c, char d) {
    if (got) return;
    cnt_x = cnt_o = cnt_t = cnt_d = 0;
    compute(a);
    compute(b);
    compute(c);
    compute(d);
    if (cnt_x == 4 || (cnt_x == 3 && cnt_t == 1)) {
        puts("X won");
        got = true;
        return;
    }
    if (cnt_o == 4 || (cnt_o == 3 && cnt_t == 1)) {
        puts("O won");
        got = true;
        return;
    }
    if (cnt_d) exist_dot = true;
}


char getch() {
    char ch = getchar();
    while (isspace(ch)) ch = getchar();
    return ch;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                board[i][j] = getch();

        printf("Case #%d: ", cas);

        exist_dot = got = false;
        for (int i = 0; i < 4; i++)
            judge(board[i][0], board[i][1], board[i][2], board[i][3]);
        for (int i = 0; i < 4; i++)
            judge(board[0][i], board[1][i], board[2][i], board[3][i]);
        judge(board[0][0], board[1][1], board[2][2], board[3][3]);
        judge(board[0][3], board[1][2], board[2][1], board[3][0]);

        if (!got) puts(exist_dot ? "Game has not completed" : "Draw");
    }

    return 0;
}
