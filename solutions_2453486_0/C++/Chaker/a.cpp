#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef vector <vector <char> > Map;

bool check_win(char c, Map m) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (m[i][j] == 'T') {
                m[i][j] = c;
            }
        }
    }
    if ((m[0][0] == c)
    && (m[0][0] == m[1][1])
    && (m[0][0] == m[2][2])
    && (m[0][0] == m[3][3])) {
        return true;
    }
    if ((m[0][3] == c)
    && (m[0][3] == m[1][2])
    && (m[0][3] == m[2][1])
    && (m[0][3] == m[3][0])) {
        return true;
    }
    for (int i = 0; i < 4; ++i) {
        if ((m[i][0] == c)
        && (m[i][0] == m[i][1])
        && (m[i][0] == m[i][2])
        && (m[i][0] == m[i][3])) {
            return true;
        }   
    }
    for (int i = 0; i < 4; ++i) {
        if ((m[0][i] == c)
        && (m[0][i] == m[1][i])
        && (m[0][i] == m[2][i])
        && (m[0][i] == m[3][i])) {
            return true;
        }   
    }
    return false;
}

int main()
{
    Map m(4);
    for (int i = 0; i < 4; ++i) {
        m[i].resize(4);
    }
    int TEST = 0;
    cin >> TEST;
    for (int test = 1; test <= TEST; ++test) {
        cout << "Case #" << test << ": ";
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> m[i][j];
            }
        }
        if (check_win('X', m)) {
            cout << "X won" << endl;
            continue;
        }
        if (check_win('O', m)) {
            cout << "O won" << endl;
            continue;
        }
        bool empty_field = false;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                empty_field |=(m[i][j] == '.');
            }
        }
        if (empty_field) {
            cout << "Game has not completed" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }
    return 0;
}