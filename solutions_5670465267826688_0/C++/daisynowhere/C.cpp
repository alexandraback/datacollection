#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;

const int mat[4][4] = {
    {1, 2, 3, 4},
    {2, 1, 4, 3},
    {3, 4, 1, 2},
    {4, 3, 2, 1}
};

const int sgn[4][4] = {
    {1, 1, 1, 1},
    {1, -1, 1, -1},
    {1, -1, -1, 1},
    {1, 1, -1, -1}
};

int Tc, n;
ll X;

int trans(char ch) {
    switch (ch) {
        case 'i': return 2;
        case 'j': return 3;
        case 'k': return 4;
    }
    throw 0;
}

int getSgn(int x) {
    return x > 0 ? 1 : -1;
}

bool gao(const string &s) {
    //cout << "gao " << s << endl;
    n = s.size();
    int firstI = -1, lastK = -1;
    int res = 1;
    for (int i = 0; i < n; i++) {
        int sg = sgn[abs(res) - 1][trans(s[i]) - 1] * getSgn(res);
        int nu = mat[abs(res) - 1][trans(s[i]) - 1];
        res = sg * nu;
        //cout << "res = " << res << endl;
        if (res == 2) {
            firstI = i;
            break;
        }
    }
    res = 1;
    for (int i = n - 1; ~i; i--) {
        int sg = sgn[trans(s[i]) - 1][abs(res) - 1] * getSgn(res);
        int nu = mat[trans(s[i]) - 1][abs(res) - 1];
        res = sg * nu;
        if (res == 4) {
            lastK = i;
            break;
        }
    }
    //cout << firstI << " " << lastK << endl;
    return firstI != -1 && lastK != -1 && firstI + 1 < lastK;
}

int calc(const string &s) {
    n = s.size();
    int res = 1;
    for (int i = 0; i < n; i++) {
        int sg = sgn[abs(res) - 1][trans(s[i]) - 1] * getSgn(res);
        int nu = mat[abs(res) - 1][trans(s[i]) - 1];
        res = sg * nu;
    }
    return res;
}

int main() {
    scanf("%d", &Tc);
    rep (ri, Tc) {
        printf("Case #%d: ", ri + 1);
        cin >> n >> X;
        string s;
        cin >> s;
        if (X >= 32) X = X % 32 + 32;
        string cur = "";
        rep (i, X) cur += s;
        if (calc(cur) != -1) {
            puts("NO");
        } else {
            puts(gao(cur) ? "YES" : "NO");
        }
    }
}

