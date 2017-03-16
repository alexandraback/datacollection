#include <cstdio>
int main (){
	freopen ("B-large.in", "r", stdin);
	freopen ("B-large.out", "w", stdout);
	int T, N, h;
	int cnt[2501];
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d", &N);
		for (int j = 1; j <= 2500; j++)
			cnt[j] = 0;
		for (int j = 0; j < N * (2 * N - 1); j++){
			scanf("%d", &h);
			cnt[h]++;
		}
		printf("Case #%d:", i);
		for (int j = 1; j <= 2500; j++){
			if (cnt[j] % 2){
				printf(" %d", j);
				cnt[j]--;
			}
		}
		printf("\n");
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
