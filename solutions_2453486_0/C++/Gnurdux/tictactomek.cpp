#include <iostream>
using namespace std;

int wins[10][4][2] = { { {0, 0}, {0, 1}, {0, 2}, {0, 3} },
                       { {1, 0}, {1, 1}, {1, 2}, {1, 3} },
                       { {2, 0}, {2, 1}, {2, 2}, {2, 3} },
                       { {3, 0}, {1, 1}, {1, 2}, {1, 3} },
                       { {0, 0}, {1, 0}, {2, 0}, {3, 0} },
                       { {0, 1}, {1, 1}, {2, 1}, {3, 1} },
                       { {0, 2}, {1, 2}, {2, 2}, {3, 2} },
                       { {0, 3}, {1, 3}, {2, 3}, {3, 3} },
                       { {0, 0}, {1, 1}, {2, 2}, {3, 3} },
                       { {0, 3}, {1, 2}, {2, 1}, {3, 0} } };

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        char board[4][4];
        bool hasdots = false;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> board[i][j];
                if (board[i][j] == '.') hasdots = true;
            }
        }
        cout << "Case #" << t << ": ";
        int i;
        for (i = 0; i < 10; i++) {
            bool x = true, o = true;
            for (int j = 0; j < 4; j++) {
                if (board[wins[i][j][0]][wins[i][j][1]] == '.' || board[wins[i][j][0]][wins[i][j][1]] == 'O') x = false;
                if (board[wins[i][j][0]][wins[i][j][1]] == '.' || board[wins[i][j][0]][wins[i][j][1]] == 'X') o = false;
            }
            if (x) {
                cout << "X won\n";
                break;
            }
            if (o) {
                cout << "O won\n";
                break;
            }
        }
        if (i == 10) {
            if (hasdots) {
                cout << "Game has not completed\n";
            } else {
                cout << "Draw\n";
            }
        }
    }
    return 0;
}
