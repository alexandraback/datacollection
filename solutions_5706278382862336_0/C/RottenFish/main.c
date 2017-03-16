#include <stdio.h>
#include <math.h>

void short_it(long long *P, long long *Q)
{
	while (*P % 2 == 0)
	{
		*P /= 2;
		*Q /= 2;
	}
	long long q = *Q;
	while (q % 2 == 0) q /= 2;
	if (q == 1) return;
	if (*P % q == 0)
	{
		*P /= q;
		*Q /= q;
	}
}

// true if number is a 2^n
int is_2_in_degree(long long X)
{
	if (X == 1) return 1;
	else if (X % 2) return 0;
	else return is_2_in_degree(X/2);
}

// use after short_it
int test_on_input_errors(long long P, long long Q)
{
	if (Q <= 0) return 1;
	if (P > Q) return 1;
	if (P < 0) return 1;
	if (!is_2_in_degree(Q)) return 1;
	return 0;
}

// P/Q
// if returned -1 then infinity
long long shortest(long long P, long long Q)
{
	if (P == 0) return -1;
	if (P >= Q) return 0;
	else return 1+shortest(P, Q/2);
}

int main(void)
{
	int T;
	long long P, Q;
	scanf("%d", &T);
	for (int test=1; test <= T; test++)
	{
		scanf("%lld/%lld", &P, &Q);
		short_it(&P, &Q);
		if (test_on_input_errors(P, Q)) printf("Case #%d: impossible\n", test);
		else printf("Case #%d: %lld\n", test, shortest(P, Q));
	}
	return 0;
}
