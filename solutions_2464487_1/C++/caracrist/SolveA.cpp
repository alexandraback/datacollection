#include "common.h"

Int fromK(Int r, Int k)
{
	return k * (2 * (r + 1) - 1) + k * (k -1) * 2;
}
Int FromRange(Int t, Int r, Int k_low, Int k_top)
{
	if (k_top == k_low)
		return k_top;
	Int k_next = (k_top + k_low) / 2;
	Int res = fromK(r, k_next);
	Int res_high = fromK(r, k_next + 1);
	if (res_high <= t)
		return FromRange(t, r, k_next, k_top);
	if (res > t)
		return FromRange(t, r, k_low, k_next);
	return k_next;
}
void SovleA(char * input)
{
	fprintf(stderr, __FUNCTION__ " started...\n");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		Int r,t;
		READ(r), READ(t), NL;
		Int l = 2 * r + 1;
		Int k = t / l;
		Int res = FromRange(t, r , 1 , min(k + 1, 0x7FFFFFFF));
		fprintf(stdout, "Case #%I64d: %I64d\n", i + 1, res);
	}
	fprintf(stderr, "\n" __FUNCTION__ " ended.\n");
}