#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

const int N = 55;
int a[N], b[N];
vector <ll> v16;
vector<pair <ll, ll> > v32;
bool d[N][N];

int divisor(ll n) {
	for(int x = 2; (ll)x * x <= n; x++)
		if(n % x == 0) return x;
	return -1;
}

ll getNum(int *a, int base, int n) {
	ll ret = 0;
	for(int i = n - 1; ~i; i--) {
		ret *= base;
		ret += a[i];
	}
	return ret;
}

void geta(int x, int *a, int &tot) {
	tot = 0;
	do {
		a[tot++] = x & 1;
		x >>= 1;
	}while(x);
}

int main() {
	freopen("outc.txt", "w", stdout);
	int T, n, m, tx, ty;
	for(int x = 1 << 15; x < (1 << 16); x++) {
		int tot;
		geta(x, a, tot);
		bool f = x & 1;
		for(int base = 2; base <= 10; base++) {
			ll num = getNum(a, base, tot);
			if(divisor(num) == -1) f = 0;
		}
		if(f) {
			v16.push_back(x);
		//	Debug(v16.size());
		}
		if(v16.size() == 50) break;
	}

	int edges = 0;
	for(ll x : v16)
		for(ll y: v16) {
			bool ok = 1;
			int tx, ty;
			geta(x, a, tx);
			geta(y, b, ty);
			for(int base = 2; base <= 10; base++) {
				ll nx = getNum(a, base, tx);
				ll ny = getNum(b, base, ty);
				ll gcd = __gcd(nx, ny);
				if(gcd == 1 || gcd == nx || gcd == ny ) ok = 0;
			}
			if(ok) {
				edges++;
				v32.push_back({x, y});
			}
		}

	scanf("%d", &T);
	scanf("%d%d", &m, &n);
	puts("Case #1:");
	For(i, 500) {
		geta(v32[i].first, a, tx);
		geta(v32[i].second, b, ty);
		for(int i = 15; ~i; i--) printf("%d", a[i]);
		for(int i = 15; ~i; i--) printf("%d", b[i]);
		for(int base = 2; base <= 10; base++) {
			ll nx = getNum(a, base, tx);
			ll ny = getNum(b, base, ty);
			printf(" %d", __gcd(nx, ny));
		}
		puts("");
	}

	return 0;
}

