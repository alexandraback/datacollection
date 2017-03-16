#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bitlist[100];
bool
ispali(long long v) {
	int nbit = 0;
	while (v) {
		bitlist[nbit++] = (int) (v % 10);
		v /= 10;
	}
	for (int i = 0, j = nbit - 1; i < j; i++, j--) {
		if (bitlist[i] != bitlist[j])
			return false;
	}
	return true;
}

int palilist[20000]; // enough
int npali;

long long goodlist[20000];
int ngood;

void 
init(void) {
	for (int i = 1; i <= 10000000; i++) {
		if (ispali(i)) {
			palilist[npali++] = i;
		}	
	}

	long long v;
	for (int i = 0; i < npali; i++) {
		if (ispali(v = (long long) palilist[i] * palilist[i])) {
			goodlist[ngood++] = v;
		}
	}
}

int
getv(long long v) {
	int left = 0, right = ngood - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (goodlist[mid] > v) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return left;
}

int 
main(void) {
	int T, seq;
	long long A, B;
	init();
	// printf("%d\n", npali); exit(1); // TODO

	scanf("%d", &T);

	for (seq = 1; seq <= T; seq++) {
		scanf("%lld%lld", &A, &B);
		// printf("A is %lld B is %lld\n", A, B); // TODO

		int res = getv(B);
		if (A != 1) {
			res -= getv(A - 1);
		}

		printf("Case #%d: %d\n", seq, res);
	}
	return 0;
}
