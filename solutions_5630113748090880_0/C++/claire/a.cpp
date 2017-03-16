#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
const int N = 110;
int a[N][N], d[N][N];
int c[N];
bool ff;

void dfs(int k, int n, int ans, int p) {
	/*cout<<k<<' ' <<n<<' '<<ans<<' '<<p<<endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}*/
	if (ff) return;
	if (k > n) {
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}*/
		if (ans > 0) {
			for (int i = 1; i <= n; i++)
				printf(" %d", a[ans][i]);
			
		}else {
			ans = -ans;
			for (int i = 1; i <= n; i++)
				printf(" %d", a[i][ans]);
		}
		ff = true;
		return;
	}
	if (p == 1) {
		for (int i = 1; i <= 2 * n - 1; i++) {
			if (c[i] == 1) continue;
			bool flag = true;
			for (int j = 1; j < k; j++)
				if (ans != -j && a[k][j] != d[i][j])
				{flag = false; break;}
			if (!flag) continue;
			if (k == 1 && a[k][1] != d[i][1]) continue;
			c[i] = 1;
			for (int j = 1; j <= n; j++)
				a[k][j] = d[i][j];
			dfs(k, n, ans, 0);
			c[i] = 0;
		}
		if (ans == 0) {
			dfs(k, n, k, 0);
		}
		
	} else {
		for (int i = 1; i <= 2 * n - 1; i++) {
			if (c[i] == 1) continue;
			bool flag = true;
			for (int j = 1; j <= k; j++)
				if (ans != j && a[j][k] != d[i][j])
				{flag = false; break;}
			if (!flag) continue;
			c[i] = 1;
			for (int j= 1; j <= n; j++)
				a[j][k] = d[i][j];
			dfs(k + 1, n, ans, 1);
			c[i] = 0;
		}
		if (ans == 0) {
			dfs(k + 1, n, -k, 1);
		}
	}
}

int main() {
	int o, cas = 0;
	scanf("%d", &o);
	while (o--) {
		int k = 30000;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n - 1; i++) {
			for (int j = 1; j <= n; j++)
				scanf("%d", &d[i][j]);
			k = min(k, d[i][1]);
		}
		memset(a, -1, sizeof(a));
		memset(c, 0, sizeof(c));
		a[1][1] = k;
		int ans = 0;
		printf("Case #%d:", ++cas);
		ff = false;
		dfs(1, n, ans, 1);
		printf("\n");
	}
}