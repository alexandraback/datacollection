#define _CRT_SECURE_NO_WARNINGS C4996
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
__int64 table[15][15];
__int64 n, X;
int T, P;
__int64 stval[10010];
__int64 edval[10010];
__int64 check[110];
__int64 rech;
char st[100010];
char cfc(int dt)
{
	if (dt == 1) return '1';
	if (dt == 2) return 'i';
	if (dt == 3) return 'j';
	if (dt == 4) return 'k';
}
int cfi(char dt)
{
	if (dt == '1') return 1;
	if (dt == 'i') return 2;
	if (dt == 'j') return 3;
	if (dt == 'k') return 4;
}
int getdiff(int l, int r)
{
	int i;

	for (i = 1; i <= 8; i++)
	{
		if (table[i][r] == l) return i;
	}
}
int main()
{
	int i, a, j, r1, r2;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	table[1][1] = 1; table[1][2] = 2; table[1][3] = 3; table[1][4] = 4;
	table[2][1] = 2; table[2][2] = 5; table[2][3] = 4; table[2][4] = 7;
	table[3][1] = 3; table[3][2] = 8; table[3][3] = 5; table[3][4] = 2;
	table[4][1] = 4; table[4][2] = 3; table[4][3] = 6; table[4][4] = 5;

	for (i = 1; i <= 4; i++)
	{
		for (a = 1; a <= 4; a++)
		{
			if (table[i][a] > 4) table[i][a + 4] = table[i][a] - 4;
			else table[i][a + 4] = table[i][a] + 4;
		}
	}

	for (i = 1; i <= 4; i++)
	{
		for (a = 1; a <= 8; a++)
		{
			if (table[i][a] > 4) table[i + 4][a] = table[i][a] - 4;
			else table[i + 4][a] = table[i][a] + 4;
		}
	}

	scanf("%d", &T);
	__int64 stdata = 0, eddata = 0;
	__int64 data = 0, data1 = 0, data2 = 0;
	__int64 cnt = 0, cnt1 = 0;
	while (T)
	{
		scanf("%I64d%I64d", &n, &X);
		scanf("%s\n", st + 1);
		rech = 1;
		for (i = 1; i <= n; i++)
		{
			stval[i] = table[rech][cfi(st[i])];
			rech = table[rech][cfi(st[i])];
		}
		stdata = 1;
		for (i = n; i >= 1; i--)
		{
			edval[i] = table[cfi(st[i])][stdata];
			stdata = table[cfi(st[i])][stdata];
		}
		stval[0] = 1;
		stval[n + 1] = 1;
		edval[0] = 1;
		edval[n + 1] = 1;
		int sw = 0;
		for (i = 1; i <= n; i++)
		{
			data = stval[i];
			cnt = 0;
			for (r1 = 0; r1 < 4; r1++)
			{
				cnt = r1;
				if (cnt>X) break;
				if (data == cfi('i'))
				{
					for (a = 1; a <= n; a++)
					{
						data1 = edval[a];
						for (r2 = 0; r2 < 4; r2++)
						{
							cnt1 = r2;
							if (cnt + cnt1>X) break;
							if (data1 == cfi('k'))
							{
								if (cnt + cnt1 + 2 <= X)
								{
									//if ((X - cnt - cnt1 - 2) % 4 == 0)
									//{
									data2 = edval[i + 1];
									for (j = 1; j <= (X - cnt - cnt1 - 2) % 4; j++)
									{
										data2 = table[data2][rech];
									}
									data2 = table[data2][getdiff(edval[1], edval[a])];
									if (data2 == cfi('j'))
									{
										sw = 1;
										break;
									}
									//}
								}
								if (a > i && cnt + cnt1 + 1 <= X)
								{
									if ((X - cnt - cnt1 - 1) % 4 == 0)
									{
									data2 = getdiff(edval[i + 1], edval[a]);
									if (data2 == cfi('j'))
									{
										sw = 1;
										break;
									}
									}
								}
							}
							data1 = table[data1][rech];
							if (sw == 1) break;
						}
					}
				}
				//if (rech == 1) break;
				data = table[rech][data];
				if (sw == 1) break;
			}
			if (sw == 1) break;
			/*if (rech == 1) continue;
			data = table[rech][data];
			cnt = 1;
			if (data == cfi('i'))
			{
			}
			if (sw == 1) break;
			data = table[rech][data];
			cnt = 2;
			if (data == cfi('i'))
			{
			}
			if (sw == 1) break;
			data = table[rech][data];
			cnt = 3;
			if (data == cfi('i'))
			{
			}*/
		}
		/*for (i = 1; i <= 8; i++)
		{
		check[i] = 0;
		}
		for (i = 1; i <= 8; i++)
		{
		check[i] = 0;
		}*/
		T--;
		if (sw == 0) printf("Case #%d: NO\n", ++P);
		else  printf("Case #%d: YES\n", ++P);
	}

	return 0;
}
