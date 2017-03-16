#include <algorithm>
#include <cassert>
#include <cstdio>
using namespace std;

int T, t;
int r, c, m;

bool ok;
char ans[64][64];
int bomb;
void clr()
{
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			ans[i][j] = '*';
	bomb = r * c;
}
bool chk()
{
	return bomb + m == r * c;
}
void dig(int i, int j)
{
	if(!chk())
		for(int di = -1; di <= +1; di++)
			for(int dj = -1; dj <= +1; dj++)
			{
				int ni = i + di, nj = j + dj;
				if(0 <= ni && ni < r && 0 <= nj && nj < c)
					if(ans[ni][nj] == '*')
					{
						ans[ni][nj] = '.';
						bomb--;
					}
			}
}

bool flag;
void flip()
{
	swap(r, c);
	for(int i = 0; i < 64; i++)
		for(int j = 0; j < i; j++)
			swap(ans[i][j], ans[j][i]);
}
void get()
{
	scanf("%d %d %d", &r, &c, &m);
	m = r * c - m;
	flag = (r > c);
	if(flag)
		flip();
}
void open(int i, int j)
{
	if(ans[i][j] == '.')
	{
		char num = '0';
		for(int di = -1; di <= +1; di++)
			for(int dj = -1; dj <= +1; dj++)
			{
				int ni = i + di, nj = j + dj;
				if(0 <= ni && ni < r && 0 <= nj && nj < c)
					if(ans[ni][nj] == '*')
						num++;
			}
		ans[i][j] = num;
		if(num == '0')
			for(int di = -1; di <= +1; di++)
				for(int dj = -1; dj <= +1; dj++)
				{
					int ni = i + di, nj = j + dj;
					if(0 <= ni && ni < r && 0 <= nj && nj < c)
						if(ans[ni][nj] == '.')
							open(ni, nj);
				}
	}
}
void verify()
{
	if(ok)
	{
		int si = -1, sj = -1;
		int cm = m;
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				assert(ans[i][j] == 'c'
						|| ans[i][j] == '.'
						|| ans[i][j] == '*');
				if(ans[i][j] == 'c')
				{
					assert(si == -1);
					si = i;
					sj = j;
				}
				else if(ans[i][j] == '*')
					cm++;
			}
		assert(cm == r * c);
		ans[si][sj] = '.';
		open(si, sj);
		fprintf(stderr, "Case #%d: %d %d %d\n", t, r, c, r * c - m);
		for(int i = 0; i < r; fprintf(stderr, "\n"), i++)
			for(int j = 0; j < c; j++)
				fprintf(stderr, "%c", ans[i][j]);
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				assert(ans[i][j] != '.');
	}
	else
		fprintf(stderr, "Case #%d: %d %d %d\nImpossible!\n", t, r, c, r * c - m);
}
void put()
{
	if(flag)
		flip();

	printf("Case #%d:\n", t);
	if(ok)
		for(int i = 0; i < r; printf("\n"), i++)
			for(int j = 0; j < c; j++)
				printf("%c", ans[i][j]);
	else
		printf("Impossible\n");

	verify();
}

int main()
{
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		get();

		if(r == 1)
		{
			ok = true;
			ans[0][0] = 'c';
			for(int i = 1; i < m; i++)
				ans[0][i] = '.';
			for(int i = m; i < c; i++)
				ans[0][i] = '*';
		}
		else if(r == 2)
		{
			if(m == 1)
			{
				ok = true;
				for(int i = 0; i < r; i++)
					for(int j = 0; j < c; j++)
						ans[i][j] = '*';
				ans[0][0] = 'c';
			}
			else if(m == 2)
				ok = false;
			else if(m % 2 == 1)
				ok = false;
			else
			{
				ok = true;
				for(int i = 0; i < r; i++)
				{
					for(int j = 0; j < m / 2; j++)
						ans[i][j] = '.';
					for(int j = m / 2; j < c; j++)
						ans[i][j] = '*';
				}
				ans[0][0] = 'c';
			}
		}
		else
		{
			if(m == 1)
			{
				ok = true;
				for(int i = 0; i < r; i++)
					for(int j = 0; j < c; j++)
						ans[i][j] = '*';
				ans[0][0] = 'c';
			}
			else if(m == 2 || m == 3 || m == 5 || m == 7)
				ok = false;
			else if(m % 2 == 0)
			{
				ok = true;
				clr();
				dig(0, 0);
				for(int j = 1; j < c; j++)
					dig(0, j);
				for(int j = c - 1; j >= 0; j--)
					for(int i = 1; i < r; i++)
						dig(i, j);
				ans[0][0] = 'c';
				assert(chk());
			}
			else if(r == 4 && c == 4 && m == 13) 
			{
				ok = true;
				for(int i = 0; i < 4; i++)
					for(int j = 0; j < 4; j++)
						ans[i][j] = '.';
				ans[0][0] = 'c';
				ans[2][3] = ans[3][2] = ans[3][3] = '*';
			}
			else
			{
				ok = true;
				clr();
				dig(1, 1);
				for(int j = 2; j < c; j++)
					dig(0, j);
				for(int j = c - 1; j >= 0; j--)
					for(int i = 1; i < r; i++)
						dig(i, j);
				ans[1][1] = 'c';
				assert(chk());
			}
		}

		put();
	}

	return 0;
}
