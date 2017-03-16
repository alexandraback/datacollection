#include "codejam-dsl.hpp"

string board[5];

bool ckrow(char sym, int x, int y, int dx, int dy)
{
    for (; x >= 0 && x < 4 && y >= 0 && y < 4; x += dx, y += dy) {
        if (board[y][x] != sym && board[y][x] != 'T') {
            return false;
        }
    }
    return true;
}

bool wins(char sym) {
    bool rv = false;

    rv |= ckrow(sym, 0, 0, 1, 0);
    rv |= ckrow(sym, 0, 1, 1, 0);
    rv |= ckrow(sym, 0, 2, 1, 0);
    rv |= ckrow(sym, 0, 3, 1, 0);

    rv |= ckrow(sym, 0, 0, 0, 1);
    rv |= ckrow(sym, 1, 0, 0, 1);
    rv |= ckrow(sym, 2, 0, 0, 1);
    rv |= ckrow(sym, 3, 0, 0, 1);

    rv |= ckrow(sym, 0, 0, 1, 1);
    rv |= ckrow(sym, 3, 0, -1, 1);

    return rv;
}

void run() {
    FZ(i,5) getline(cin, board[i]);

    bool ow = wins('O'), xw = wins('X');
    if (ow && xw) {
        // this is not possible in real game, but can it be in the input?
        cout << "Draw";
    } else if (ow) {
        cout << "O won";
    } else if (xw) {
        cout << "X won";
    } else {
        bool incomplete = false;
        FZ(y,4) FZ(x,4) {
            if (board[y][x] == '.') {
                incomplete = true;
                break;
            }
        }
        if (incomplete) {
            cout << "Game has not completed";
        } else {
            cout << "Draw";
        }
    }
}

