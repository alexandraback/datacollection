#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mset(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define gi(x) scanf("%d", &x)
#define pis(x) printf("%d ", x)
#define pin(x) printf("%d\n", x)
#define pnl printf("\n")
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "

inline void solve() {
    int r, c, w;
    gi(r), gi(c), gi(w);

    int ans = (r - 1) * ((c / w));

    int extra = 11111;

    for (int i = 0; i < w; ++i) {
        int cur = 0;
        for (int j = i; j < c; j += w) {
            if (j > 0 and j < c - 1) {
                cur = max(cur, (j / w) + 1);
            } else {
                cur = max(cur, (j / w));
            }
        }
        extra = min(cur, extra);
    }

    ans += extra + w;

    fprintf(stderr, "%d\n", ans);
    pin(ans);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    gi(T);

    for (int tc = 1; tc <= T; ++tc) {
        printf("Case #%d: ", tc);
        fprintf(stderr, "Case #%d: ", tc);
        solve();
    }
    return 0;
}