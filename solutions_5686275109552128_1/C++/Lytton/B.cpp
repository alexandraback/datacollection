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
	ans = p[n];
	for (int i = 1;i <= p[n];++i){
		int now = 0;
		for (int j = 1;j <= n;++j)
			if (p[j] <= i) continue;
			else now += (p[j]-1)/i;
		ans = min(ans, now+i);
	}
	printf("Case #%d: %d\n", id, ans);
}

int main() {
	//printf("sdf");
	freopen("B-large.in", "r", stdin);
	//freopen("B.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &T);
	//printf("sdf");
	for (int i = 1;i <= T;++i){
		solve( i );
	}
	return 0;
}