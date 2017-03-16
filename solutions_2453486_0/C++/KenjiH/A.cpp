#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  

inline bool check(char x, char a) {
    return (x == a) || (x == 'T');
}

bool win(const vector<string> &v, char c) {
    bool ck;

    // horizontal check
    REP (i, 4) {
        ck = true;
        REP (j, 4)
            ck &= check(v[i][j], c);
        if (ck)
            return true;
    }
    // vertical check
    REP (i, 4) {
        ck = true;
        REP (j, 4)
            ck &= check(v[j][i], c);
        if (ck)
            return true;
    }
    // diagonal check
    ck = true;
    REP (i, 4)
        ck &= check(v[i][i], c);
    if (ck)
        return true;

    ck = true;
    REP (i, 4)
        ck &= check(v[i][3-i], c);
    if (ck)
        return true;

    return false;
}

int cntEmpty(const vector<string> &v) {
    int ret = 0;
    REP (i, 4) REP (j, 4) if (v[i][j] == '.') ++ret;
    return ret;
}

string solve() {
    vector<string> bd(4);
    REP (i, 4)
        cin >> bd[i];

    if (win(bd, 'X'))
        return "X won";
    if (win(bd, 'O'))
        return "O won";
    if (cntEmpty(bd))
        return "Game has not completed";
    return "Draw";
}

int main() {
    int T;
    cin >> T;

    REP (i, T) {
        string res = solve();
        printf("Case #%d: %s\n", i+1, res.c_str());
    }
    return 0;
}
