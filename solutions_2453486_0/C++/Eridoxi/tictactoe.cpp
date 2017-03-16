#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>

// STL
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>


using namespace std;

char tab[4][4];
bool full;

int check_line(int i) {
    bool win = true;
    char c;
    char player = 'T';
    for (int j = 0; j < 4; ++j) {
        c = tab[i][j];
        if (c == '.') {
            full = false; return 0;
        } else if (c == 'X') {
            if (player == 'O') win = false;
            else player = 'X';
        } else if (c == 'O') {
            if (player == 'X') win = false;
            else player = 'O';
        }
    }
    if (!win || player == 'T')
        return 0;
    return player == 'X' ? 1:2;
}


int check_col(int i) {
    char c;
    char player = 'T';
    for (int j = 0; j < 4; ++j) {
        c = tab[j][i];
        if (c == '.') {
            return 0;
        } else if (c == 'X') {
            if (player == 'O') return 0;
            else player = 'X';
        } else if (c == 'O') {
            if (player == 'X') return 0;
            else player = 'O';
        }
    }
    if (player == 'T')
        return 0;
    return player == 'X' ? 1:2;
}


int check_diag1() {
    char c;
    char player = 'T';
    for (int j = 0; j < 4; ++j) {
        c = tab[j][3-j];
        if (c == '.') {
            return 0;
        } else if (c == 'X') {
            if (player == 'O') return 0;
            else player = 'X';
        } else if (c == 'O') {
            if (player == 'X') return 0;
            else player = 'O';
        }
    }
    if (player == 'T')
        return 0;
    return player == 'X' ? 1:2;
}


int check_diag2() {
    char c;
    char player = 'T';
    for (int j = 0; j < 4; ++j) {
        c = tab[j][j];
        if (c == '.') {
            return 0;
        } else if (c == 'X') {
            if (player == 'O') return 0;
            else player = 'X';
        } else if (c == 'O') {
            if (player == 'X') return 0;
            else player = 'O';
        }
    }
    if (player == 'T')
        return 0;
    return player == 'X' ? 1:2;
}


int solve() {
    int res;
    for (int i = 0; i < 4; ++i) {
        res = check_line(i);
        if (res != 0) return res;
        res = check_col(i);
        if (res != 0) return res;
    }
    res = check_diag1();
    if (res != 0) return res;
    res = check_diag2();
    if (res != 0) return res;
    return 0;
}

int main() {
    int numcase;

    freopen("A-small-attempt0.in", "r", stdin);
    //freopen("ex_tictac", "r", stdin);
    freopen("A-small.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        full = true;
        for  (int j = 0; j < 4; ++j)
            for  (int l = 0; l < 4; ++l)
                cin >> tab[j][l];
        int g = solve();
        cout << "Case #" << i + 1 << ": ";
        if (g == 1) cout << "X won" << endl;
        else if (g == 2) cout << "O won" << endl;
        else if (g == 0 && full) cout << "Draw" << endl;
        else cout << "Game has not completed" << endl;
    }

    return 0;
}
