/*
ID: tahsynx1
LANG: C++
TASK: 
*/

#include <bits/stdc++.h>
using namespace std;

//typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> pll;
const double PI = acos(-1);

//defines
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a)*(a))
#define inf 100000000
#define mod 1000000007
#define mod1 1000000007
#define mod2 1000000009
#define b1 43
#define b2 41
#define EPS 1e-9
//define harmonic(n) 0.57721566490153286l+log(n)
#define nl puts("")
#define odd(n) (n&1)
#define even(n) (!(n&1))
#define vsort(v) sort(v.begin(), v.end())
#define lc (node<<1)
#define rc ((node<<1)|1)

//loop
#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, n) for(int i = 1; i <= n; ++i)

//input
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define sd(a) scanf("%lf", &a)
#define sc(a) scanf("%c", &a)
#define sst(a) scanf("%s", a)

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

//debug
#ifdef tahsin
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) { return os << "(" << p.first << ", " << p.second << ")"; }

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) { os << "{";
	for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it; }
    return os << "}"; }

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) { os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it; }
    return os << "]"; }

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) { os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ; }
    return os << "]"; }

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () { cerr << endl; }

template <typename T>
void faltu( T a[], int n ) { for(int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl; }

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

#else
#define dbg(args...)
#endif

ll bigmod(ll a, ll b) {
	ll ret = 1;
	while(b) { if(b&1) ret = (ret*a)%mod; b >>= 1; a = (a*a)%mod; }
	return ret;
}

ll inverse(ll n) { return bigmod(n, mod-2); }

//Direction Array 
//int fx[]={1, -1, 0, 0}; int fy[]={0, 0, 1, -1};
//int fx[]={0, 0, 1, -1, -1, 1, -1, 1}; int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};

//bit manipulation
bool checkBit(int n, int i) { return (n&(1<<i)); }
int setBit(int n, int i) { return (n|(1<<i)); }
int resetBit(int n, int i) { return (n&(~(1<<i))); }
//end of template

//#define MX 
int n;
char a[10], b[10];

void gen1(int i, int m, vi &v) {
	if(i == n) {
		v.PB(m);
		return;
	}

	if(a[i] == '?') {
		rep(j, 10) gen1(i+1, m*10+j, v);
	}
	else gen1(i+1, m*10 + a[i]-'0', v);
}

void gen2(int i, int m, vi &v) {
	if(i == n) {
		v.PB(m);
		return;
	}

	if(b[i] == '?') {
		rep(j, 10) gen2(i+1, m*10+j, v);
	}
	else gen2(i+1, m*10 + b[i]-'0', v);
}


int main () {
#ifdef tahsin
//	freopen("out", "w", stdout);
#endif
	int t;

	si(t);

	REP(cs, t) {
		sst(a);
		sst(b);

		n = strlen(a);

		vi A, B;

		gen1(0, 0, A);
		gen2(0, 0, B);

		piii mn = {inf, {0, 0}};
		for(int &u: A) for(int &v: B) {
			int diff = abs(u-v);
			if(diff < mn.F) mn = {diff, {u, v}};
			else if(diff == mn.F) {
				if(u < mn.S.F) mn = {diff, {u, v}};
				else if(u == mn.S.F && v < mn.S.S) mn = {diff, {u, v}};
			}
		}

		string c = "";
		rep(i, n) {
			c += mn.S.F%10 + '0';
			mn.S.F /= 10;
		}
		string d = "";
		rep(i, n) {
			d += mn.S.S%10 + '0';
			mn.S.S /= 10;
		}

		reverse(c.begin(), c.end());
		reverse(d.begin(), d.end());
		printf("Case #%d: %s %s\n", cs, c.c_str(), d.c_str());
	}

//	timeStamp;
	return 0;
}

