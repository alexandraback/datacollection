#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

int n, m;
const int N = 55;
ll pow2[N];
int vis[N][N];

int main() {
	int T;

	freopen("out.txt", "w", stdout);
	pow2[0] = 1;
	for(int i = 1; i < N; i++) pow2[i] = pow2[i - 1] * 2;
	scanf("%d", &T);
	For(cas, T) {
		cin >> n >> m;
		printf("Case #%d: ", cas + 1);
		if(m > pow2[n - 2]) {
			puts("IMPOSSIBLE");
			continue;
		}
		puts("POSSIBLE");
		mst(vis, 0);
		m--;
		vis[1][n] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n - 1; j++)
				vis[i][j] = 1;

		for(int i = n - 1; i >= 2; i--) 
			if(m >= pow2[i - 2]) {
				m -= pow2[i - 2];
				vis[i][n] = 1;
			}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				printf("%d", vis[i][j]);
			puts("");
		}
	}
	return 0;
}
