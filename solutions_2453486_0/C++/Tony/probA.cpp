
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const string xWon = "X won";
const string oWon = "O won";
const string draw = "Draw";
const string incomplete = "Game has not completed";

string b[4];

bool check(char a1, char a2, char a3, char a4, char c) {
    return (a1 == c || a1 == 'T')
        && (a2 == c || a2 == 'T')
        && (a3 == c || a3 == 'T')
        && (a4 == c || a4 == 'T');
}

bool check_diag(char c) {
    return check(b[0][0], b[1][1], b[2][2], b[3][3], c)
            || check(b[0][3], b[1][2], b[2][1], b[3][0], c);
}

bool check_rowcol(int i, char c) {
    return check(b[i][0], b[i][1], b[i][2], b[i][3], c)
            || check(b[0][i], b[1][i], b[2][i], b[3][i], c);
}

bool check(char c) {
    for (int i = 0; i < 4; i++)
        if (check_rowcol(i, c))
            return true;
    if (check_diag(c))
        return true;
    return false;
}

string solve() {
    if (check('X'))
        return xWon;
    if (check('O'))
        return oWon;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (b[i][j] == '.')
                return incomplete;
    return draw;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 4; i++)
            cin >> b[i];
        cout << "Case #" << t << ": " << solve() << endl;
    }
}

