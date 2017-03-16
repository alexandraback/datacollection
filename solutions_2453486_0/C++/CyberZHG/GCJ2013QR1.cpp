#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char stage[10][10];
char board[10][10];

bool isWin(char player)
{
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player && board[0][3] == player)
    {
        return true;
    }
    if (board[1][0] == player && board[1][1] == player && board[1][2] == player && board[1][3] == player)
    {
        return true;
    }
    if (board[2][0] == player && board[2][1] == player && board[2][2] == player && board[2][3] == player)
    {
        return true;
    }
    if (board[3][0] == player && board[3][1] == player && board[3][2] == player && board[3][3] == player)
    {
        return true;
    }
    if (board[0][0] == player && board[1][0] == player && board[2][0] == player && board[3][0] == player)
    {
        return true;
    }
    if (board[0][1] == player && board[1][1] == player && board[2][1] == player && board[3][1] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][2] == player && board[2][2] == player && board[3][2] == player)
    {
        return true;
    }
    if (board[0][3] == player && board[1][3] == player && board[2][3] == player && board[3][3] == player)
    {
        return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player)
    {
        return true;
    }
    if (board[0][3] == player && board[1][2] == player && board[2][1] == player && board[3][0] == player)
    {
        return true;
    }
    return false;
}

bool isXWin()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            board[i][j] = stage[i][j];
            if (board[i][j] == 'T')
            {
                board[i][j] = 'X';
            }
        }
    }
    return isWin('X');
}

bool isYWin()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            board[i][j] = stage[i][j];
            if (board[i][j] == 'T')
            {
                board[i][j] = 'O';
            }
        }
    }
    return isWin('O');
}

bool isDraw()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (stage[i][j] == '.')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        for (int i = 0; i < 4; ++i)
        {
            scanf("%s", stage[i]);
        }
        printf("Case #%d: ", t);
        if (isXWin())
        {
            printf("X won\n");
        }
        else if (isYWin())
        {
            printf("O won\n");
        }
        else if (isDraw())
        {
            printf("Draw\n");
        }
        else
        {
            printf("Game has not completed\n");
        }
    }
    return 0;
}
