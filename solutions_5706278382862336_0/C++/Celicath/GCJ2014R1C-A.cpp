/* 2014.5.11 Celicath */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <stdint.h>

int64_t gcd(int64_t a, int64_t b)
{
	if (a > b) return gcd(a, b);
	else if (a == 0) return b;
	else return gcd(b % a, a);
}

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int64_t P, Q;

		fscanf(fin, "%lld/%lld", &P, &Q);
		int64_t g = gcd(P, Q);
		P /= g;
		Q /= g;

		int result = 40;
		for (int i = 0; i <= 40; i++)
		{
			if (Q == 1)
			{
				if (P >= Q && result > i)
					result = i;
				break;
			}
			else if (Q & 1) goto hell;
			else
			{
				if (P >= Q && result > i)
					result = i;
				Q >>= 1;
			}
		}

		fprintf(fout, "Case #%d: %d\n", c_n, result);
		printf("Case #%d: %d\n", c_n, result);
		continue;
	hell:
		fprintf(fout, "Case #%d: impossible\n", c_n);
		printf("Case #%d: impossible\n", c_n);
	}
	return -0;
}
