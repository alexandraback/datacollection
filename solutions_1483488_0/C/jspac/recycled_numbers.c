#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#define LEN 7
#define MAX 2000000

int main(void)
{
	int t, T, A, B, c, k, m, n, r, w, mul[LEN], *len, *chk;
	uint64_t cnt;
	FILE *in, *out;
	
	mul[0] = 1;
	for (m = 0, n = 1; n < LEN; m++, n++) mul[n] = 10 * mul[m];
	
	len = (int *)malloc((MAX + 1) * sizeof(int));
	chk = (int *)malloc((MAX + 1) * sizeof(int));
	
	A = 0; B = 1;
	for (k = 0; k <= LEN; k++)
	{
		for (n = A; n < B; n++) len[n] = k;
		A = B; B *= 10;
		if (B > MAX) B = MAX;
	}
	
	in = fopen("input.txt", "rt");
	out = fopen("output.txt", "wt");
	
	fscanf(in, "%d", &T);
	for (t = 1; t <= T; t++)
	{
		fscanf(in, "%d %d", &A, &B);
		
		if (A <= 11) A = 12;
		if (B < A) { fprintf(out, "Case #%d: 0\n", t); continue; }
		
		cnt = 0;
		memset((void *)(chk + A), 0, (B - A + 1) * sizeof(int));
		for (n = A; n <= B; n++)
		{
			if (chk[n]) continue;
			
			c = 0;
			chk[m = n] = 1;
			w = mul[len[n] - 1];
			for (k = 1; k < len[n]; k++)
			{
				r = m % 10;
				m = m / 10 + r * w;
				if (r && m >= A && m <= B && !chk[m]) { chk[m] = 1; c++; }
			}
			
			if (c) cnt += c * (c + 1) / 2;
		}
		
		fprintf(out, "Case #%d: %" PRIu64 "\n", t, cnt);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}