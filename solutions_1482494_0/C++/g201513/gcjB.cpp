#include<stdio.h>
#include<string.h>

const int maxn = 2005;

int ntest;
int used[maxn];
int N, A[maxn], B[maxn], now, ans;

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d", &N);
		for(int i=1; i<=N; i++) {
			scanf("%d%d", &A[i], &B[i]);
		}

		now = 0;
		ans = 0;
		memset(used, 0, sizeof(used));

		for(; now < N*2; ) {
			bool ok = false;
			for(int i=1; i<=N; i++) if(used[i]!=2 && B[i] <= now) {
				now += (2-used[i]);
				used[i] = 2;
				ok = true;
				ans++;
				break;
			}
			if(ok) continue;

			int opt = -1, choose = -1;
			for(int i=1; i<=N; i++) if(used[i]==0 && A[i] <= now) {
				if(opt < B[i]) {
					opt = B[i];
					choose = i;
				}
			}

			if(choose == -1) {
				break;
			}

			used[choose] = 1;
			now++; ans++;
		}

		if(now != N*2) printf("Case #%d: Too Bad\n", test);
		else printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}