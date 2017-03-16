#include <iostream>

using namespace std;

static int won(char c, int val) {
        return val == c * 4 || val == c * 3 + 'T';
}

string judge()
{
        char board[4][4];
        int i = 0;
        int has_dot = 0;
        while (i < 16) {
                char c;
                cin >> c;
                if (c == '.')
                        has_dot = 1;
                if (c == 'X' || c == 'O' || c == 'T' || c == '.') {
                        int x = i % 4;
                        int y = i / 4;
                        board[y][x] = c;
                        ++i;
                }
        }

        for (int i = 0; i < 4; ++i) {
                int v = board[i][0] + board[i][1] + board[i][2] + board[i][3];
                int w = board[0][i] + board[1][i] + board[2][i] + board[3][i];
                if (won('X', v) || won('X', w))
                        return "X won";
                else if (won('O', v) || won('O', w))
                        return "O won";
        }

        int v = board[0][0] + board[1][1] + board[2][2] + board[3][3];
        int w = board[3][0] + board[2][1] + board[1][2] + board[0][3];
        
        if (won('X', v) || won('X', w))
                return "X won";
        else if (won('O', v) || won('O', w))
                return "O won";

        
        return has_dot ? "Game has not completed" : "Draw";
}

int main()
{
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
                cout << "Case #" << i << ": " << judge() << "\n";
        }
        return 0;
}
