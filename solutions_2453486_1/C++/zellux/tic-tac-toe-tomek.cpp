#include <iostream>

bool winning_in_row(char *row, char player)
{
    int t = 0;
    for (int i = 0; i < 4; i++) {
        if (row[i] == 'T')
            t++;
        else if (row[i] != player)
            return false;
    }
    return t <= 1;
}

bool winning(char board[4][4], char player)
{
    char row[4];
    for (int i = 0; i < 4; i++)
        if (winning_in_row(&board[i][0], player))
            return true;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            row[j] = board[j][i];
        if (winning_in_row(row, player))
            return true;
    }

    for (int i = 0; i < 4; i++)
        row[i] = board[i][i];
    if (winning_in_row(row, player))
        return true;

    for (int i = 0; i < 4; i++)
        row[i] = board[i][3 - i];
    if (winning_in_row(row, player))
        return true;
    return false;
}

int main()
{
    int t;
    char board[4][4];
    char ch;
    bool filled;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        filled = true;
        for (int x = 0; x < 4; x ++) {
            std::cin.get(ch);
            for (int y = 0; y < 4; y++) {
                std::cin.get(board[x][y]);
                if (board[x][y] == '.')
                    filled = false;
            }
        }
        std::cout << "Case #" << i + 1 << ": ";
        if (winning(board, 'X'))
            std::cout << "X won" << std::endl;
        else if (winning(board, 'O'))
            std::cout << "O won" << std::endl;
        else if (filled)
            std::cout << "Draw" << std::endl;
        else
            std::cout << "Game has not completed" << std::endl;
        std::cin.get(ch);
    }
    return 0;
}

