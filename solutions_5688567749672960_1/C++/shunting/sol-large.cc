#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <queue>

// TODO check all the type to avoid overflow

typedef long long ll;

using namespace std;

ll pow(int ndig) {
	ll res = 1;
	for (int i = 0; i < ndig; i++) {
		res *= 10;
	}
	return res;
}

ll reverse(ll v) {
	ll res = 0;
	while (v) {
		ll d = v % 10;
		res = res * 10LL + d;
		v /= 10;
	}
	return res;
}

int getndig(ll N) {
	int ndig = 0;
	while (N) {
		ndig++;
		N /= 10;
	}
	return ndig;
}

bool upperSmall(ll N, int ndig) {
	int half = ndig / 2;	
	int mov = half + (ndig % 2);
	N /= pow(mov);
	return N == pow(half - 1);
}

ll solve(ll N) {
	// printf("solve %lld\n", N); // TODO
	int ndig = getndig(N);
	if (ndig == 1) {
		return N;
	}

	ll res = 0;
	if (!upperSmall(N, ndig)) { // check if upper half is already small
		// printf("- no upper small %lld\n", N); // TODO
		ll lowerCap = pow(ndig / 2);
		ll lowerHalf = N % lowerCap;
		if (lowerHalf == 0) {
			res += lowerCap - 1;
			N -= (lowerCap - 1);
			// printf("--0 res %lld N %lld\n", res, N);
			if (upperSmall(N, ndig)) {
				goto out;
			}
		} else if (lowerHalf > 1) {
			res += lowerHalf - 1;	
			N -= (lowerHalf - 1);
		}
		res += 1;
		N = reverse(N);
	}
out:

	// Node: upperSmall is true
	// XXX: add res to the result
	ll lowerNdig = (ndig + 1) / 2;
	ll lowerCap = pow(lowerNdig);
	ll lowerHalf = N % lowerCap;
	// printf("-- second lower half %lld\n", lowerHalf);

	res += lowerHalf;
	N -= lowerHalf;

	// printf("-- res %lld N %lld\n", res, N);
	return res + 1 + solve(N - 1);
}

int 
main(void) {
	int T;
	scanf("%d", &T);

	ll N;
	for (int seqno = 1; seqno <= T; seqno++) {
		scanf("%lld", &N);
		// printf("Input %lld\n", N);
		printf("Case #%d: %lld\n", seqno, solve(N));
	}

	return 0;
}
