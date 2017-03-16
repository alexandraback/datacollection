#include <stdio.h>

void KCS(long long int K, long long int C, long long int S, long long int n);
void KC(long long int K, long long int C);

int main() {
	int t, i;
	long long int K, C, S, n;

	scanf("%d", &t);
	for(i = 1; i <= t; i++) {
		scanf("%Ld%Ld%Ld", &K, &C, &S);
		printf("Case #%d:", i);
		if(K == S) 
			KC(K, C);
		else {
			n = (K+C-1)/C; //ceil(K/C)
			if(n > S)
				printf(" IMPOSSIBLE\n");
			else
				KCS(K, C, S, n);
		}
	}
 	return 0;
}

void KCS(long long int K, long long int C, long long int S, long long int n) {
	long long int i, j, Kpower, p;

	for(i = 0; i < n; i++) {
		p = 0;
		Kpower = 1;
		for(j = C-1; j >= 0; j--) {
			if(i*C+j < K) {
				p += (i*C+j)*Kpower;
			}
			Kpower *= K;
		}
		printf(" %Ld", p + 1);
	}
	printf("\n");
}

void KC(long long int K, long long int C) { //K==S
	long long KC1 = 1;
	long long int i;
	for(i = 0; i < C - 1; i++) 
		KC1 *= K;
	for(i = 1; i <= K; i++) 
		printf(" %Ld", i*KC1);
	printf("\n");
}

