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
    int x, r, c;
    gi(x), gi(r), gi(c);

    bool won = true;
    if (x == 1) {
        won = false;
    } else if (x == 2) {
        if ((r * c) % 2 == 0) won = false;
    } else if (x == 3) {
        if (r == 3 and c >= 2 or c == 3 and r >= 2) won = false;
    } else if(x == 4) {
        if (r == 4 and c >= 3 or c == 4 and r >= 3) won = false;
    } else {
        assert(false);
    }

    puts(won ? "RICHARD" : "GABRIEL");
    fprintf(stderr, won ? "RICHARD\n" : "GABRIEL\n");
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