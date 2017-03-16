#include <cstdio>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int main(void)
{
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int q = 1; q <= t; q++)
	{
		int n,m,k;
		scanf("%d%d%d", &n, &m, &k);
		printf("Case #%d:\n",q);
		if (n == 1)
		{
			if (n * m - k >= 1)
			{
				printf("c");
				for (int i = 0; i < n * m - k - 1; i++)
					printf(".");
				for (int i = 0; i < k; i++)
					printf("*");
				printf("\n");
			}
			else
				printf("Impossible\n");
		}
		else
			if (m == 1)
			{
				if (n * m - k >= 1)
				{
					printf("c\n");
					for (int i = 0; i < n * m - k - 1; i++)
						printf(".\n");
					for (int i = 0; i < k; i++)
						printf("*\n");
				}
				else
					printf("Impossible\n");
			} else
			{
				if (n * m - k == 1)
				{
					printf("c");
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
							if (i || j)
							{
								printf("*");
							}
							printf("\n");
					}
				}
				else
				if (n * m - k >= 4)
				{
					bool a[55][55];
					memset(a,0,sizeof(a));
					int rest = n * m - k;
					int q = min(rest / 2, m);
					int lx, rx;
					lx = q - 2;
					for (int i = 0; i < q; i++)
					{
						a[0][i] = 1;
						a[1][i] = 1;
					}
					rest -= 2 * q;
					if (n == 2)
					{
						if (rest % 2 == 1)
						{
							printf("Impossible\n");
						}
						else
						{
							printf("c");
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < m; j++)
									if (i || j)
									{
										if (a[i][j])
											printf(".");
										else
											printf("*");
									}
									printf("\n");
							}
						}
					} else
					{
						if ((rest < 2) && rest)
						{
							a[0][q-1] = 0;
							a[1][q-1] = 0;
							lx --;
							rest += 2;
						}
						q = min(rest / 2, n - 2);
						for (int i = 0; i < q; i++)
						{
							a[2 + i][0] = 1;
							a[2 + i][1] = 1;
						}
						rest -= 2 * q;
						if (m == 2)
						{
							if (rest % 2 == 1)
							{
								printf("Impossible\n");
							}
							else
							{
								printf("c");
								for (int i = 0; i < n; i++)
								{
									for (int j = 0; j < m; j++)
										if (i || j)
										{
											if (a[i][j])
												printf(".");
											else
												printf("*");
										}
										printf("\n");
								}
							}
						}
						else
						{
							for (int i = 2; i < n; i++)
							{
								for (int j = 0; j < min(rest, lx); j++)
									a[i][2 + j] = 1;
								rest -= min(rest, lx);
								if (rest == 0)
									break;
							}
							if (rest != 0)
							{
								printf("Impossible\n");
							}
							else
							{
								printf("c");
								for (int i = 0; i < n; i++)
								{
									for (int j = 0; j < m; j++)
										if (i || j)
										{
											if (a[i][j])
												printf(".");
											else
												printf("*");
										}
									printf("\n");
								}
							}
						}
					}
				}
				else
					printf("Impossible\n");
			}
	}
	return 0;
}