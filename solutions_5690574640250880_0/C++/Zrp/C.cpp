#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define N 120001
#define oo 1000000000
#define eps 1e-7
using namespace std;
int a[1001][1001] = {0}, n, m;
int print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			if (a[i][j] == 0)
				printf(".");
			else if (a[i][j] == 1)
				printf("*");
			else
				printf("c");
		printf("\n");
	}
	return 0;
}
int imp()
{
	printf("Impossible\n");
}
int main()
{
	int tot;
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &tot);
	for (int tt = 1; tt <= tot; tt++)
	{
		memset(a,0, sizeof(a));
		int num, fl = 0;
		printf("Case #%d:\n", tt);
		
		scanf("%d%d%d", &n, &m, &num);

		if (n == 1)
		{
			for (int i = 1; i <= m; i++)
				if (i <= num)
					printf("*");
				else if (i < m)
					printf(".");
				else
					printf("c");
			printf("\n");
		} else
		if (m == 1)
		{
			for (int i = 1; i <= n; i++)
				if (i <= num)
					printf("*\n");
				else if (i < n)
					printf(".\n");
				else 
					printf("c\n");
		} else
		if (m == 2)
		{
			if (n * m - num == 2)
			{fl = 1;	imp();}
			else
			if (num % 2 == 1)
			{
				if (num < n * m - 1)
				{
					fl = 1;
					printf("Impossible\n");
				} else
					for (int i = 1; i <= n; i++)
						for (int j = 1; j <= m; j++)
							a[i][j] = 1;
				a[n][m] = 2;
			} else
			{
				for (int i = 1; i <= n; i++)
					if (num > 0)
					{
						num -= 2;
						a[i][1] = a[i][2] = 1;
					}
				a[n][m] = 2;
			}
			if (!fl)
			 print();
		} else
		if (n == 2)
		{
			if (n * m - num == 2)
			{fl = 1;
				imp();
			}else
			if (num % 2 == 1)
			{
				if (num < n * m - 1)
				{
					printf("Impossible\n");
					fl = 1;
				} else
					for (int i = 1; i <= n; i++)
						for (int j = 1; j <= m; j++)
							a[i][j] = 1;
				a[n][m] = 2;
			} else
			{
				for (int i = 1; i <= m; i++)
					if (num > 0)
					{
						num -= 2;
						a[1][i] = a[2][i] = 1;
					}
				a[n][m] = 2;
			}
			if (!fl)
				print();
		} else
		{
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					a[i][j] = 1;
			int ll = n*m - num;
			if (ll == 1)
			{
				a[1][1] = 2;
				print();
			} else
			if (ll < 4)
				imp();
			else
			{
				ll -= 4;
				a[1][1] = 2;
				a[1][2] = a[2][1] = a[2][2] = 0;
				if (ll == 0)
					print();
				else
				{
					if (ll == 1)
						imp();
					else
					{
						ll -= 2;
						a[1][3] = a[2][3] = 0;
						if (ll == 0)
							print();
						else
						{
							if (ll == 1)
								imp();
							else
							{
								a[3][1] = a[3][2] = 0;
								ll -= 2;
								if (ll == 0) print();
								else
							{
								for (int i = 4; i <= n; i++)
								{
									if (ll == 0)
										break;
									else if (ll == 1)
									{
										a[3][3] = 0;
										ll--;
										break;
									}
									ll -= 2;
									a[i][1] = a[i][2] = 0;
								}
								if (ll == 0)
									print();
								else
								{
									for (int i = 4; i <= m; i++)
									{
										if (ll == 0)
											break;
										else if (ll == 1)
										{
											a[3][3] = 0;
											ll--;
											break;
										}
										ll -= 2;
										a[1][i] = a[2][i] = 0;
									}
									if (ll == 0)
										print();
									else
									{
										for (int i = 3; i <= n; i++)
											for (int j = 3; j <= m; j++)
											{
												a[i][j] = 0;
												ll--;
												if (ll == 0)
												{
													goto loop;
												}
											}
										loop:;
										print();
									}
								}
							}
						}
					}
					}
				}
			}
			
		}
	}
	return 0;
}
