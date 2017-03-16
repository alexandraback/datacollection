#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

string s[5];
int c1, c2, ct;
void calc(char ch) {
    if (ch == 'X') c1++;
    else if (ch == 'O') c2++;
    else if (ch == 'T') ct++;
}
int solve() {
    REP(i, 4) {
        c1 = c2 = ct = 0;
        REP(j, 4)
            calc(s[i][j]);
        if (c1 + ct == 4) return 1;
        else if (c2 + ct == 4) return 2;
    }
    REP(j, 4) {
        c1 = c2 = ct = 0;
        REP(i, 4)
            calc(s[i][j]);
        if (c1 + ct == 4) return 1;
        else if (c2 + ct == 4) return 2;
    }
    c1 = c2 = ct = 0;
    for (int i = 0, j = 0; i < 4 && j < 4; i++, j++) {
        calc(s[i][j]);
    }
    if (c1 + ct == 4) return 1;
    else if (c2 + ct == 4) return 2;
    c1 = c2 = ct = 0;
    for (int i = 0, j = 3; i < 4 && j >= 0; i++, j--) {
        calc(s[i][j]);
    }
    if (c1 + ct == 4) return 1;
    else if (c2 + ct == 4) return 2;
    REP(i, 4)
        REP(j, 4)
        if (s[i][j] == '.') return -1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T, ca = 0;
    cin >>T;
    string tmp;
    while (T--) {
        REP(i, 4) cin >>s[i];
        //getline(cin, s);
        int ans = solve();
        cout <<"Case #" <<++ca <<": ";
        if (ans == 1) cout <<"X won" <<endl;
        else if (ans == 2) cout <<"O won" <<endl;
        else if (ans == 0) cout <<"Draw" <<endl;
        else cout <<"Game has not completed" <<endl;
    }
    return 0;
}

