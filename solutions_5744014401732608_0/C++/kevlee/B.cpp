#include <bits/stdc++.h>
using namespace std;
int T, n,  m, b[1005], a[8][8], ans, coun;
bool vis[8];
void dfs(int x) {
	coun++;
	if (ans>m||coun>1000) return;
	if (x==n) {
		ans++;
		return;
	}
	for (int i=1; i<=n; i++) {
		if (a[x][i]) {
			dfs(i);
		}
		if (ans>m) return;
	}
}
void solve(int test) {
	scanf("%d %d", &n, &m);
	printf("Case #%d: ", test);
	int cnt=-1;
	memset(b, 0, sizeof b);
	for (int i=1; i<n; i++) {
		for (int j=2; j<=n; j++) {
			if (i!=j) {
				cnt++;
				b[cnt]=i*10+j;
			}
		}
	}
//	printf("%d\n", cnt);
cnt++;
	for (int i=0; i<(1<<cnt); i++) {
//		printf("%d\n",i);
		for (int j=1; j<=n; j++) for (int k=1; k<=n; k++) a[j][k]=0;
		for (int j=0; j<cnt; j++) {
			int x=b[j]/10, y=b[j]%10;
			if (i&(1<<j))a[x][y]=1;
		}
		bool ok=true;
		for (int j=1; j<=n; j++) if (a[j][n]) ok=false;
		

		if (ok) continue;
			ans=coun=0;
		dfs(1);
		if (ans==m) {
			printf("POSSIBLE\n");
			for (int j=1; j<=n; j++) {
				for (int k=1; k<=n; k++) printf("%d", a[j][k]);
				printf("\n");
			}
			return;
		}
	}
	printf("IMPOSSIBLE\n");
}
int main () {
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	scanf("%d", &T);
	for (int i=1; i<=T; i++) {
		solve(i);
	}
	return 0;
}
