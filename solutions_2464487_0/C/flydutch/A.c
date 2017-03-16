#include <stdio.h>
#include <gmp.h>

#ifdef DEBUG
#define ddd(s, ...) printf(s, __VA_ARGS__)
#else
#define ddd(s, ...)
#endif

int main(void) {
	int t = 0, T;

	scanf("%d", &T);
	while (t<T) {
		mpz_t _r, _t, _y;
		char sr[100], st[100];
		unsigned long long y;

		scanf("%s %s", sr, st);
		mpz_init_set_str(_r, sr, 10);
		mpz_init_set_str(_t, st, 10);
		mpz_init(_y);

		mpz_set(_y, _r);
		mpz_mul(_y, _y, _y);
		mpz_sub(_y, _y, _r);
		mpz_add(_y, _y, _t);
		mpz_add(_y, _y, _t);
		mpz_mul_ui(_y, _y, 4);
		mpz_add_ui(_y, _y, 1);
		mpz_root(_y, _y, 2);
		mpz_sub_ui(_y, _y, 1);
		mpz_tdiv_q_ui(_y, _y, 2);
		mpz_sub(_y, _y, _r);
		y = (mpz_get_ui(_y)+1)/2;

		t++;
		printf("Case #%d: %Lu\n", t, y);
	}
	return (0);
}
