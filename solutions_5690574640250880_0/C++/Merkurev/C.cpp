#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;



const int maxn = 55;
char f[maxn][maxn];
int cnt[maxn][maxn];
bool used[maxn][maxn];


int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {-1, 1, -1, 0, 1, -1, 0, 1};


void dfs(int x, int y, int r, int c)
{
	if (used[x][y] )
		return;
	used[x][y] = true;
	if (cnt[x][y] != 0)
		return;
	for (int d = 0; d < 8; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || r <= nx)
			continue;
		if (ny < 0 || c <= ny)
			continue;
		if (f[nx][ny] == '*')
			continue;
		dfs(nx, ny, r, c);
	}
}

bool test(int r, int c, int n)
{
	memset(cnt, 0, sizeof cnt);
	int x = 0;

	int sx = 0, sy = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (f[i][j] == '*')
				x++;
			else if (f[i][j] == '.')
			{
				for (int d = 0; d < 8; d++)
				{
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx < 0 || r <= nx)
						continue;
					if (ny < 0 || c <= ny)
						continue;
					if (f[nx][ny] == '*')
						cnt[i][j]++;
				}
				if (f[sx][sy] == '*' || cnt[i][j] <= cnt[sx][sy] )
				{
					sx = i;
					sy = j;
				}
			}
			else
			{
				fprintf(stderr, "strange value at field to test\n");
				return false;
			}
		}
		if (f[i][c] != 0)
		{
			fprintf(stderr, "row not end by 0\n");
			return false;
		}
	}
	f[sx][sy] = 'c';
	memset(used, 0, sizeof used);

	//fprintf(stderr, "call dfs...\n");
	dfs(sx, sy, r, c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (f[i][j] != '*' && !used[i][j] )
				return false;
	return true;
}

void fillF(int r, int c, char ch)
{	
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			f[i][j] = ch;

}

void PrintF(int r, int c)
{
	for (int i = 0; i < r; i++)
		printf("\n%s", f[i] );
}


char p[maxn * maxn];

int r, c, n;
bool stupidSolve(bool prn)
{
	for (int i = 0; i < r * c ; i++)
	{
		if (i < n)
			p[i] = '*';
		else
			p[i] = '.';
	}
	do
	{
		memset(f, 0, sizeof f);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				f[i][j] = p[i * c + j];
		if (test(r, c, n) )
		{
			if (prn)
				PrintF(r, c);
			return true;
		}
	} while (next_permutation(p, p + r * c) );
	
	memset(f, 0, sizeof f);

	return false;
}

bool solve()
{
	scanf("%d%d%d", &r, &c, &n);

	for (int remr = 1; remr <= r; remr++)
		for (int remc = 1; remc <= c; remc++)
		{
			int alr = r * c - remr * remc;
			int remn = n - alr;

		//	printf("testing:\nn = %d, r = %d, c = %d, alr = %d\nremr = %d, remc = %d, remn = %d\n", n, r, c, alr, remr, remc, remn);

			if (remn < 0)
				continue;
			if (remn >= remr || remn >= remc)
				continue;
	
			memset(f, 0, sizeof f);
			fillF(r, c, '*');
			fillF(remr, remc, '.');

			if (remr >= remc)
			{
				for (int h = remr - 1; remn > 0 && (h >= 2 || remc == 1); h--)
				{
					remn--;
					f[h][0] = '*';
				}
				if (remn == 1)
				{
					f[remr - 1][1] = '*';
					remn--;
				}
			}
			else
			{
				for (int h = remc - 1; remn > 0 && (h >= 2 || remr == 1); h--)
				{
					remn--;
					f[remr - 1][h] = '*';
				}
				if (remn)
				{
					f[remr - 2][remc - 1] = '*';
					remn--;
				}
			}
			if (remn)
			{
				fprintf(stderr, "not all bomb placed\n");
				continue;
			}
			if (test(r, c, n) )
			{
				PrintF(r, c);
				return true;
			}
	/*		else
			{
				printf("\n__________\n");
				PrintF(r, c);
			}*/
		}
	printf("\nImpossible");
	return false;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		fprintf(stderr, "Case #%d\n", i);
		printf("Case #%d: ", i);
		bool ans = solve();
		bool slow = ans;// stupidSolve(false);
		if (ans != slow)
		{
			stupidSolve(true);
			break;
		}
		printf("\n");
	}



	return 0;
}

