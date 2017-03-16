#include <stdio.h>

void KC(long long int K, long long int C);

int main() {
	int t, i;
	long long int K, C, S;

	scanf("%d", &t);
	for(i = 1; i <= t; i++) {
		scanf("%Ld%Ld%Ld", &K, &C, &S);
		printf("Case #%d:", i);
		KC(K, C);
	}
 	return 0;
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

