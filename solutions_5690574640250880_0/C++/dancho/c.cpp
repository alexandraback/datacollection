#include <cstdio>
#include <cstring>
#include <algorithm>

int r, c, m;
bool fl;
char b[64][64];

void printBoard(int t)
{
	printf("Case #%d:\n", t);
	if (!fl)
	{
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				printf("%c", b[i][j]);
			printf("\n");
		}
	}
	else
	{
		for (int i = 0; i < c; ++i)
		{
			for (int j = 0; j < r; ++j)
				printf("%c", b[j][i]);
			printf("\n");
		}
	}
}

void printImpos(int t)
{
	printf("Case #%d:\nImpossible\n", t);
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; ++t)
	{
		scanf("%d %d %d", &r, &c, &m);
		fl = 0;
		if (r > c)
		{
			std::swap(r, c);
			fl = 1;
		}
		m = r * c - m;
		memset(b, '*', sizeof(b));
		if (m == 1)
		{
			b[0][0] = 'c';
			printBoard(t);
			continue;
		}
		if (r == 1)
		{
			for (int i = 0; i < m; ++i)
				b[0][i] = '.';
			b[0][0] = 'c';
			printBoard(t);
			continue;
		}
		if (r == 2)
		{
			if (m % 2 == 1 || m <= 3)
				printImpos(t);
			else
			{
				for (int i = 0; i < m / 2; ++i)
					b[0][i] = b[1][i] = '.';
				b[0][0] = 'c';
				printBoard(t);
			}
			continue;
		}
		if (m == 5 || m == 7 || m < 4)
		{
			printImpos(t);
			continue;
		}
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				b[i][j] = '.';
		b[0][0] = 'c';
		m -= 4;
		int nr = 2, nc = 2;
		bool f = 0;
		while (m >= 2 && (nr < r || nc < c))
		{
			if (f == 0)
			{
				if (nr < r)
				{
					b[nr][0] = '.';
					b[nr][1] = '.';
					m -= 2;
					++nr;
				}
				else if (nc < c)
				{
					b[0][nc] = '.';
					b[1][nc] = '.';
					m -= 2;
					++nc;
				}
			}
			else if (f == 1)
			{
				if (nc < c)
				{
					b[0][nc] = '.';
					b[1][nc] = '.';
					m -= 2;
					++nc;
				}
				else if (nr < r)
				{
					b[nr][0] = '.';
					b[nr][1] = '.';
					m -= 2;
					++nr;
				}
			}
			f = 1 - f;
		}
		for (int i = 2; i < r; ++i)
		{
			for (int j = 2; j < c; ++j)
			{
				if (m > 0)
				{
					b[i][j] = '.';
					--m;
				}
			}
		}
		printBoard(t);
	}
	return 0;
}
