#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std;

#define min(a, b) (((a) < (b)) ? (a) : (b))

char field[100][100];
char good[100][100];
int gr, gc;

int dx[] = {-1, -1, -1, 0, 1, 1,  1,  0};
int dy[] = {-1,  0,  1, 1, 1, 0, -1, -1};

void paint(int r, int c, int sr, int sc)
{
	field[sr][sc] = ',';
	int nz = 0;
	for (int k = 0; k < 8; k++)
		if (sr + dx[k] >= 0 && sr + dx[k] < r && sc + dy[k] >= 0 && sc + dy[k] < c)
			if (field[sr + dx[k]][sc + dy[k]] == '*')
			{
				nz++;
				return;
			}
	for (int k = 0; k < 8; k++)
		if (sr + dx[k] >= 0 && sr + dx[k] < r && sc + dy[k] >= 0 && sc + dy[k] < c &&
			field[sr + dx[k]][sc + dy[k]] == '.')
			paint(r, c, sr + dx[k], sc + dy[k]);
}

bool check(int r, int c, int sr, int sc)
{
	if (field[sr][sc] != '.')
		return false;
	paint(r, c, sr, sc);
	bool nice = true;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (field[i][j] == '.')
				nice = false;
			if (field[i][j] == ',')
				field[i][j] = '.';
		}
	if (nice)
	{
		gr = sr;
		gc = sc;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				good[i][j] = field[i][j];
	}
	return nice;
}

bool stupidFind(int r, int c, int cr, int cc, int ml)
{
	int nc = cc + 1, nr = cr;
	if (nc >= c)
	{
		nr++;
		nc = 0;
	}
	if (cr >= r)
	{
		if (ml)
			return false;
		for (int sr = 0; sr < r; sr++)
			for (int sc = 0; sc < c; sc++)
				if (check(r, c, sr, sc))
					return true;
		return false;
	}
	if (ml > 0)
	{
		field[cr][cc] = '.';
		if (stupidFind(r, c, nr, nc, ml - 1))
			return true;
	}
	field[cr][cc] = '*';
	return stupidFind(r, c, nr, nc, ml);
}

int res[100], asz;

bool betterSol(int r, int c, int left, int prev, int rsz, bool less)
{
	if (left < 0 || rsz > r)
		return false;
	if (left > 0 && prev == 0)
		return false;
	if (left == 0)
	{
		asz = rsz;
		return asz != 1;
	}
	if (!less)
	{
		res[rsz] = prev;
		return betterSol(r, c, left - prev, prev, rsz + 1, true);
	}
	else
		for (int i = min(prev, c); i >= 2; i--)
		{
			res[rsz] = i;
			if (betterSol(r, c, left - i, i, rsz + 1, rsz > 1))
				return true;
		}
	return false;
}

bool betterSol(int r, int c, int m)
{
	if (r == 1 || m == 1)
	{
		res[0] = m;
		asz = 1;
		return true;
	}
	if (c == 1)
	{
		for (int i = 0; i < m; i++)
			res[i] = 1;
		asz = m;
		return true;
	}
	return betterSol(r, c, m, c + 1, 0, true);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d:\n", i);
		int r, c, m;
		int fr, fc, ac;
		bool possible = false;
		cin >> r >> c >> m;
		m = r * c - m;
		bool p = betterSol(r, c, m);

		if (p)
		{
			for (int qr = 0; qr < r; qr++)
			{
				for (int qc = 0; qc < c; qc++)
					if (asz > qr && qc < res[qr])
						printf(!qr && !qc ? "c" : ".");
					else
						printf("*");
				printf("\n");
			}
		}
		else
			printf("Impossible\n");
	}
}