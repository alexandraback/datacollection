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

int n; char s[1008];
void Solve() {
	scanf("%d", &n); scanf("%s", s);
	rep(i, 0, n + 1) s[i] -= '0';
	int cnt = 0, ans = 0;
	rep(i, 0, n + 1) {
		if (s[i] && i > cnt) 
			ans += i - cnt, cnt = i;
		cnt += s[i];
	}
	printf("%d\n", ans);
}
int main() {
	int _; cin >> _;
	rep(i, 1, _ + 1) 
		printf("Case #%d: ", i), Solve();
	fclose(stdin); fclose(stdout);
	return 0;
}
