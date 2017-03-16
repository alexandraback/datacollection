#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <utility>
#include <sstream>
#include <numeric>

#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(v) do{cerr<<#v<<':';for(auto x:v) cerr << x << ','; cerr << '\n';}while(0)
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ford1(i, n) for(int i = (int)(n); i>=1; --i)
#define fored(i, a, b) for(int i = (int)(b); i >= (int)(a); --i)
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define clr(v) memset(v, 0, sizeof(v))
#define clr1(v) memset(v, 0xFF, sizeof(v))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define op operator

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef long long i64;
typedef unsigned long long u64;	
typedef long double ld;

const int MOD = 1000000007;

int popcnt(int x) { return __builtin_popcount(x);}
int popcnt(u64 x) { return __builtin_popcountll(x);}
int ctz(int x) { return __builtin_ctz(x);}
int ctz(u64 x) { return __builtin_ctzll(x);}
int clz(int x) { return __builtin_clz(x);}
int clz(u64 x) { return __builtin_clzll(x);}
int ffs(int x) { return __builtin_ffs(x);}
int ffs(u64 x) { return __builtin_ffsll(x);}
int parity(int x) { return __builtin_parity(x);}
int parity(u64 x) { return __builtin_parityll(x);}
double powi(double x, int i) { return __builtin_powi(x,i); }
float powi(float x, int i) { return __builtin_powif(x,i); }
long double powi(long double x, int i) { return __builtin_powil(x,i); }
int gcd(int a, int b) { return __gcd(a,b); }
i64 gcd(i64 a, i64 b) { return __gcd(a,b); }
int lcm(int a, int b) { return a/__gcd(a,b)*b; }
i64 lcm(i64 a, i64 b) { return a/__gcd(a,b)*b; }

int add(int a, int b) { a += b; if(a>=MOD) a-= MOD; return a; }
int sub(int a, int b) { a -= b; if(a<0) a+= MOD; return a; }
int mul(int a, int b) { return (a*1ll*b) % MOD; }
inline int pow(int a, i64 n) { int r(1); while(n) { if(n&1) r=mul(r,a); n/=2; if(n)a=mul(a,a);} return r; }

inline bool randb() {
    static int x, pos = -1;
    if(pos==-1) { pos = 30; x = rand(); }
    return (x>>(pos--))&1;
}

template<class T> bool uax(T&a, const T& b) {
	if( a < b ) { a = b; return true; }
	return false;
}

template<class T> bool uin(T&a, const T& b) {
	if( a > b ) { a = b; return true; }
	return false;
}

const ld pi = acosl(-1.0);
const ld eps = 1e-9;

const int N = 120;

vi g[N];
vi ans;
int c[N];
int p[N];

int can1[N];
int n;

bool can(int v, int v0) {
    //cerr << v << ' ' << v0 << '\n';
    vi tmp2;
    while( !binary_search( all(g[v0]), v ) ) {
        tmp2.pb(v0);
        v0 = p[v0];
    }
    vi u(n);
    forn(i, n) if( c[i] != 0 ) u[i] = 1;
    function<void(int)> f = [&](int v) {
        u[v] = 1;
        for(int z: g[v] ) if( !u[z] ) f(z);
    };
    p[v] = v0;
    while( v != -1 ) {
        f(v); v = p[v];
    }
    forn(i, n) if( !u[i] ) { p[v] = -1; return false; }
    for(int z: tmp2) c[z] = 2; 
    return true;
}

void dfs(int v) {
    //cerr << "dfs+ " << v << '\n';
    ans.pb(v);
    c[v] = 1;
    forn(i, n) can1[i] = false;
    forn(i, n) if( c[i] == 1 ) for(int z: g[i]) if( !c[z] ) can1[z] = true;
    forn(i, n) if( can1[i] && can(i, v) ) {
        dfs(i);
    }
    c[v] = 2;
    //cerr << "dfs- " << v << '\n';
}

void solve() {
    int m;
    cin >> n >> m;
    vector<pair<string,int> > v(n);
    forn(i, n) { cin >> v[i].fi; v[i].se = i; }
    sort(all(v));
    vi p(n);
    forn(i, n) p[ v[i].se ] = i;
    forn(i, n) g[i].clear();
    forn(j, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        a = p[a]; b = p[b];
        //cerr << a << ' ' << b << '\n';
        g[a].pb(b);
        g[b].pb(a);
    }
    forn(i, n) sort(all(g[i]));
    forn(i, n) c[i] = 0;
    forn(i, n) ::p[i] = -1;
    forn(i, n) can1[i] = 0;
    ans.clear();
    dfs(0);
    assert( ans.size() == n );
    forn(i, n) cout << v[ans[i]].fi; cout << '\n';
    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(15);
	cerr << fixed;
	cerr.precision(15);
    int T; cin >> T;
    forn(t, T) {
        cout << "Case #" << t+1 << ": ";
        solve();
    }
    return 0;
}
