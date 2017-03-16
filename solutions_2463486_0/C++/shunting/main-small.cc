#include <stdio.h>

bool palilist[1001];
bool palisqlist[1001];

int bitlist[100];
bool
ispali(int v) {
	int nbit = 0;
	while (v) {
		bitlist[nbit++] = v % 10;
		v /= 10;
	}
	for (int i = 0, j = nbit - 1; i < j; i++, j--) {
		if (bitlist[i] != bitlist[j])
			return false;
	}
	return true;
}

int 
main(void) {
	int T, seq;
	int A, B;
	scanf("%d", &T);

	for (int i = 1; i <= 1000; i++) {
		palilist[i] = ispali(i);
		if (palilist[i] && i * i <= 1000) {
			palisqlist[i * i] = true;
		}
	}
	for (seq = 1; seq <= T; seq++) {
		scanf("%d%d", &A, &B);
		
		int sum = 0;
		for (int i = A; i <= B; i++) {
			sum += palilist[i] && palisqlist[i];
		}
		printf("Case #%d: %d\n", seq, sum);
	}
	return 0;
}
