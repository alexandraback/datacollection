#include <bits/stdc++.h>
using namespace std;


#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int N = 1010;

int n, p[N];
bool vis[N];
vi adj[N];

int dfs(int u, int p) {
    int res = 0;
    for (int v : adj[u]) if (v != p) 
        res = max(res, dfs(v,u));
    return ++res;
}

int cycle(int u) {
    int v = u, len = 0;
    forn(_,n+2) {
        v = p[v];
        len++;
        if (v == u) return len;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int ncas; cin >> ncas;
    forn(cas, ncas) {
        cout << "Case #" << cas+1 << ": ";
        cin >> n;
        forn(u,n) adj[u].clear();
        fill_n(vis, n, false);
        forn(i,n) {
            cin >> p[i], p[i]--;
            adj[p[i]].pb(i);
        }

        int lines = 0;
        forn(u,n) if (!vis[u] && p[p[u]] == u) {
            int v = p[u];
            vis[u] = vis[v] = true;
            lines += dfs(u,v) + dfs(v,u);
        }

        int ans = 0;
        forn(u,n) ans = max(ans, cycle(u));
        ans = max(ans, lines);
        cout << ans << endl;
    }
    return 0;
}
