#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

int mat[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2, -1, 4, -3},
    {0, 3, -4, -1, 2},
    {0, 4, 3, -2, -1}
};

int getVal(char ch) {
    if (ch == 'i') return 2;
    if (ch == 'j') return 3;
    if (ch == 'k') return 4;
    return -1;
}

void run() {
    int L, X;
    cin >> L >> X;
    string s, str = "";
    cin >> s;
    REP(i, X) str += s;

    int len = str.length();
    int idx = 0, val = 1;

    while (idx < len) {
        int m = getVal(str[idx++]);
        val = val < 0 ? -mat[-val][m] : mat[val][m];
        if (val == 2) break;
    }
    if (idx >= len) {
        cout << "NO" << endl;
        return;
    }

    val = 1;
    while (idx < len) {
        int m = getVal(str[idx++]);
        val = val < 0 ? -mat[-val][m] : mat[val][m];
        if (val == 3) break;
    }
    if (idx >= len) {
        cout << "NO" << endl;
        return;
    }

    val = 1;
    while (idx < len) {
        int m = getVal(str[idx++]);
        val = val < 0 ? -mat[-val][m] : mat[val][m];
    }
    if (val == 4) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
