// #include <QtCore>
#include <stdio.h>

static char board[4][4];

void getBoard()
{
    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 4; ++x)
        {
            board[x][y] = 0;
            while ((board[x][y] != 'X') && (board[x][y] != 'O') && (board[x][y] != 'T') && (board[x][y] != '.'))
                scanf("%c", &board[x][y]);
        }
    }
}

bool hasWon(char playerLetter)
{
    bool column, row, diag1 = true, diag2 = true;
    for (int j = 0; j < 4; ++j)
    {
        column = true;
        row = true;
        for (int i = 0; i < 4; ++i)
        {
            if ((board[j][i] != 'T') && (board[j][i] != playerLetter)) column = false;
            if ((board[i][j] != 'T') && (board[i][j] != playerLetter)) row = false;
        }
        if (column || row) return true;
        if ((board[j][j] != 'T') && (board[j][j] != playerLetter)) diag1 = false;
        if ((board[j][3 - j] != 'T') && (board[j][3 - j] != playerLetter)) diag2 = false;
    }
    return diag1 || diag2;
}

char *run()
{
    if (hasWon('X')) return "X won";
    if (hasWon('O')) return "O won";
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (board[i][j] == '.') return "Game has not completed";
        }
    }
    return "Draw";
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        getBoard();
        printf("Case #%d: %s\n", i, run());
    }
    return 0;
}
