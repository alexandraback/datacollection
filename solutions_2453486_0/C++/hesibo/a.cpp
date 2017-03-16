#include <iostream>
using namespace std;

bool validate(char a, char b, char c, char d, char x) {
    int tnum = (a == 'T') + (b == 'T') + (c == 'T') + (d == 'T');
    int xnum = (a == x) + (b == x) + (c == x) + (d == x);
    if (xnum == 4 || (xnum == 3 && tnum == 1)) {
        cout << x << " won" << endl;
        return true;
    }
    return false;
}

void check(string s[]) {
    for (int i = 0; i < 4; i++) {
        if (validate(s[i][0], s[i][1], s[i][2], s[i][3], 'O')) {
            return;
        }
        if (validate(s[i][0], s[i][1], s[i][2], s[i][3], 'X')) {
            return;
        }
        if (validate(s[0][i], s[1][i], s[2][i], s[3][i], 'O')) {
            return;
        }
        if (validate(s[0][i], s[1][i], s[2][i], s[3][i], 'X')) {
            return;
        }
    }
    if (validate(s[0][0], s[1][1], s[2][2], s[3][3], 'O')) {
        return;
    }
    if (validate(s[0][0], s[1][1], s[2][2], s[3][3], 'X')) {
        return;
    }
    if (validate(s[0][3], s[1][2], s[2][1], s[3][0], 'O')) {
        return;
    }
    if (validate(s[0][3], s[1][2], s[2][1], s[3][0], 'X')) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i][j]=='.') {
                cout << "Game has not completed" << endl;
                return;
            }
        }
    }
    cout << "Draw" << endl;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("a_out.txt", "w", stdout);
    
    int t;
    cin >> t;
    for (int task = 1; task <= t; task++) {
        string s[4];
        cin >> s[0] >> s[1] >> s[2] >> s[3];
        
        cout << "Case #" << task << ": "; 
        check(s);
        
        getline(cin, s[0]);
    }
}
