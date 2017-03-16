#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define sz(x) (int)x.size()

typedef pair<int, int> II;
const int inf = 1e9;
const int Nmax = 100100;

int a[Nmax], n, v, c, res, dd[33];
bool f[33][33];

void check(){
    FOR(i, 0, n) FOR(j, 0, v) f[i][j] = 0;
    f[0][0] = 1;
    FOR(i, 0, n - 1) FOR(j, 0, v) if (f[i][j]) {
        f[i + 1][j] = 1;
        if (a[i + 1] + j <= v) f[i + 1][a[i + 1] + j] = 1;
    }
    FOR(i, 1, v) if (f[n][i] == 0) return;
    res = min(res, n);
}

void Try(int i, int cnt) {
    if (cnt >= 5 || i == v + 1) {
        check();
        return;
    }
    if (n >= res) return;
    Try(i + 1, cnt);
    if (dd[i] == 0) {
        a[++n] = i;
        Try(i + 1, cnt + 1);
        n--;
    }
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int test;
    cin >> test;
    FOR(t, 1, test) {
        cin >> c >> n >> v;
        FOR(i, 1, v) dd[i] = 0;
        FOR(i, 1, n) {
            cin >> a[i];
            dd[a[i]] = 1;
        }
        res = v;
        Try(1, 0);
        printf("Case #%d: %d\n", t, res - n);
    }
    return 0;
}
