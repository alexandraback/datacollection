#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100;
char table[N][N];

void clear()
{
	for (int i = 0; i < N; i++)
		for (int s = 0; s < N; s++)
			table[i][s] = '*';
}

void simpleCase(int ind, int a, int b, int f)
{                                           
	printf("Case #%d:\n", ind + 1);
	for (int i = 0; i < a; i++, puts(""))
		for (int s = 0; s < b; s++)
		{
			if (i == 0 && s == 0)
				putchar('c');
			else if (f > 0)
				putchar('.');
			else
				putchar('*');
			f--;
		}
}

void fillE(int pos, int cnt)
{
	for (int i = 0; i < cnt; i++)
		table[i][pos] = '.';
}

void printTable(int ind, int a, int b)
{
	printf("Case #%d:\n", ind + 1);
	for (int i = 0; i < a; i++, puts(""))
		for (int s = 0; s < b; s++)
		{
			if (i == 0 && s == 0)
				putchar('c');
			else
				putchar(table[i][s]);
		}
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int r, c, m;
		scanf("%d%d%d", &r, &c, &m); 
		m = r * c - m;
		if (r == 1 || c == 1 || m == 1)
		{
			simpleCase(i, r, c, m);
			continue;
		}
		clear();
		bool ok = false;
		for (int len = 2; len <= c && !ok; len++)
			for (int lstVal = 2; lstVal <= r && !ok; lstVal++)
				for (int cnt = 2; cnt <= min(len, 3) && !ok; cnt++)
				{           	
					if (cnt == 2 && len != c && len != 2)
						continue;
					int k = lstVal * cnt + 2 * (len - cnt);
					if (lstVal * len < m || k > m)
						continue;
					for (int s = 0; s < len; s++)
					{
						if (s < cnt)
							fillE(s, lstVal);
						else
						{
							fillE(s, min(2 + m - k, lstVal));
							k += min(m - k, lstVal - 2);
						}
					}	
					ok = true;
					printTable(i, r, c);
				}
		if (!ok)
			printf("Case #%d:\nImpossible\n", i + 1);
	}

	return 0;
}