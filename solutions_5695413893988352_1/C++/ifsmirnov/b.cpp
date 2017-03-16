#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef long long i64;
typedef pair<i64, i64> pii;
typedef unsigned long long u64;

const int maxn = 50;

string s, t;
int n;
pii best;

void relax(pii t) {
    i64 db = abs<i64>(best.fi - best.se);
    i64 dt = abs<i64>(t.fi - t.se);
    if (best.fi == -1 || tie(dt, t.fi, t.se) < tie(db, best.fi, best.se)) {
        best = t;
    }
}

i64 p10[maxn];

pii d[maxn][2];

void solve(int tn) {
    cin >> s >> t;
    n = s.size();
    p10[n-1] = 1;
    for (int i = n-2; i >= 0; --i) p10[i] = p10[i+1] * 10;
//     forn(i, n) cerr << p10[i] << " "; cerr << endl;

    best.fi = -1;
    forn(I, 2) {
        forn(i, n+1) d[i][0] = d[i][1] = {1e18, 1e18};
        d[0][0] = {0,0};
        forn(i, n) forn(r, 2) if (d[i][r].fi != 1e18) {
            forn(c1, 10) forn(c2, 10) {
                if (s[i] != '?' && s[i]-'0' != c1) continue;
                if (t[i] != '?' && t[i]-'0' != c2) continue;
                if (r == 0 && c2 > c1) continue;

                i64 nd = d[i][r].fi + (c1 - c2) * p10[i];
                i64 n1 = d[i][r].se + c1 * p10[i];
                int nr = (r == 1) | (c2 < c1);
                if (nd >= 0) d[i+1][nr] = min(d[i+1][nr], pii{nd, n1});
            }
        }

        forn(r, 2) {
            if (d[n][r].fi == 1e18) continue;
            i64 x = d[n][r].se;
            i64 y = x - d[n][r].fi;
            if (I) swap(x, y);
            relax({x, y});
        }
        swap(s, t);
    }

    cout << "Case #" << tn << ": " << setw(n) << setfill('0') << best.fi << " " <<
        setw(n) << setfill('0') << best.se << endl;
}

int main() {
#ifdef LOCAL
//     freopen("b.in", "r", stdin);
#endif

    int t;
    cin >> t;
    forn(i, t) solve(i+1);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
