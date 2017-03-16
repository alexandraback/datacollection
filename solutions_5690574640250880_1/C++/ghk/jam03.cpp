#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string PROG = "C-large";
FILE *fin, *fout;

int t, r, c, m, mm;
int i, j, k, p, q, a, b;
bool flag, rev;
char ans[50][50];

int main()
{
	fin = fopen((PROG + ".in").c_str(), "r");
	fout = fopen((PROG + ".out").c_str(), "w");
	
	fscanf(fin, "%d", &t);
	for (k = 1; k <= t; k++)
	{
		fscanf(fin, "%d %d %d", &r, &c, &m);
		rev = 0;
		if (r > c)
		{
			i = r; r = c; c = i;
			rev = 1;
		}
		if (r == 1)
		{
			flag = 1;
			for (i = 0; i < c - 1; i++) ans[0][i] = '.';
			for (i = 0; i < m; i++) ans[0][i] = '*';
			ans[0][c - 1] = 'c';
		}
		else if (m == r * c - 1)
		{
			flag = 1;
			for (i = 0; i < r; i++)
				for (j = 0; j < c; j++)
				{
					ans[i][j] = '*';
				}
			ans[0][0] = 'c';
		}
		else
		{
			flag = 0;
			mm = r * c - m;
			for (p = 2; p <= r; p++)
			{
				q = mm / p;
				a = mm % p;
				if (a > 0)
				{
					a = p - a;
					q++;
				}
				if (q > c) continue;
				if (q < p) break;
				if ((q <= 3) && (a > 0) && ((p < r) || (q < c))) continue;
				if ((q == 3) && (a > 1)) continue;
				if ((p == 2) && (a > 0)) continue;
				if (q == 3)
				{
					flag = 1;
					for (i = 0; i < r; i++)
						for (j = 0; j < c; j++)
						{
							ans[i][j] = '*';
						}
					for (i = 0; i < p; i++)
						for (j = 0; j < q; j++)
						{
							ans[i][j] = '.';
						}
					for (i = 0; i < a; i++)
						ans[i][0] = '*';
					if (a == 1)
						ans[a][2] = 'c';
					else
						ans[0][0] = 'c';
					break;
				}
				else if (a < p - 1)
				{
					flag = 1;
					for (i = 0; i < r; i++)
						for (j = 0; j < c; j++)
						{
							ans[i][j] = '*';
						}
					for (i = 0; i < p; i++)
						for (j = 0; j < q; j++)
						{
							ans[i][j] = '.';
						}
					for (i = 0; i < a; i++)
						ans[p - i - 1][0] = '*';
					ans[0][0] = 'c';
					break;
				}
				else if ((p >= 3) && ((q > 4) || ((p == r) && (q == c))))
				{
					flag = 1;
					for (i = 0; i < r; i++)
						for (j = 0; j < c; j++)
						{
							ans[i][j] = '*';
						}
					for (i = 0; i < p; i++)
						for (j = 0; j < q; j++)
						{
							ans[i][j] = '.';
						}
					for (i = 0; i < a - 1; i++)
						ans[p - i - 1][0] = '*';
					ans[p - 1][1] = '*';
					ans[0][0] = 'c';
					break;
				}
				else if (a < q - 1)
				{
					flag = 1;
					for (i = 0; i < r; i++)
						for (j = 0; j < c; j++)
						{
							ans[i][j] = '*';
						}
					for (i = 0; i < p; i++)
						for (j = 0; j < q; j++)
						{
							ans[i][j] = '.';
						}
					for (i = 0; i < a; i++)
						ans[p - 1][q - i - 1] = '*';
					ans[0][0] = 'c';
					break;
				}
			}
		}
		fprintf(fout, "Case #%d:\n", k);
		if (flag == 0)
		{
			fprintf(fout, "Impossible\n");
		}
		else
		{
			if (rev == 0)
			{
				for (i = 0; i < r; i++)
				{
					for (j = 0; j < c; j++)
						fprintf(fout, "%c", ans[i][j]);
					fprintf(fout, "\n");
				}
			}
			else
			{
				for (j = 0; j < c; j++)
				{
					for (i = 0; i < r; i++)
						fprintf(fout, "%c", ans[i][j]);
					fprintf(fout, "\n");
				}
			}
			
		}
	}
	return 0;
}