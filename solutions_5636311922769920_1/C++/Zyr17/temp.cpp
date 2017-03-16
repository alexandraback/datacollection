#include <bits/stdc++.h>
#define Init freopen("t.in","r",stdin);freopen("t.out","w",stdout);
int n,m,s,T;
int main(){
	Init;
	scanf("%d", &T);
	for (int i = 1; i <= T; i ++ ){
		printf("Case #%d:", i);
		scanf("%d%d%d", &n, &m, &s);
		if (m * s < n){
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for (int i = 1; i <= n; i += m){
			long long ans = 1;
			for (int j = i; j < i + m; j ++ )
				ans = (ans - 1) * n + (j > n ? n : j);
			printf(" %lld", ans);
		}
		printf("\n");
	}
}
