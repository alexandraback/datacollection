#include <stdio.h>
char D[1050];
int d[1050];
int sum[100050];
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, i, T, mx = 0;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		for(i = 0; i <= 1030; i++) D[i] = 0;
		scanf("%d", &N);
		scanf("%s", D);
		for(i = 0; i <= N; i++) d[i] = D[i]-'0';
		sum[0] = d[0];
		for(i = 1; i < N; i++) sum[i] = d[i]+sum[i-1];
		mx = 0;
		for(i = 1; i <= N; i++) {
			if(i-sum[i-1] > mx) mx = i-sum[i-1];
		}
		printf("Case #%d: %d\n", t, mx);
	}
	return 0;
}