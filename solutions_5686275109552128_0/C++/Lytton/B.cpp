#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (1000+10)
#define oo (100000)

int T, n, ans;
int p[MAXN];
int f[MAXN][MAXN];

void solve( int id ) {
	int k, num, tmp; 

	scanf("%d", &n);
	for (int i = 1;i <= n;++i){
		scanf("%d", &p[i]);
		//r = max(r, p[i]);
	}
	sort(p+1, p + n + 1);
	for (int i  = 1;i <= n;++i)
		for (int j = 0;j <= p[n];++j)
			f[i][j] = p[n];
	f[0][0] = 0;
	for (int i = 1;i <= n;++i)
		for (int j = 0;j < p[i];++j){
			f[i][j] = min(f[i][j], max(f[i-1][j], p[i]));
			k = 0; 
			num = k; 
			//num = (1 << k) - 1;
			while (num <= j){
				if (p[i] % (num+1) == 0) tmp = p[i] / (num+1);
				else tmp = p[i]/(num+1) + 1;
				f[i][j] = min(f[i][j], max(f[i-1][j-num], tmp));
				k++;
				num = k;
			//	num = (1 << k) - 1;
			}
		}
	int ans = p[n];
	for (int j = 0;j < p[n];++j)
		ans = min(ans, f[n][j] + j);
	printf("Case #%d: %d\n", id, ans);
}

int main() {
	//printf("sdf");
	freopen("B-small-attempt1.in", "r", stdin);
	//freopen(".in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	scanf("%d", &T);
	//printf("sdf");
	for (int i = 1;i <= T;++i){
		solve( i );
	}
	return 0;
}