#include <stdio.h>
#include <memory.h>
#define N 1001
int t, d, P[N], dp[N];
int main()
{
	FILE *fpi = fopen("./B-large.in", "r");
	FILE *fpo = fopen("./B-large.out", "w");
	fscanf(fpi, "%d", &t);
	int lsv, ans = 0;
	for(int c = 1; c <= t; ++c)
	{
		ans = 0;
		memset(P, 0, sizeof(P));
		fscanf(fpi, "%d", &d);
		for(int i = 0; i < d; ++i)
		{
			fscanf(fpi, "%d", &lsv);
			++P[lsv];
			ans = ans > lsv ? ans : lsv;
		}
		int st = ans, ad;
		for(int i = st - 1; i > 0; --i)
		{
			lsv = i;
			for(int j = st; j > i; --j)
			{
				if(!P[j]) continue;
				ad = j / i;
				if(ad * i == j) --ad;
				lsv += ad * P[j];
			}
			ans = ans < lsv ? ans : lsv;
		}
		fprintf(fpo, "Case #%d: %d\n", c, ans);
	}
	return 0;
}
