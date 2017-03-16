#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define mp make_pair
#define pb push_back

enum State {
    XWIN,
    OWIN,
    DRAW,
    NOTCOMPLETED
};

void f(int n) {
    State st = DRAW;
    char f[6][6], c;
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            f[i][j] = 0;
    
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            cin >> c; f[i][j] = c;
            if (c == '.')
                st = NOTCOMPLETED;
            if (c == 'X' || c == 'T')
                ++f[i][4], ++f[4][j];
            if (c == 'O' || c == 'T')
                ++f[i][5], ++f[5][j];
        }    
    
    /*for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl << endl;*/
    
    for (int i = 0; i < 4; ++i) {
        if (f[i][4] == 4 || f[4][i] == 4) {
            st = XWIN; break;
        }
        if (f[i][5] == 4 || f[5][i] == 4) {
            st = OWIN; break;
        }
    }
    
    if (st != XWIN || st != OWIN) {
        int x, o;
        x = o = 0;
        for (int i = 0; i < 4; ++i) {
            if (f[i][i] == 'X' || f[i][i] == 'T')
                ++x;
            if (f[i][i] == 'O' || f[i][i] == 'T')
                ++o;
        }
            
        if (x == 4)
            st = XWIN;
        if (o == 4)
            st = OWIN;
            
        if (st != XWIN || st != OWIN) {
            x = o = 0;
            for (int i = 0; i < 4; ++i) {
                if (f[i][3 - i] == 'X' || f[i][3 - i] == 'T')
                    ++x;
                if (f[i][3 - i] == 'O' || f[i][3 - i] == 'T')
                    ++o;
            }
                
            if (x == 4)
                st = XWIN;
            if (o == 4)
                st = OWIN;
        }
    }
    
    if (st == XWIN)
        cout << "Case #" << n << ": " << "X won" << endl;
    else if (st == OWIN)
        cout << "Case #" << n << ": " << "O won" << endl;
    else if (st == DRAW)
        cout << "Case #" << n << ": " << "Draw" << endl;
    else if (st == NOTCOMPLETED)
        cout << "Case #" << n << ": " << "Game has not completed" << endl;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        f(i);
    return 0;
}
