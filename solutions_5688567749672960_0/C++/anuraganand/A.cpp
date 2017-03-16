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

const int maxN = 1000100;

int dp[maxN];

int reverse(int n) {
    int m = 0;
    while (n > 0) {
        m = m * 10 + (n % 10);
        n /= 10;
    }
    return m;
}

int getMin(int cur, int target) {
    if (cur == target) return 1;
    int & ret = dp[cur];
    if (~ret) return ret;
    ret = 1 + getMin(cur + 1, target);
    int rev = reverse(cur);
    if (rev > cur and rev <= target) ret = min(ret, 1 + getMin(rev, target));
    return ret;
}

inline void solve() {
    int n;
    scanf("%d", &n);
    mset(dp, -1);
    int ans = getMin(1, n);
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