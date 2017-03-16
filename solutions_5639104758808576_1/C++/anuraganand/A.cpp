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

const int maxS = 1010;
char people[maxS];

inline void solve() {
    int n;
    gi(n);
    scanf("%s", people);
    int standing = 0, ans = 0;

    for (int i = 0; i <= n; ++i) {
        int p = people[i] - '0';
        if (p > 0) {
            if (standing < i) {
                ans += i - standing;
                standing += i - standing;
            }
            standing += p;
        }
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