#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define INF 1000000000
#define X first
#define Y second
#define pb push_back

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

void solve (vector <string> s) {
    int WO = 0, WX = 0;
    REP (i, 4) {
        int wo = 0, wx = 0;
        REP (j, 4) {
            if (s[i][j] == 'O')  wo++;
            else if (s[i][j] == 'X') wx++;
            else if (s[i][j] == 'T') {
                wo ++;
                wx ++;
            }
        }
        WO = max(wo, WO);
        WX = max(wx, WX);
    }

    REP (i, 4) {
        int wo = 0, wx = 0;
        REP (j, 4) {
            if (s[j][i] == 'O')  wo++;
            else if (s[j][i] == 'X') wx++;
            else if (s[j][i] == 'T') {
                wo ++;
                wx ++;
            }
        }
        WO = max(wo, WO);
        WX = max(wx, WX);
    }

    {
        int wo = 0, wx = 0;
        REP (i, 4) {
            if (s[i][i] == 'O')  wo++;
            else if (s[i][i] == 'X') wx++;
            else if (s[i][i] == 'T') {
                wo ++;
                wx ++;
            }
        }
        WO = max(wo, WO);
        WX = max(wx, WX);
    }

    {
        int wo = 0, wx = 0;
        REP (i, 4) {
            if (s[i][3-i] == 'O')  wo++;
            else if (s[i][3-i] == 'X') wx++;
            else if (s[i][3-i] == 'T') {
                wo ++;
                wx ++;
            }
        }
        WO = max(wo, WO);
        WX = max(wx, WX);
    }

    if (WO == 4) {
        std::cout << "O won" << std::endl;
        return;
    }
    if (WX == 4) {
        std::cout << "X won" << std::endl;
        return;
    }
    REP (i, 4)
        REP (j, 4)
            if (s[i][j] == '.') {
                std::cout << "Game has not completed" << std::endl;
                return;
            }
    std::cout << "Draw" << std::endl;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t) {
        std::cout << "Case #" << tt+1 << ": ";
        vector<string> s;
        REP (i, 4) {
            string ss;
            cin >> ss;
            s.pb(ss);
        }
        solve(s);
    }

    return 0;
}
