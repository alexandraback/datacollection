#include<bits/stdc++.h>
using namespace std;

int T, n, m;
const int MAXN = 201;
int f[MAXN][MAXN];
int a[MAXN][MAXN];
int row[MAXN], col[MAXN];
int cnt[10000];
/*
int dfs(int u, int tot){
	if (tot >= 2 * n - 1){
		return 1;
	}
	for(int i = 1; i <= 2 * n - 1; i++){
		if (f[i][u] == )
	}
}*/

int main(){
	freopen("Bl.in", "r", stdin);
	freopen("Bl.out", "w", stdout);
	cin>>T;
	for(int o = 1; o <= T; o++){
		printf("Case #%d: ", o);
		scanf("%d", &n);
		int p = 100000, q = 0;
		for(int i = 1; i <= 2500; i++)
			cnt[i] = 0;
		for(int i = 1; i <= 2 * n - 1; i++){
			for(int j = 1; j <= n; j++){
				int x;
				scanf("%d", &x);
				cnt[x] = ~cnt[x];
			}
		}
		m = 0;
		for(int i = 1; i <= 2500; i++){
			if (cnt[i]){
				m++;
				printf("%d%c", i, " \n"[m == n]);
			}
		}
		/*
		for(int i = 1; i <= n; i++)
			row[i] = 0, col[i] = 0;
		int cntp = 0, cntq = 0;
		for(int i = 1; i <= 2 * n + 1; i++){
			cntp += (f[i][1] == p);
			cntq += (f[i][n] == q);
		}
		if (cntp == 2){
			row[1] = 1, col[1] = 1;
			int flag = 0;
			for(int i = 1; i <= 2 *n + 1; i++)
				if (f[i][1] == p){
					if (!flag){
						flag = 1;
						for(int j = 1; j <= n; j++)					
							a[1][j] = f[i][j];
					}
					else{
						for(int j = 1; j <= n; j++)
							a[j][1] = f[i][j];
						break;
					}
				}
			dfs(1, 2);
		}
		else{
			row[n] = 1, col[n] = 1;
			int flag = 0;
			for(int i = 1; i <= 2 *n + 1; i++)
				if (f[i][n] == q){
					if (!flag){
						flag = 1;
						for(int j = 1; j <= n; j++)					
							a[n][j] = f[i][j];
					}
					else{
						for(int j = 1; j <= n; j++)
							a[j][n] = f[i][j];
						break;
					}
				}
			dfs(n, 2);
		}
		int flag = 0;
		for(int i = 1; i <= n; i++)
			if (!flag)
			if (!row[i]){
				for(int j = 1; j <= n; j++)
					printf("%d%c", a[i][j], " \n"[j == n]);
				flag  =1;
			}
		for(int i = 1; i <= n; i++)
			if (!flag)
			if (!col[i]){
				for(int j = 1; j <= n; j++)
					printf("%d%c", a[j][i], " \n"[j == n]);
				flag  =1;
			}*/
	}
	return 0;
} 

