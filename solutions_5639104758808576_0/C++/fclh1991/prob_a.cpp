#include <stdio.h>
#include <string>
#define N 1100
char S[N];
int t, maxs;
int main()
{
	FILE *fpi = fopen("./A-small-attempt1.in", "r");
	FILE *fpo = fopen("./A_sml.out", "w");
	fscanf(fpi, "%d", &t);
	int ans, tot;
	for(int c = 1; c <= t; ++c)
	{
		tot = ans = 0;
		fscanf(fpi, "%d", &maxs);
		fscanf(fpi, "%s", S);
		for(int i = 0; i <= maxs; ++i)
		{
			if(tot < i)
			{
				ans += i - tot;
				tot = i;
			}
			tot += S[i] - '0';
		}
		fprintf(fpo, "Case #%d: %d\n", c, ans);
	}
	return 0;
}

