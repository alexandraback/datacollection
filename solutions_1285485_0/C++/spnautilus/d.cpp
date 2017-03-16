#include <stdio.h>
#include <set>

using namespace std;

#define maxs (32)

typedef pair <int, int> PII;

int T;
char B[maxs][maxs];
int R, C;
int D;
int r0, c0;

int gcd(int a, int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

inline int abs1(int a)
{
	return (a >= 0) ? a : -a;
}

inline int sqr(int a)
{
	return a * a;
}

int main()
{
	int i, j;
	int tt;

	scanf("%d", &T);
	for(tt = 1; tt <= T; ++tt)
	{
		scanf("%d %d %d", &R, &C, &D);
		for(i = 0; i < R; ++i)
		{
			scanf("%s", B[i]);
			for(j = 0; j < C; ++j)
			{
				if(B[i][j] == 'X')
				{
					r0 = i;
					c0 = j;
				}
			}
		}

		set <PII> rec;

		for(i = -D; i <= D; ++i)
		{
			for(j = -D; j <= D; ++j)
			{
				if(i != 0 || j != 0)
				{
					int r1;
					int c1;

					if(abs1(i) & 1)
					{
						r1 = R - r0 - 1 + i * (R - 2);
					}
					else
					{
						r1 = r0 + i * (R - 2);
					}

					if(abs1(j) & 1)
					{
						c1 = C - c0 - 1 + j * (C - 2);
					}
					else
					{
						c1 = c0 + j * (C - 2);
					}

//					printf("i %d j %d : %d %d %d %d   %d\n", i, j, r0, c0, r1, c1, sqr(r1 - r0) + sqr(c1 - c0));

					if(sqr(r1 - r0) + sqr(c1 - c0) <= D*D)
					{
//						printf("i %d j %d : %d %d %d %d   %d\n", i, j, r0, c0, r1, c1, sqr(r1 - r0) + sqr(c1 - c0));
						int g = gcd(abs1(r1 - r0), abs1(c1 - c0));
						rec.insert(PII((r1 - r0) / g, (c1 - c0) / g));
					}
				}
			}
		}


		printf("Case #%d: %d\n", tt, rec.size());
	}

	return 0;
}
