#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <ctime>
#include <cstring>
#include <sstream>

//#include <unordered_map>
//#include <unordered_set>


using namespace std;

//types
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<pii> vpii;

// for
#define FI(n) for(int i=0; i<n; i++)
#define FI1(n) for(int i=1; i<=n; i++)
#define FJ(n) for(int j=0; j<n; j++)
#define FJ1(n) for(int j=1; j<=n; j++)
#define FK(n) for(int k=0; k<n; k++)
#define FU(i, n) for (int i=0; i<n; i++)
#define F(i, s, e) for (int i=s; i<=e; i++)

//scanf types
#define SI(x) scanf("%d", &x)
#define SII(x, y) scanf("%d %d", &x, &y)
#define SIII(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define SIIII(x, y, z, t) scanf("%d %d %d %d", &x, &y, &z, &t)
#define SD(x) scanf("%lf", &x)
#define SP(x) scanf("%d %d", &x.first, &x.second)
#define SS(x) scanf("%s", &x)
#define SA(x, n) FI(n) SI(x[i])
#define SAA(x, n, m) FI(n) FJ(m) SI(x[i][j])

#define Tests(t) int t; SI(t); for(int test=1; test<=t; test++)
#define WS(n) int n; while(SI(n) != EOF)

//scanf with def
#define DI(x) int x; SI(x)
#define DII(x, y) int x, y; SII(x, y);
#define DIII(x, y, z) int x, y, z; SIII(x, y, z);
#define DD(x) double x; SD(x)
#define DS(x) string s; cin>>s
#define DA(a, n) int n; SI(n); SA(a, n);
#define DA2(a, n) int n; SI(n); SAA(a, n, n)
#define DAA(a, n, m) int n, m; SII(n, m); SAA(a, n, m)
#define TESTS DI(tests); FU(test, tests)

//input & files
#define FR(x) freopen(x, "rt", stdin)
#define FW(x) freopen(x, "wt", stdout)
#define FRW(x, y) FR(x); FW(y)
#define UNSYNC() ios::sync_with_stdio(false)

//output && db
#define DB(x) cout<<#x<<" = "<<(x)<<" ";
#define DBN(x) cout<<#x<<" = "<<(x)<<"\n";
#define DBA(x, n) {cout<<#x<<" = [ "; FI(n) cout<<x[i]<<((i+1==n)?" ]":", ");}
#define DBV(x) {cout<<#x<<" = [ "; int i = 0, n = x.size(); for(auto c:x) { cout<<c<<((i+1==n)?" ]":", "); i++;}}

#define PI(x) printf("%d", x)
#define PIS(x) printf("%d ", x)
#define PIN(x) printf("%d\n", x)
#define PA(x, n) {FI(n) if (i+1==n) PIN(x[i]); else PIS(x[i]);}
#define PV(x) PA(x, x.size())
#define PS(x) for (auto it: x) cout<<it<<" ";
#define PLN() putchar('\n');

#define D_EQ(l, r, p) (r-l <= p)
#define D_EQ6(l, r) D_EQ(l, r, 1e-6)
#define D_EQ9(l, r) D_EQ(l, r, 1e-9)

#define PREC(N) cout.precision(N), cout.setf(cout.fixed)


//algorithm
#define REV(a) reverse(a.begin(), a.end())
#define REVA(a, n) reverse(a, a+n);

//consts
const int INF = 1000001000;
const int mod = 1000 * 1000 * 1000 + 7;
const int mod9 = 1000 * 1000 * 1000 + 9;
const double PI = 3.1415926535897932;

//pair
#define x first
#define y second

//functions
double sqr(double x) { return x*x; };
ld sqr(ld x) { return x*x; };
ll sqr(ll x) { return x*x; };
ll sqr(int x) { return x * 1LL * x; };

ll gcd(ll a, ll b) { while (b) a %= b, swap(a, b); return a; }
ll bpm(ll a, ll n = -2, ll m = mod) { n = n >= 0 ? n : m + n; ll r = 1; while (n) { if (n & 1) r = (r*a) % m; a = (a*a) % m; n >>= 1; } return r; }
ll dist(ll x1, ll y1, ll x2, ll y2) { return sqr(x1 - x2) + sqr(y1 - y2); }


//operators
std::ostream& operator << (std::ostream& os, pii p) {
	return os << "{" << p.x << " " << p.y << "}";
}

typedef pair<pii, int> ppi;

#define SLL(x) scanf("%I64d", &x)
#define SAL(a, n) FI(n) SLL(a[i])
#define DLL(x) ll x; SLL(x);

const int N = 100005;

string C, J; ll mn;
ll val(string& x) {
	ull r = 0;
	for (int d : x) {
		r = r * 10 + d - '0';
	}
	return r;
}

string fill9(string& x) {
	for (char& a : x) {
		a = (a == '?') ? '9' : a;
	}
	return x;
}

string fill0(string& x) {
	for (char& a : x) {
		a = (a == '?') ? '0' : a;
	}
	return x;
}

ll dif(string& a, string& b) {
	return abs(val(a) - val(b));
}

void check(string& a, string& b) {
	ll df = dif(a, b);
	if (df < mn) {
		mn = df;
		C = a;
		J = b;
	}
}

void dfs(int i, string a, string b) {
	//DB(i); DB(a); DBN(b);
	if (i == a.length()) {
		check(a, b);
		return;
	}

	if (a[i] != '?' && b[i] != '?') {
		if (a[i] == b[i]) {
			dfs(i + 1, a, b);
		}
		else {
			if (a[i] < b[i]) {
				fill9(a);
				fill0(b);
			}
			else {
				fill9(b);
				fill0(a);
			}
			check(a, b);
		}
	} else
	if (a[i] == '?' && b[i] == '?') {
		string a1 = a, b1 = b;
		a1[i] = b1[i] = '0';
		dfs(i + 1, a1, b1);
		string a2 = a, b2 = b;
		a2[i] = '0';
		b2[i] = '1';
		dfs(i, a2, b2);

		a2 = a, b2 = b;		
		a2[i] = '1';
		b2[i] = '0';
		dfs(i, a2, b2);
	}
	else if (a[i] == '?') {
		if (b[i] != '0') {
			a[i] = b[i] - 1;
			dfs(i, a, b);
		}
		a[i] = b[i];
		dfs(i+1, a, b);
		if (b[i] != '9') {
			a[i] = b[i] + 1;
			dfs(i, a, b);
		}
	}
	else {
		if (a[i] != '0') {
			b[i] = a[i] - 1;
			dfs(i, a, b);
		}
		b[i] = a[i];
		dfs(i + 1, a, b);
		if (a[i] != '9') {
			b[i] = a[i] + 1;
			dfs(i, a, b);
		}
	}


}


void solve(string a, string b) {
	mn = LLONG_MAX;
	dfs(0, a, b);
	cout << C << " " << J;
}

int main() {
	// your code goes here	
	FRW("input.txt", "output.txt");	

	UNSYNC();

	int n; cin >> n;
	FI(n) {
		string x, y;
		cin >> x >> y;
		cout << "Case #" << i+1 << ": ";
		solve(x, y);
		cout << "\n";
	}

	return 0;
}