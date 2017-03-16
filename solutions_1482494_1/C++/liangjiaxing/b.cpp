#include<stdio.h>
#include<string.h>

const int INF = 9999;

int a[1010], b[1010];

int main(){
	int i, j, k, m, n;
	int N;
	int T, re;
	freopen("x.txt", "r", stdin);
	freopen("w.txt", "w", stdout);
	scanf("%d", &T);
	for(re = 1; re <= T; re++){
		scanf("%d", &N);
		for(i = 0; i < N; i++)
			scanf("%d%d", a + i, b + i);
		int t = 0;
		int ans = 0;
		while(t < 2 * N){
			bool flag = false;
			for(i = 0; i < N; i++){
				if(b[i] <= t){
					t += a[i] < INF ? 2 : 1;
					a[i] = b[i] = INF;
					ans++;
					flag = true;
				}
			}
			if(flag) continue;
			int u = -1;
			for(i = 0; i < N; i++){
				if(a[i] <= t && (u == -1 || b[i] > b[u])){
					u = i;
				}
			}
			//printf("u = %d\n", u);
			if(u == -1) break;
			a[u] = INF;
			t++;
			ans++;
		}
		printf("Case #%d: ", re);
		if(t < 2 * N){
			puts("Too Bad");
		}else
			printf("%d\n", ans);
	}
}
