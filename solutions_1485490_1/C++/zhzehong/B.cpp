#include <stdio.h>
#include <memory.h>

struct node {
	long long has;
	int type;
};

long long max(long long A, long long B) {
     if (A > B) return A;
     else return B;
}

node s1[120], s2[120];
int N, M;
long long dp[120][120];

long long work(int a, int b, bool ok1, bool ok2) {
	if (a >= N || b >= M) return (dp[a][b] = 0);
	if (ok1 && ok2 && dp[a][b] != -1) return dp[a][b];
	long long ans = -1;
	if (s1[a].type == s2[b].type) {
		long long k;
		if (s1[a].has < s2[b].has) {
			k = s1[a].has;
			s2[b].has -= k;
			ans = work(a+1, b, 1, 0) + k;
			s2[b].has += k;
		}
		else if (s1[a].has > s2[b].has) {
			k = s2[b].has;
			s1[a].has -= k;
			ans = work(a, b+1, 0, 1) + k;
			s1[a].has += k;
		}
		else {
			k = s1[a].has;
			ans = work(a+1, b+1, 1, 1) + k;
		}
	}
	else {
	     ans = max(ans, work(a+1, b, 1, ok2));
	     ans = max(ans, work(a, b+1, ok1, 1));
      }
	if (ok1 && ok2) dp[a][b] = ans;
	return ans;
}

void run() {
	memset(dp, -1, sizeof(dp));

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) 
		scanf("%lld%d", &s1[i].has, &s1[i].type);
	for (int i = 0; i < M; i++) 
		scanf("%lld%d", &s2[i].has, &s2[i].type);

	work(0, 0, 1, 1);
	printf(" %lld\n", dp[0][0]);
}

int main() {

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int cases;
	scanf("%d", &cases);

	for (int cas = 1; cas <= cases; cas++) {
		printf("Case #%d:", cas); 
		run();
	}
	return 0;
}
