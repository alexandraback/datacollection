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
long long ans;
void work(int a, int b, long long sum) {
	if (a >= N || b >= M) {
		if(sum > ans) ans = sum;
          return;
	}
	if (s1[a].type == s2[b].type) {
		long long k;
		if (s1[a].has < s2[b].has) {
			k = s1[a].has;
			s2[b].has -= k;
			work(a+1, b, sum+k);
			s2[b].has += k;
		}
		else if (s1[a].has > s2[b].has) {
			k = s2[b].has;
			s1[a].has -= k;
			work(a, b+1, sum+k);
			s1[a].has += k;
		}
		else {
			k = s1[a].has;
			work(a+1, b+1, sum+k);
		}
	}
	else {
	work(a+1, b, sum);
	work(a, b+1, sum);
}
}

void run() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) 
		scanf("%lld%d", &s1[i].has, &s1[i].type);
	for (int i = 0; i < M; i++) 
		scanf("%lld%d", &s2[i].has, &s2[i].type);

	ans = 0;
	work(0, 0, 0);
	printf(" %lld\n", ans);
}

int main() {

	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);

	int cases;
	scanf("%d", &cases);

	for (int cas = 1; cas <= cases; cas++) {
		printf("Case #%d:", cas); 
		run();
	}
	return 0;
}
