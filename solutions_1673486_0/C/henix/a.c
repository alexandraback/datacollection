#include <stdio.h>
#include <math.h>
#include <gmp.h>

#define N 100000

mpf_t probs[N];

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	int c;
	// init all mpf
	int i;
	for (i = 0; i < N; ++i) {
		mpf_init(probs[i]);
	}
	mpf_t minkey;
	mpf_t curexp;
	mpf_init(minkey);
	mpf_init(curexp);

	mpf_t tmp;
	mpf_init(tmp);

	for (c = 0; c < t; ++c) {
		int ntyped, ntotal;
		scanf("%d%d", &ntyped, &ntotal);
		for (i = 0; i < ntyped; ++i) {
			double d;
			scanf("%lf", &d);
			mpf_set_d(probs[i], d);
		}

		int sum = ntotal + 1;
		mpf_set_ui(minkey, sum + 1);
		// i - the corrent number from front
		for (i = 1; i <= ntyped; ++i) {
			int j;
			mpf_set_ui(curexp, 1);
			for (j = 0; j < i; ++j) {
				mpf_mul(curexp, curexp, probs[j]);
			}
			mpf_set_si(tmp, -sum);
			mpf_mul(curexp, curexp, tmp);
			mpf_set_si(tmp, 2 * sum + ntyped - 2 * i);
			mpf_add(curexp, curexp, tmp);
			if (mpf_cmp(curexp, minkey) < 0) {
				mpf_set(minkey, curexp);
			}
		}
		printf("Case #%d: %.6f\n", c + 1, mpf_get_d(minkey));
	}

	// clear all mpf
	mpf_clear(tmp);
	mpf_clear(minkey);
	mpf_clear(curexp);
	for (i = 0; i < N; ++i) {
		mpf_clear(probs[i]);
	}
	return 0;
}
