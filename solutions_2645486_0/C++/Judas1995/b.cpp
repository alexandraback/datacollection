#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int v[555];
int f[555][555];
int t,e,r,n;
int ans;

int main(){

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	scanf("%d", &t);
	for (int z = 1; z <= t; z++){
		scanf("%d%d%d", &e, &r, &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
		}
		for (int i = 0; i <= 500; i++){
			for (int j = 0; j <= 500; j++){
				f[i][j] = -1000000;
			}
		}
		f[0][e] = 0;
		r = min(r, e);
		for (int i = 0; i < n; i++){
			for (int j = r; j <= e; j++){
				for (int k = 0; k <= j; k++){
					f[i + 1][min(j - k + r, e)] = max(f[i + 1][min(j - k + r, e)], f[i][j] + k * v[i + 1]);
				}
			}
		}
		ans = 0;
		for (int j = r; j <= e; j++){
			ans = max(ans, f[n][j]);
		}
		printf("Case #%d: %d\n", z, ans);
	}
	return 0;

}
