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

const int maxL = 200200;
char s[maxL];
int a[maxL];
int dp[maxL][3][4][2];
int hash[128];

int val[4][4] = {   
                    {0, 1, 2, 3},
                    {1, 0, 3, 2},
                    {2, 3, 0, 1},
                    {3, 2, 1, 0}
                };

int sign[4][4] = {
                    {1,  1,  1,  1},
                    {1, -1,  1, -1},
                    {1, -1, -1,  1},
                    {1,  1, -1, -1}
                };

int can(int idx, int state, int curVal, bool isPos, int n) {
    if (idx == n) {
        return state == 2 and curVal == 3 and isPos;
    }

    int & ret = dp[idx][state][curVal][isPos];
    if (~ret) return ret;
    ret = false;

    if (sign[curVal][a[idx]] == -1) isPos ^= true;
    curVal = val[curVal][a[idx]];

    if (can(idx + 1, state, curVal, isPos, n)) return ret = true;
    if (isPos and state < 2) {
        if (curVal == state + 1) {
            if (can(idx + 1, state + 1, 0, true, n)) return ret = true;
        }
    }
    return ret;
}

inline void solve() {
    int n; ll x;
    gi(n), scanf("%lld", &x);

    scanf("%s", s);
    rep (i, n) a[i] = hash[s[i]];

    for (int i = n; i < 15 * n; ++i) {
        a[i] = a[i % n];
    }

    bool ok = false;

    for (int rep = 1; rep <= x and rep <= 15; ++rep) if ((x - rep) % 4 == 0) {
        mset(dp, -1);
        if (can(0, 0, 0, true, rep * n)) {
            ok = true;
            break;
        }
    }

    puts(ok ? "YES" : "NO");
    fprintf(stderr, ok ? "YES\n" : "NO\n");
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    hash['1'] = 0;
    hash['i'] = 1;
    hash['j'] = 2;
    hash['k'] = 3;

    srand(time(NULL));
    int T;
    gi(T);

    for (int tc = 1; tc <= T; ++tc) {
        printf("Case #%d: ", tc);
        fprintf(stderr, "Case #%d: ", tc);
        solve();
    }
    return 0;
}