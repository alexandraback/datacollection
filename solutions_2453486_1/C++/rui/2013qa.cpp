#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int a[4][4];
int b[3];
int check() {
    int ret = 0;
    if (b[0] == 4 || (b[0] == 3 && b[2] == 1))
        ret = 1;
    if (b[1] == 4 || (b[1] == 3 && b[2] == 1))
        ret = 2;
    memset(b, 0 ,sizeof b);
    return ret;
}
void setb(int x, int y) {
    if (a[x][y] == 1)
        b[0]++;
    if (a[x][y] == 2)
        b[1]++;
    if (a[x][y] == 3)
        b[2]++;
}
int gao() {
    memset(b, 0 ,sizeof b);
    int ret;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            setb(i, j);
        ret = check();
        if (ret)
            return ret;
        for (int j = 0; j < 4; ++j)
            setb(j, i);
        ret = check();
        if (ret)
            return ret;
    }
    for (int i = 0; i < 4; ++i)
        setb(i, i);
    ret = check();
    if (ret)
        return ret;
    for (int i = 0; i < 4; ++i)
        setb(i, 3-i);
    ret = check();
    if (ret)
        return ret;
    return 0;
}
int main() {
    int t;
    string s;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        getline(cin, s);
        int zero = 0;
        for (int i = 0; i < 4; ++i) {
            getline(cin, s);
            for (int j = 0; j < 4; ++j) {
                if (s[j] == '.') {
                    a[i][j] = 0;
                    zero = 1;
                }
                if (s[j] == 'X')
                    a[i][j] = 1;
                if (s[j] == 'O')
                    a[i][j] = 2;
                if (s[j] == 'T')
                    a[i][j] = 3;
            }
        }
        int ret = gao();
        cout << "Case #" << tt << ": ";
        if (ret) {
            if (ret == 1)
                cout << "X won" << endl;
            else
                cout << "O won" << endl;
        } else {
            if (zero)
                cout << "Game has not completed" << endl;
            else
                cout << "Draw" << endl;
        }
    }
    return 0;
}
