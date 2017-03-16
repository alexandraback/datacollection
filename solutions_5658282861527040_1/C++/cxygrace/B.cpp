#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxd = 40;

int getbit(int x, int p)
{
	return (x & (1 << p)) >> p;
}

long long getnum(int A, int B, int K)
{
	static long long f[maxd][2][2][2];
	memset(f, 0, sizeof(f));
	f[31][1][1][1] = 1;
	
	for (int i = 30; i >= 0; i--)
	{
		for (int a = 0; a <= 1; a++)
			for (int b = 0; b <= 1; b++)
			{
				for (int p1 = 0; p1 <= 1; p1++)
				{
					if (p1 == 1 && a != getbit(A, i)) continue;
					for (int p2 = 0; p2 <= 1; p2++)
					{
						if (p2 == 1 && b != getbit(B, i)) continue;
						for (int p3 = 0; p3 <= 1; p3++)
						{
							if (p3 == 1 && (a & b) != getbit(K, i)) continue;
							for (int q1 = 0; q1 <= 1; q1++)
							{
								if (q1 == 1 && (p1 != 0 || a >= getbit(A, i))) continue;
								for (int q2 = 0; q2 <= 1; q2++)
								{
									if (q2 == 1 && (p2 != 0 || b >= getbit(B, i))) continue;
									for (int q3 = 0; q3 <= 1; q3++)
									{
										if (q3 == 1 && (p3 != 0 || (a & b) >= getbit(K, i))) continue;
										f[i][p1][p2][p3] += f[i+1][p1+q1][p2+q2][p3+q3];
									}
								}
							}
						}
					}
				}
			}
	}
	
	return f[0][0][0][0];
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		int A, B, K;
		scanf("%d%d%d", &A, &B, &K);
		printf("Case #%d: %lld\n", i, getnum(A, B, K));
	}
	return 0;
}
