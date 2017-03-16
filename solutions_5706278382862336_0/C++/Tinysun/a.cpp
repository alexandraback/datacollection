#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "tool.h"

uint64_t Gcd(uint64_t a, uint64_t b)
{
	if (a == b || a == 0)
		return b;
	if (a > b)
		return Gcd(b, a);
	// a < b
	return Gcd(b % a, a);
} 

int main(int argc, char **argv)
{
	char buf[256];
	fgets(buf, 100, stdin);
    int T = atoi(buf);
    for(int tcase=1; tcase<=T; tcase++)
    {
		uint64_t A, B;
		scanf("%llu/%llu", &A, &B);

		uint64_t g = Gcd(A, B);
		A = A/g;
		B = B/g;

		uint64_t chk = B;
		int cnt = 0;
		int gene = 0;
		while (chk != 0)
		{
			if (chk & 1)
				cnt++;
			chk = chk >> 1;
			gene++;
		}
		gene--;
		bool impos = false;
		if (cnt > 1)
			impos = true;

		int cnt2 = 0;
		while (A != 1)
		{
			A = A >> 1;
			cnt2++;
		}
		
		int  ans = gene - cnt2;

		if (impos)
			printf("Case #%d: impossible", tcase);
		else
			printf("Case #%d: %d", tcase, ans);
		printf("\n");
    }

    return 0;
}
