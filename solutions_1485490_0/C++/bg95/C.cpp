#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

const int N = 201;

struct Block
{
	long long l;
	int c;
};
Block a[N], b[N]; //start from 1
int an, bn;
long long f[N][N];
long long dp()
{
	int i, j, ti, tj;
	long long tsl, tla, tlb, tc;
	memset(f, 0, sizeof(f));
	for (i = 1; i <= an; i++)
		for (j = 1; j <= bn; j++)
		{
			f[i][j] = std::max(f[i][j - 1], f[i - 1][j]);
			if (a[i].c == b[j].c)
			{
				//printf("samecolor\n");
				//f[i][j] = f[i - 1][j - 1] + std::min(a[i].l, b[j].l);
				tc = a[i].c;
				ti = i;
				tj = j;
				tsl = 0;
				tla = a[i].l;
				tlb = b[j].l;
				while (ti > 0 && tj > 0)
				{
					tsl += std::min(tla, tlb);
					f[i][j] = std::max(f[i][j], f[ti - 1][tj - 1] + tsl);
					//printf("ti = %d(%I64d), tj = %d(%I64d)\n", ti, tla, tj, tlb);
					//printf("renew f[%d][%d] = %I64d + %I64d\n", ti - 1, tj - 1, f[ti - 1][tj - 1], tsl);
					if (tla > tlb)
					{
						tla = tla - tlb;
						for (tj--; tj > 0 && b[tj].c != tc; tj--);
						if (tj <= 0)
							break;
						tlb = b[tj].l;
					}
					else if (tla < tlb)
					{
						tlb = tlb - tla;
						for (ti--; ti > 0 && a[ti].c != tc; ti--);
						if (ti <= 0)
							break;
						tla = a[ti].l;
					}
					else
						break;
				}//while
			}//else
			//printf("f[%d][%d] = %I64d\n", i, j, f[i][j]);
		}//for
	return f[an][bn];
}
int main(void)
{
	int T, c;
	int i;
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (c = 1; c <= T; c++)
	{
		scanf("%d%d", &an, &bn);
		for (i = 1; i <= an; i++)
			scanf("%d%d", &a[i].l, &a[i].c);
		for (i = 1; i <= bn; i++)
			scanf("%d%d", &b[i].l, &b[i].c);
		printf("Case #%d: %I64d\n", c, dp());
	}
	return 0;
}
