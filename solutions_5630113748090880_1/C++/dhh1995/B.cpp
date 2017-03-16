#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i, x, y) for(int i = x; i < y; ++ i)
#define pb push_back
#define mk make_pair

const int N = 105;
int a[N][N], ans[N];
vector<int> c[N];
int n;

bool check() {
	FOR(j,1,n)
		if (a[0][j] == a[0][j - 1])
			return false;
	return true;
}

void solve() {

	scanf("%d", &n);
	FOR(j,0,n)
		c[j].clear();
	FOR(i,1,2*n)
	{
		FOR(j,0,n)
			scanf("%d", a[i] + j), c[j].pb(a[i][j]);
	}
	FOR(j,0,n)
		sort(c[j].begin(), c[j].end());
	FOR(j,0,n)
	{
		FOR(i,1,2*n)
		{
			bool flag = true;
			int m = 0, t = 0;
			FOR(k, 0, n)
			{
				while (t < 2 * n - 1 && c[j][t] != a[i][k]) {
					m += m == j;
					a[0][m++] = c[j][t++];
				}
				if (t == 2 * n - 1) {
					flag = false;
					break;
				}
				++t;
			}
			if (flag) {
				while (t < 2 * n + 1) {
					m += m == j;
					a[0][m++] = c[j][t++];
				}
				a[0][j] = a[i][j];
				if (check()) {
					FOR(j,0,n)
						ans[j] = a[0][j];
				}
			}
		}
	}

	FOR(j,0,n)
		printf(" %d", ans[j]);
	puts("");
}


int main() {
#ifdef LOCAL
	freopen("in","r",stdin);
#endif
	int T, Case = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d:", ++Case);
		solve();
	}
	return 0;
}
