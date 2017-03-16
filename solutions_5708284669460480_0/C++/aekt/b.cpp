#include <cstdio>
#include <cstring>

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int k, l, s;
		char K[101], L[101], S[101];
		scanf("%d%d%d", &k, &l, &s);
		scanf("%s", K);
		scanf("%s", L);
		int N = 1, M = 0;
		for (int i = 0; i < s; i++, N*=k);
		int bnn[N];
		for (int i = 0; i < N; i++) {
			for (int j = 0, m = i; j < s; j++) {
				S[j] = K[m % k];
				m /= k;
			}
			bnn[i] = 0;
			for (int j = 0; j <= s-l; j++) {
				if (strncmp(S+j,L,l) == 0) bnn[i]++;
			}
			if (bnn[i] > M) M = bnn[i];
		}
		double p = 0;
		for (int i = 0; i < N; i++) {
			p += bnn[i];
		}
		p /= N;
		printf("Case #%d: %.8f\n", t, M - p);
	}
	return 0;
}
