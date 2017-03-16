#include <iostream>
#include <string>

using namespace std;

string board[4];

bool check_char(char player, char at_board) {
    return at_board == player || at_board == 'T';
}

bool check_win(char c) {
    bool win;
    for (int i = 0; i < 4; i++) {
        win = true;
        for (int j = 0; j < 4; j++)
            if (!check_char(c, board[i][j]))
                win = false;
        if (win)
            return true;

        win = true;
        for (int j = 0; j < 4; j++)
            if (!check_char(c, board[j][i]))
                win = false;
        if (win)
            return true;
    }

    win = true;
    for (int i = 0; i < 4; i++)
        if (!check_char(c, board[i][i]))
            win = false;
    if (win)
        return true;

    win = true;
    for (int i = 0; i < 4; i++)
        if (!check_char(c, board[i][3-i]))
            win = false;
    if (win)
        return true;

    return false;
}

string check() {
    if (check_win('X'))
        return "X won";
    if (check_win('O'))
        return "O won";
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == '.')
                return "Game has not completed";
    return "Draw";
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        for (int i = 0; i < 4; i++)
            cin >> board[i];

        cout << "Case #" << testcase << ": " << check() << endl;
    }
    return 0;
}
