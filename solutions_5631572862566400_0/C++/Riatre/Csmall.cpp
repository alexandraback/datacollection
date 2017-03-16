#include <bits/stdc++.h>

using namespace std;

int F[1111];

int x[1111];

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while (T--) {
		printf("Case #%d: ", ++TK);

		int N = 0;
		scanf("%d",&N);

		for(int i = 1;i <= N;i++) scanf("%d", &F[i]);

		for(int i = 0;i < N;i++) x[i] = i+1;
		int ans = 1;
		do {
			for(int len = ans + 1;len <= N;len++) {
				bool okay = true;
				for(int i = 0;i < len;i++) {
					int nxt = x[(i + 1) % len];
					int prv = x[(i + len - 1) % len];
					if (nxt != F[x[i]] && prv != F[x[i]]) {
						okay = false;
						break;
					}
				}
				if (okay) {
					ans = max(ans, len);
				}
			}
		} while (next_permutation(x, x+N));
		printf("%d\n",ans);
	}
	return 0;
}
