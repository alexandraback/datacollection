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

const int maxD = 1010;
int a[maxD];

inline void solve() {
    int n;
    gi(n);

    rep (i, n) gi(a[i]);

    int high = a[0];
    rep (i, n) high = max(high, a[i]);

    int ans = high;

    for (int m = 1; m <= high; ++m) {
        int special = 0;
        rep (i, n) {
            if (a[i] > m) {
                special += (a[i] - 1) / m;
            }
        }
        ans = min(ans, special + m);
    }

    printf("%d\n", ans);
    fprintf(stderr, "%d\n", ans);
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