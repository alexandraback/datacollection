#include <stdio.h>
#define MAX_N 1010

int N, S[MAX_N], P[MAX_N];

void init(int begin, int end);
int solve();

int main()
{
	int T, t, i, ans;
	FILE* fp = fopen("A-large.out", "w");

	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d", &N);
		for(i = 0; i <= N; i++) {
			scanf("%1d", &S[i]);
		}
		P[0] = 0;
		init(1, N);
		ans = solve();
		fprintf(fp, "Case #%d: %d\n", t, ans);
	}
	fclose(fp);
	return 0;
}

void init(int begin, int end) {
	int i;

	for(i = begin; i <= end; i++) {
		P[i] = P[i - 1] + S[i - 1];
	}
}

int solve() {
	int ret = 0, i;

	for(i = 0; i <= N; i++) {
		if(!S[i])	continue;
		if(i > P[i]) {
			ret += i - P[i];
			P[i] = i;
			init(i + 1, N);
		}
	}
	return ret;
}
