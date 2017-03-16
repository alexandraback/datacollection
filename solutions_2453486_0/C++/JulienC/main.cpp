#include <iostream>

using namespace std;

bool same_color(char a, char b)
{
    if (a == '.' || b == '.')
    {
        return false;
    }
    return (a == b || a == 'T' || b == 'T');
}

void solve(char board[4][5])
{
    char players[] = {'O', 'X'};
    for (auto p : players)
    {
        for (int i = 0; i < 4; i++)
        {
            if (same_color(p, board[i][0])
             && same_color(p, board[i][1])
             && same_color(p, board[i][2])
             && same_color(p, board[i][3]))
            {
                cout << p << " won" << endl;
                return;
            }
            if (same_color(p, board[0][i])
             && same_color(p, board[1][i])
             && same_color(p, board[2][i])
             && same_color(p, board[3][i]))
            {
                cout << p << " won" << endl;
                return;
            }
        }
        if (same_color(p, board[0][0])
         && same_color(p, board[1][1])
         && same_color(p, board[2][2])
         && same_color(p, board[3][3]))
        {
            cout << p << " won" << endl;
            return;
        }
        if (same_color(p, board[3][0])
         && same_color(p, board[2][1])
         && same_color(p, board[1][2])
         && same_color(p, board[0][3]))
        {
            cout << p << " won" << endl;
            return;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == '.')
            {
                cout << "Game has not completed" << endl;
                return;
            }
        }
    }
    cout << "Draw" << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        char board[4][5];
        cin >> board[0];
        cin >> board[1];
        cin >> board[2];
        cin >> board[3];
        cout << "Case #" << (t+1) << ": ";
        solve(board);
    }
    return 0;
}

