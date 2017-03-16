#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define sz(x) (int)x.size()

typedef pair<int, int> II;
const int inf = 1e9;
const int Nmax = 100100;

double f[102][102][102], res;
int cnt[1111], next[1111];
string a, b;
int n, m, s;

void solve() {
    b = "#" + b;
    next[1] = 0;
    FOR(i, 2, m) {
        int j = next[i - 1];
        while (j > 0 && b[j + 1] != b[i]) j = next[j];
        if (b[j + 1] == b[i]) j++;
        next[i] = j;
    }

    FOR(i, 'A', 'Z') cnt[i] = 0;
    FOR(i, 0, n - 1) {
        cnt[a[i]]++;
    }
    memset(f, 0, sizeof f);
    f[0][0][0] = 1;
    FOR(i, 0, s - 1) FOR(j, 0, m - 1) {
        FOR(c, 'A', 'Z') if (cnt[c] > 0) {
            int j2 = j, ok = 0;
            while (j2 > 0 && b[j2 + 1] != c) j2 = next[j2];
            if (b[j2 + 1] == c) j2++;
            if (j2 == m) {
                j2 = next[j2];
                ok = 1;
            }
            FOR(k, 0, i) if (f[i][j][k] > 0) {
                f[i + 1][j2][k + ok] += f[i][j][k] * cnt[c] / n;
            }
        }
    }
    res = 0;
    int Max = 0;
    FOR(j, 0, m - 1) FOR(k, 1, s) if (f[s][j][k] > 0)
        Max = max(Max, k);
    //cout << Max << endl;
    FOR(j, 0, m - 1) FOR(k, 0, s) if (f[s][j][k] > 0){
        res += (Max - k) * f[s][j][k];
        //cout << k << ' ' << f[s][j][k] << endl;
    }

}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int test;
    cin >> test;
    FOR(t, 1, test) {
        cin >> n >> m >> s;
        cin >> a;
        cin >> b;
        solve();
        printf("Case #%d: %.9lf\n", t, res);
    }
    return 0;
}
