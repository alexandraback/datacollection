#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i, x, y) for(int i = x; i < y; ++ i)
#define pb push_back
#define mk make_pair

const int N = 55;
int n, m;
int a[N], d[N];
vector<int> prime;

int check6() {
	for (int x : prime) {
		int b = 1;
		int z = 0;
		FOR(i, 0, n)
		{
			z = (z + b * a[i]) % x;
			b = b * 6 % x;
		}
		if (z == 0)
			return x;
	}
	return -1;
}

void dfs(int t, int x, int s23) {
	if (m == 0)
		return;
	if (t == 4) {
		if (s23 % 3 == 0) {
			int res = check6();
			if (res > 0) {
				--m;
				d[6] = res;
				FOR(i, 0, n)
					printf("%d", a[i]);
				FOR(i, 2, 11)
					printf(" %d", d[i]);
				puts("");
			}
		}
		return;
	}
	FOR(i, x, n-1)
	{
		a[i] = 1;
		dfs(t + 1, i + 1, s23 + (i & 1 ? 2 : 1));
		a[i] = 0;
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i,0,n)
		a[i] = 0;
	a[0] = a[n - 1] = 1;
	FOR(i,2,11)
		d[i] = i & 1 ? 2 : 3;
	int s23 = 1 + (n & 1 ? 1 : 2);
	dfs(0, 1, s23);
	assert(m == 0);
}

int main() {
#ifdef LOCAL
	freopen("in","r",stdin);
#endif
	int MAX = 100;
	FOR(i, 2, MAX)
	{
		bool flag = true;
		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0)
				flag = false;
		if (flag)
			prime.pb(i);
	}

	int T, Case = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d:\n", ++Case);
		solve();
	}
	return 0;
}
