#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

#define min(a, b) (((a) < (b)) ? (a) : (b))

void print(int fr, int fc, int ac, int r, int c)
{
	for (int qr = 0; qr < r; qr++)
	{
		for (int qc = 0; qc < c; qc++)
		{
			if (qr == 0 && qc == 0)
				printf("c");
			else if (qr < fr)
			{
				if (qc < fc)
					printf(".");
				else
					printf("*");
			}
			else if (qr == fr)
			{
				if (qc < ac)
					printf(".");
				else
					printf("*");
			}
			else
				printf("*");
		}
		printf("\n");
	}
}

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
		bool p = stupidFind(r, c, 0, 0, m);
/*
		for (ac = 2; ac <= c && !possible; ac++)
		{
			for (fc = ac; fc <= c && !possible; fc++)
			{
				if ((m - ac) % fc != 0 || (m - ac) / fc + 1 > r || (m - ac) / fc <= 0 || ((m - ac) / fc == 1 && ac != fc))
					continue;

				fr = (m - ac) / fc;

				possible = true;

				print(fr, fc, ac, r, c);
			}
		}
		if (!possible)
		{
			if (m == 1)
				print(1, 1, 0, r, c), possible = true;
			else if (r == 1)
				print(1, m, 0, r, c), possible = true;
			else if (c == 1)
				print(m, 1, 0, r, c), possible = true;
			else
				printf("Impossible\n");
		}
		if (possible != p)
		{
			printf("ACHTUNG %d\n\n\n\nActually:\n", i);
			if (p)
			{
				for (int qr = 0; qr < r; qr++)
				{
					for (int qc = 0; qc < c; qc++)
						printf("%c", qr == gr && qc == gc ? 'c' : good[qr][qc]);
					printf("\n");
				}
			}
			else
				printf("Impossible\n");
			printf("\n\n");
		}*/

		if (p)
		{
			for (int qr = 0; qr < r; qr++)
			{
				for (int qc = 0; qc < c; qc++)
					printf("%c", qr == gr && qc == gc ? 'c' : good[qr][qc]);
				printf("\n");
			}
		}
		else
			printf("Impossible\n");
	}
}