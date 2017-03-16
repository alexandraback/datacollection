// David Wahler <dwahler@gmail.com>
// Google Code Jam submission: "Tic-Tac-Toe-Tomek"

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++) {
        vector<string> board(4);
        for (int i = 0; i < 4; i++) {
            cin >> board[i];
        }

        bool x_won = false, o_won = false;
        int filled_cells = 0;

        for (int i = 0; i < 4; i++) {
            bool x_won_row = true, x_won_col = true;
            bool o_won_row = true, o_won_col = true;

            for (int j = 0; j < 4; j++) {
                if (board[i][j] != '.') filled_cells++;

                if (board[i][j] != 'X' && board[i][j] != 'T') x_won_row = false;
                if (board[i][j] != 'O' && board[i][j] != 'T') o_won_row = false;
                if (board[j][i] != 'X' && board[j][i] != 'T') x_won_col = false;
                if (board[j][i] != 'O' && board[j][i] != 'T') o_won_col = false;
            }
            x_won = x_won || x_won_row || x_won_col;
            o_won = o_won || o_won_row || o_won_col;
        }

        int diagonal = 0;
        for (int diagonal = 0; diagonal < 2; diagonal++) {
            bool x_won_diag = true, o_won_diag = true;
            for (int i = 0; i < 4; i++) {
                int j = diagonal ? i : 3-i;
                if (board[i][j] != 'X' && board[i][j] != 'T') x_won_diag = false;
                if (board[i][j] != 'O' && board[i][j] != 'T') o_won_diag = false;
            }
            x_won = x_won || x_won_diag;
            o_won = o_won || o_won_diag;
        }

        cout << "Case #" << testCase << ": ";
        if (x_won) {
            cout << "X won";
        } else if (o_won) {
            cout << "O won";
        } else if (filled_cells < 16) {
            cout << "Game has not completed";
        } else {
            cout << "Draw";
        }
        cout << endl;

    }
}
