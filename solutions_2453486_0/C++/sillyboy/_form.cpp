#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
//#include <conio.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
#define FR(i,n) for (int i = 0; i < (n); i++)
#define DN(i,a) for(int i = (a)-1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define Set(a,c) memset(a, c, sizeof(a))
#define oo 1000000000
#define MAXN 105

typedef pair<int, int> PII;
typedef vector<int> VI;

string a[10];

bool Xwon() {
    FR(i, 4) {
        bool ok = true;
        FR(j, 4) if (a[i][j] == '.' || a[i][j] == 'O') ok = false;
        if (ok) return true;
    }

    FR(i, 4) {
        bool ok = true;
        FR(j, 4) if (a[j][i] == '.' || a[j][i] == 'O') ok = false;
        if (ok) return true;
    }
    bool ok = true;
    FR(i, 4) if (a[i][i] == '.' || a[i][i] == 'O') ok = false;
    if (ok) return true;
    ok = true;
    FR(i, 4) if (a[i][3 - i] == '.' || a[i][3 - i] == 'O') ok = false;
    return ok;
}

bool Owon() {
    FR(i, 4) {
        bool ok = true;
        FR(j, 4) if (a[i][j] == '.' || a[i][j] == 'X') ok = false;
        if (ok) return true;
    }

    FR(i, 4) {
        bool ok = true;
        FR(j, 4) if (a[j][i] == '.' || a[j][i] == 'X') ok = false;
        if (ok) return true;
    }
    bool ok = true;
    FR(i, 4) if (a[i][i] == '.' || a[i][i] == 'X') ok = false;
    if (ok) return true;
    ok = true;
    FR(i, 4) if (a[i][3 - i] == '.' || a[i][3 - i] == 'X') ok = false;
    return ok;
}

bool Draw() {
    FR(i, 4) FR(j, 4) if (a[i][j] == '.') return false;
    return true;
}

string result() {
    if (Xwon()) return "X won";
    if (Owon()) return "O won";
    if (Draw()) return "Draw";
    return "Game has not completed";
}

int main () {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int ntest;
    cin >> ntest;
    FOR(test, 1, ntest) {
        FR(i, 4) cin >> a[i];
        string s = result();
        cout << "Case #" << test << ": " << s << endl;
    }
    return 0;
}
