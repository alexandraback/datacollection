#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define mp(a,b) make_pair(a,b)
#define F first
#define S second

#define all(x) x.begin(), x.end()
#define sqr(x) ((x)*(x))
#define eps 1e-8
#define inf (int)(1e9+7)
#define infll (ll)(1e18+3)
#define sz(x) ((int)x.size())

typedef long long ll;
typedef  double ld;
typedef vector < ll > vll;
typedef vector < int > vi;
typedef pair < ll, ll > pll;
typedef pair < int, int > pii;
typedef int huint;

const ld PI = acosl(-1);

const int N = 3003;

int g[N];
vector<vi> p;

int n, ans, kl,  f[N], h[N], xz, mh, mv;
void dfs(int v,int l) {
    h[v] = l, f[v] = kl;
    if (f[g[v]] == kl) {
        int s = l - h[g[v]] + 1;
        ans = max(s, ans);
        return;
    }
    if (!f[g[v]]) dfs(g[v], l + 1);
    
}

void find(int v, int h) {
    if (h > mh) mh = h, mv = v;
    for (int to : p[v]) {
        if (f[to]) continue;
        find(to, h + 1);
    }
}

void go(int v) {
    if (f[v] != 0) return;
    xz += 1;
    f[v] = 1;
    go(g[v]);
}


int main() {
#ifdef DEBUG
    freopen("/Users/rzmn/Documents/acm/acm/input.txt", "r", stdin);
    freopen("/Users/rzmn/Documents/acm/acm/output.txt", "w", stdout);
#else
    //freopen("gunman.in", "r", stdin);
    //freopen("gunman.out", "w", stdout);
#endif
    cout.precision(10);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    
    
    int test;
    cin >> test;
    for (int tt(1); tt <= test; tt++) {
        cin >> n;
        p.clear();
        p.resize(n);
        fill(f, f+N, 0);
        ans = 1;
        kl = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x--;
            g[i] = x;
            p[x].pb(i);
        }
        for (int i = 0; i < n; i++) if (!f[i]) kl++, dfs(i, 1);
        for (int i = 0; i < n; i++)
            f[i] = 0;
        for (int i = 0; i < n; i++) {
            int v = g[i];
            if (i == g[v])
                f[i] = f[v] = 2;
        }
        xz = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] != 2) continue;
            xz += 1;
            f[i] = 3;
            mh = -1; mv = -1;
            find(i, 0);
            go(mv);
        }
        ans = max(ans, xz);
        
        cout << "Case #" << tt << ": " << ans << "\n";
        
    }
    
    
    
    
    
    
    
#ifdef DEBUG
    cerr << "\n == TIME : " << clock() / ld(CLOCKS_PER_SEC) << " == " << endl;
#endif
}