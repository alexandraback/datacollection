#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

const int N = 55;
int a[N];
vector <int> v16, v32;

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
	int T, n, m;
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

	scanf("%d", &T);
	scanf("%d%d", &m, &n);
	puts("Case #1:");
	for(ll x : v16) {
		int tot;
		geta(x, a, tot);
		for(int i = 15; ~i; i--) printf("%d", a[i]);
		for(int b = 2; b <= 10; b++) {
			ll num = getNum(a, b, tot);
			printf(" %d", divisor(num));
		}
		puts("");
	}


	return 0;
}
