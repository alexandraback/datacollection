#include <stdio.h>

int main(void)
{
	int t, T, n, N, s, S, p, P, tot, cnt;
	FILE *in, *out;
	
	in = fopen("input.txt", "rt");
	out = fopen("output.txt", "wt");
	
	fscanf(in, "%d", &T);
	for (t = 1; t <= T; t++)
	{
		fscanf(in, "%d %d %d", &N, &S, &P);
		
		s = 0;
		cnt = 0;
		for (n = 0; n < N; n++)
		{
			fscanf(in, "%d", &tot);
			
			p = tot / 3;
			switch (tot % 3)
			{
				case 0:
					if (p >= P) cnt++;
					else if (tot && p + 1 >= P) s++;
					break;
				case 1:
					if (p + 1 >= P) cnt++;
					break;
				case 2:
					if (p + 1 >= P) cnt++;
					else if (p + 2 >= P) s++;
					break;
			}
		}
		
		cnt += (s <= S) ? s : S;
		fprintf(out, "Case #%d: %d\n", t, cnt);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}