#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5 + 8;
const long double pi = M_PI;
//const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned int ui;
typedef double db;
typedef long double ld;
typedef int arr[mn];
typedef char arc[mn];
typedef bool arb[mn];
typedef double ard[mn];
#define mp make_pair
#define ft first
#define sd second
#define pb push_back
#define Travel(x) for (Edge *i = h[x]; i; i = i->n) 
#define lowbit(x) (x & (-x))
#define sqr(x) ((x) * (x))
#define runtime ((double)clock() / CLOCKS_PER_SEC)
#define rep(x, l, r) for (int x = l; x < r; x++)
#define per(x, r, l) for (int x = r - 1; x >= l; x--)

inline int gi() {
	int pos = 1, res = 0; char c;
	do c = getchar();
	while (!isdigit(c) && c != '-');
	if (c == '-') pos = -1, c = getchar();
	while (isdigit(c))
		res = (res << 1) + (res << 3) + c - '0', c = getchar();
	return res * pos;
}
inline void gg(int &x) {x = gi();}
/*
inline int rd() {return  rand() * rand() + rand();}
inline int Rd(int n) {return rd() % n + 1;}
*/

/*
inline ll Power(ll x, int q) {
	if (!x) return  0;
	ll res = 1;
	while (q) {
		if (q & 1) res = res * x % mod;
		q >>= 1; x = x * x % mod; 
	}
	return res;
}

ll Gcd(ll a, ll b) {return b ? Gcd(b, a % b) : 0;} 
*/


/*struct Edge {Edge *n; int v; Edge() {}} *h[mn];
inline void AE(int u, int v) 
	{Edge *x = new Edge(); x->v = v; x->n = h[u]; h[u] = x;}
*/
int n, ans, p[1008];
void Check(int x) {
	int res = x;
	for (int i = 1; i <= n; i++) 
		res += (p[i] - 1) / x;
	ans = min(ans, res);
}
void Solve() {
	scanf("%d", &n); ans = 1e9;
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	for (int i = 1; i <= 1000; i++) Check(i);
	cout << ans << endl;
}
int main() {


	int _; cin >> _;
	rep(i, 1, _ + 1) 
		printf("Case #%d: ", i), Solve();
	fclose(stdin); fclose(stdout);
	return 0;
}