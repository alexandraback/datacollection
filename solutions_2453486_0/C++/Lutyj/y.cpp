#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char f[4][5];

string check(string& tmp)
{
    int nD = count(tmp.begin(), tmp.end(), '.');
    if (nD > 0) return "";

    int nX = count(tmp.begin(), tmp.end(), 'X');
    int nO = count(tmp.begin(), tmp.end(), 'O');

    if (nX > 0 && nO > 0) return "";
    if (nX > 0) return "X"; else return "O";
}

void solve()
{
    for (int r = 0; r < 4; ++r) {
        string tmp(f[r]);
        if (check(tmp) != "") { cout << check(tmp) << " won" << endl; return; }
    }

    for (int c = 0; c < 4; ++c) {
        string tmp;
        for (int r = 0; r < 4; ++r) tmp += f[r][c];
        if (check(tmp) != "") { cout << check(tmp) << " won" << endl; return; }
    }

    string tmp;
    for (int i = 0; i < 4; ++i) tmp += f[i][i];
    if (check(tmp) != "") { cout << check(tmp) << " won" << endl; return; }

    tmp = "";
    for (int i = 0; i < 4; ++i) tmp += f[i][3-i];
    if (check(tmp) != "") { cout << check(tmp) << " won" << endl; return; }

    int nD = count(&f[0][0], &f[3][5], '.');

    if (nD == 0)
        cout << "Draw" << endl;
    else
        cout << "Game has not completed" << endl;;
}

int main()
{
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t+1 << ": ";
        for (int r = 0; r < 4; ++r) cin >> f[r];
        solve();
    }


    return 0;
}
