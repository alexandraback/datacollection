#include <string>
#include <cstdio>

using namespace std;

enum Winner {None, XWon, OWon, Draw};

Winner lineWinner(char a, char b, char c, char d)
{
    char chs[4];
    chs[0] = a;
    chs[1] = b;
    chs[2] = c;
    chs[3] = d;
    bool xwon = true;
    for (int i = 0; i < 4; ++i)
    {
        if (chs[i] != 'X' && chs[i] != 'T')
        {
            xwon = false;
            break;
        }
    }
    if (xwon)
        return XWon;
    bool owon = true;
    for (int i = 0; i < 4; ++i)
    {
        if (chs[i] != 'O' && chs[i] != 'T')
        {
            owon = false;
            break;
        }
    }
    if (owon)
        return OWon;
    return None;
}

Winner winner(const string* board)
{
    for (int i = 0; i < 4; ++i)
    {
        Winner res;
        res = lineWinner(board[i][0], board[i][1], board[i][2], board[i][3]);
        if (res != None)
            return res;
    }
    for (int i = 0; i < 4; ++i)
    {
        Winner res;
        res = lineWinner(board[0][i], board[1][i], board[2][i], board[3][i]);
        if (res != None)
            return res;
    }
    Winner res;
    res = lineWinner(board[0][0], board[1][1], board[2][2], board[3][3]);
    if (res != None)
        return res;
    res = lineWinner(board[0][3], board[1][2], board[2][1], board[3][0]);
    if (res != None)
        return res;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j] == '.')
                return None;
        }
    }
    return Draw;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int idxTestcase = 1; idxTestcase <= T; ++idxTestcase)
    {
        string board[4];
        for (int i = 0; i < 4; ++i)
        {
            char line[5];
            scanf("%s", line);
            board[i] = line;
        }
        const char* result;
        switch (winner(board))
        {
        case None:
            result = "Game has not completed";
            break;
        case XWon:
            result = "X won";
            break;
        case OWon:
            result = "O won";
            break;
        case Draw:
            result = "Draw";
            break;
        }
        printf("Case #%d: %s\n", idxTestcase, result);
    }
    return 0;
}
