#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

int T;
string s[10];

bool checkRow(char type) {
    int i, j;
    for (i = 0; i < 4; i++) {
        set<char> memo;
        for (j = 0; j < 4; j++) memo.insert(s[i][j]);
        if(memo.size() == 1 && memo.count(type)) return true;
        if(memo.size() == 2 && memo.count(type) && memo.count('T')) return true;
    }
    return false;
}

bool checkCol(char type) {
    int i, j;
    for (j = 0; j < 4; j++) {
        set<char> memo;
        for (i = 0; i < 4; i++) memo.insert(s[i][j]);
        if(memo.size() == 1 && memo.count(type)) return true;
        if(memo.size() == 2 && memo.count(type) && memo.count('T')) return true;
    }
    return false;
}

bool checkDiag(char type) {
    int i, j;
    set<char> fi, si;

    fi.insert(s[0][0]); fi.insert(s[1][1]); fi.insert(s[2][2]); fi.insert(s[3][3]);
    si.insert(s[0][3]); si.insert(s[1][2]); si.insert(s[2][1]); si.insert(s[3][0]);

    if(fi.size() == 1 && fi.count(type)) return true;
    if(si.size() == 1 && si.count(type)) return true;
    if(fi.size() == 2 && fi.count(type) && fi.count('T')) return true;
    if(si.size() == 2 && si.count(type) && si.count('T')) return true;

    return false;
}


int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    int i, j, test = 1;
    cin >> T;
    for ( ; T--; ) {
        bool has_incomplete = false;
        for (i = 0; i < 4; i++) {
            cin >> s[i];
            for (j = 0; j < 4; j++) {
                if(s[i][j] == '.') {
                    has_incomplete = true;
                }
            }
        }

        cout << "Case #" << test++ << ": ";

        if(checkRow('X') || checkCol('X') || checkDiag('X')) {
            cout << "X won\n";
        } else if(checkRow('O') || checkCol('O') || checkDiag('O')) {
            cout << "O won\n";
        } else if(has_incomplete) {
            cout << "Game has not completed\n";
        } else {
            cout << "Draw\n" ;
        }
    }
    return 0;
}
