#include <stdio.h>
#define MN 1000005
int n, L, c[MN], r[MN];
long long d[MN];
char S[MN];
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int K = 1; K <= T; K++) {
		scanf("%s",S+1);
		scanf("%d",&n);
		for (int i = 1; S[i]; i++) {
			L = i;
			if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') c[i] = 0;
			else c[i] = 1;
			if (c[i]) r[i] = r[i-1]+1;
		}
		for (int i = 1; i <= L; i++) {
			if (c[i]) {
				if (r[i] >= n)
					d[i] = (i-n+1);
				else
					d[i] = d[i-1];

			} else{
				if (r[i-1] >= n)
					d[i] = d[i-1];
				else
					d[i] = d[i-1];
			}
		}
		long long sol = 0;
		for (int i = 1; i <= L; i++) {
			sol += d[i];
			d[i] = r[i] = 0;
		}
		printf("Case #%d: %lld\n",K,sol);
	}
	fcloseall();
	return 0;
}