#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, f) for(__typeof(f.begin()) i = f.begin(); i != f.end(); i++)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define getbit(x, i) ((x >> (i-1)) & 1LL)
#define onbit(x, i) (x | (1LL << (i-1)))
#define offbit(x, i) (x & ~(1 << (i-1)))
#define lim 1000000

ll n;
int ntest, f[1000001];
queue<int> q;
map<ll, ll> ff;

void init() {
    reset(f, 0x7f);
    f[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x < lim && f[x+1] > f[x] + 1) {
            f[x+1] = f[x] + 1;
            q.push(x+1);
        }
        int y = 0, xx = x;
        while (xx) y = y * 10 + (xx % 10), xx /= 10;
        if (f[y] > f[x] + 1) {
            f[y] = f[x] + 1;
            q.push(y);
        }
    }
}

ll solve(ll x) {
    if (x == 1) return 1;
    if (ff[x]) return ff[x];
    ll xx = x, y = 0;
    while (xx) y = y * 10 + (xx % 10), xx /= 10;
    ll res = x;
    if (y < x && x % 10) {
        res = min(res, solve(y) + 1);
        xx = y; ll cost = (y % 10) - 1, mu = 1;
        xx /= 10;
        if (cost && y - cost < x) res = min(res, solve(y - cost) + cost + 1);
        while (xx) {
            mu *= 10; cost += mu * (xx % 10); xx /= 10;
            if (cost) res = min(res, solve(y - cost) + cost + 1);
        }
    } else res = min(res, solve(x-1) + 1);
    ff[x] = res;
    return res;
}

int main() {
    freopen("input.txt","r",stdin);
   // freopen("output.out","w",stdout);
    cin >> ntest;
    init();
    For(test, 1, ntest) {
        printf("Case #%d: ", test);
        cin >> n;
        //if (n <= lim) cout << f[n] << endl;
        //else
        ff.erase(all(ff));
        cout << solve(n) << endl;
    }
}


