#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt;
string s, t, x, y, xx, yy;
LL ansa, ansb;
const LL INF = 3e18;

bool inv;

void solve(string &x, string &y, int pos = 0, bool done = false) {
    if (pos == (int)x.length()) {
        LL a = ansa, b = ansb, c, d;
        istringstream iss(x + " " + y);
        iss >> c >> d;
        if (inv) swap(c, d);
        bool newAns = false;
        if (abs(a - b) != abs(c - d)) {
            if (abs(c - d) < abs(a - b)) {
                newAns = true;
            }
        } else if (a != c) {
            if (c < a) {
                newAns = true;
            }
        } else {
            if (d < b) {
                newAns = true;
            }
        }
        if (newAns) {
            xx = x;
            yy = y;
            ansa = c;
            ansb = d;
            if (inv) swap(xx, yy);
        }
        return;
    }
    char sx = x[pos];
    char sy = y[pos];
    if (done) {
        if (x[pos] == '?') x[pos] = '0';
        if (y[pos] == '?') y[pos] = '9';
        solve(x, y, pos + 1, true);
        x[pos] = sx;
        y[pos] = sy;
        return;
    }
    if (x[pos] == '?' && y[pos] == '?') {
        x[pos] = '0';
        y[pos] = '0';
        solve(x, y, pos + 1, false);
        x[pos] = '1';
        y[pos] = '0';
        solve(x, y, pos + 1, true);
        x[pos] = sx;
        y[pos] = sy;
        return;
    }
    if (x[pos] == '?') {
        x[pos] = y[pos];
        solve(x, y, pos + 1, false);
        if (y[pos] != '9') {
            x[pos] = y[pos] + 1;
            solve(x, y, pos + 1, true);
        }
        x[pos] = sx;
        y[pos] = sy;
        return;
    }
    if (y[pos] == '?') {
        y[pos] = x[pos];
        solve(x, y, pos + 1, false);
        if (x[pos] != '0') {
            y[pos] = x[pos] - 1;
            solve(x, y, pos + 1, true);
        }
        x[pos] = sx;
        y[pos] = sy;
        return;
    }
    if (x[pos] > y[pos]) {
        solve(x, y, pos + 1, true);
    } else if (x[pos] == y[pos]) {
        solve(x, y, pos + 1, false);
    }
    x[pos] = sx;
    y[pos] = sy;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        printf("Case #%d: ", test);
        cin >> s >> t;
        x = s, y = t;
        ansa = INF, ansb = -INF;
        inv = false;
        solve(x, y);
        x = s, y = t;
        inv = true;
        solve(y, x);
        printf("%s %s\n", xx.c_str(), yy.c_str());
    }
    return 0;
}
