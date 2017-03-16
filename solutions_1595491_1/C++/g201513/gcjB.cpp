#include<stdio.h>

int N, S, p;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%d%d", &N, &S, &p);

		int v = (p==0 ? 0 : p * 3 - 2);
		int v2 = (p<=1 ? p : p * 3 - 4);
		int ans = 0;

		for(int i=0, u; i<N; i++) {
			scanf("%d", &u);
			if(u >= v) ans++;
			else if(u >= v2 && S > 0) {
				ans++; S--;
			}
		}

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}