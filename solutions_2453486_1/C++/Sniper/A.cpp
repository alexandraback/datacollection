#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool win(const vector<string> & vec, char chess) {
    int cnt = 0;
    for (int i = 0; i < 4; ++ i) {
        cnt = 0;
        for (int j = 0; j < 4; ++ j) {
            if (chess == vec[i][j] || 'T' == vec[i][j]) ++ cnt;
        }
        if (cnt == 4) return true;
        cnt = 0;
        for (int j = 0; j < 4; ++ j) {
            if (chess == vec[j][i] || 'T' == vec[j][i]) ++ cnt;
        }
        if (cnt == 4) return true;
    }
    cnt = 0;
    for (int i = 0; i < 4; ++ i) {
        if (chess == vec[i][i] || 'T' == vec[i][i]) ++ cnt;
    }
    if (cnt == 4) return true;
    cnt = 0;
    for (int i = 0; i < 4; ++ i) {
        if (chess == vec[i][3-i] || 'T' == vec[i][3-i]) ++ cnt;
    }
    if (cnt == 4) return true;
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ ti) {
        vector<string> vec;
        int empty = 0;
        for (int i = 0; i < 4; ++ i) {
            string s;
            cin >> s;
            vec.push_back(s);
            for (int j = 0; j < 4; ++ j) if(s[j] == '.') ++ empty;
        }
        bool Xwin = win(vec, 'X');
        bool Owin = win(vec, 'O');
        if (!Xwin && !Owin) {
            printf("Case #%d: %s\n", ti, empty > 0 ? "Game has not completed" : "Draw");
        } else {
            printf("Case #%d: %s\n", ti, Xwin ? "X won" : "O won");
        }
    }
}
