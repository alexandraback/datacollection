#include <stdio.h>
int bff[1005], vis[1005], ind[1005], tail[1005];
int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C_large.out", "w", stdout);
	int t, tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++){
		int n, i, j, mx=0, cnt=0, bf, tm=0;
		scanf("%d", &n);
		for (j = 1; j <= n; j++) tail[j] = 0;
		for (i = 1; i <= n; i++) scanf("%d", &bff[i]);
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++) vis[j] = 0, ind[j] = 0;
			bf = i;
			vis[bf] = 1;
			cnt = 1;
			ind[bf] = cnt;
			while (true){
				bf = bff[bf];
				if (vis[bf] == 0){
					vis[bf] = 1;
					cnt++;
					ind[bf] = cnt;
				}
				else{
					if (mx < cnt - ind[bf] + 1) mx = cnt - ind[bf] + 1;
					if (cnt - ind[bf] + 1 == 2){
						if (tail[bf] < cnt - 2) tail[bf] = cnt - 2;
					}
					break;
				}
			}
		}
		for (i = 1; i <= n; i++){
			if (i==bff[bff[i]]){
				tm += tail[i] + tail[bff[i]] + 2;
			}
		}
		if (mx < tm / 2) mx = tm/2;
		printf("Case #%d: %d\n", t,mx);

	}

	return 0;
}