#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

const string X_WON = "X won";
const string O_WON = "O won";
const string DRAW = "Draw";
const string NOT_COMPLETED = "Game has not completed";

char board[5][5];

const int dx[] = {1, 0, 1, -1};
const int dy[] = {0, 1, 1,  1};

bool check(int r, int c, int dir, char player) {
    for (int i = 0; i < 4; ++i) {
        if (board[r][c] != player && board[r][c] != 'T') return false;
        r += dx[dir];
        c += dy[dir];
    }
    return true;
}

bool won(char player) {
    if (check(0, 0, 2, player)) return true;
    if (check(3, 0, 3, player)) return true;
    for (int i = 0; i < 4; ++i) {
        if (check(i, 0, 1, player)) return true;
        if (check(0, i, 0, player)) return true;
    }
    return false;
}

int main() {
    int tests;
    scanf("%d", &tests);
    for (int test_id = 1; test_id <= tests; ++test_id) {
        printf("Case #%d: ", test_id);
        for (int i = 0; i < 4; ++i) cin >> board[i];
        bool over = true;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (board[i][j] == '.')
                    over = false;
        if (won('X')) cout << X_WON << endl;
        else if (won('O')) cout << O_WON << endl;
        else if (over) cout << DRAW << endl;
        else cout << NOT_COMPLETED << endl;
    }
    return 0;
}
