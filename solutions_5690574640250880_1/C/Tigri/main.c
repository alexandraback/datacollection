#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LN_LEN 1024
#define MAX_RC 51

char grid[MAX_RC][MAX_RC];

int getintarr(const char *str, int *arr, int n)
{
	const char *p = str;
	char *e;
	int i;
	for (i = 0; i < n; i++)
	{
		while (isspace(*p))
			p++;
		int v = strtol(p, &e, 10);
		arr[i] = v;
		p = e + 1;
	}
	return i;
}

void fillgrid(int r, int c, char f)
{
	int i;
	for (i = 0; i < r; i++)
	{
		memset(grid[i], f, c);
		grid[i][c] = 0;
	}
}

void fillrect(int r0, int c0, int nr, int nc, char f)
{
	int i;
	for (i = 0; i < nr; i++)
		memset(&(grid[r0 + i][c0]), f, nc);
}

int solve(FILE *fin, int *pr, int *pc, int cs)
{
	char line[MAX_LN_LEN];
	if (!fgets(line, MAX_LN_LEN - 1, fin))
		return -1.0;
	int arr[3];
	getintarr(line, arr, 3);
	int r = arr[0];
	int c = arr[1];
	int m = arr[2];		
	int rc = r * c;
	int f = rc - m;
	*pr = r;
	*pc = c;
	int x, y;
	int dx, dy;
	int n;
	int nr, nc;
	int rf;
	if (m == 0)
	{
		fillgrid(r, c, '.');
		grid[0][0] = 'c';
		return 1;
	}
	if (f == 1)
	{
		fillgrid(r, c, '*');
		grid[0][0] = 'c';
		return 1;
	}
	if ((r == 1) || (c == 1))
	{
		fillgrid(r, c, '*');
		if (r == 1)
		{
			dx = 1;
			dy = 0;
		}
		else
		{
			dx = 0;
			dy = 1;
		}
		for (x = 0, y = 0, n = 0; n < f; n++, x += dx, y += dy)
			grid[y][x] = '.';
		grid[0][0] = 'c';	
		return 1;
	}
	if ((r == 2) || (c == 2))
	{
		if (f & 1)
			return 0;
		if (f < 4)
			return 0;
		fillgrid(r, c, '*');
		if (r == 2)
		{
			nr = 2;
			nc = f / 2;
		}
		else
		{
			nr = f / 2;
			nc = 2;
		}
		fillrect(0, 0, nr, nc, '.');
		grid[0][0] = 'c';
		return 1;
	}
	if ((r == 4) && (c == 4) && (m == 3))
	{
		fillgrid(r, c, '.');
		grid[r - 2][c - 1] = '*';
		grid[r - 1][c - 2] = '*';
		grid[r - 1][c - 1] = '*';
		grid[0][0] = 'c';
		return 1;
	}
	nc = f / r;
	if (nc > 1)
	{
		rf = f - nc * r;
		if (rf != 1)
		{
			fillgrid(r, c, '*');
			fillrect(0, 0, r, nc, '.');
			if (rf > 0)
				fillrect(0, nc, rf, 1, '.');
			grid[0][0] = 'c';
			return 1;
		}
		else if ((r >= 4) && (nc >= 4) && (f > 16))
		{
			fillgrid(r, c, '*');
			fillrect(0, 0, r, nc, '.');
			fillrect(0, nc, 2, 1, '.');
			grid[r - 1][0] = '*';
			grid[0][0] = 'c';
			return 1;
		}
	}
	nr = f / c;
	if (nr > 1)
	{
		rf = f - nr * c;
		if (rf != 1)
		{
			fillgrid(r, c, '*');
			fillrect(0, 0, nr, c, '.');
			if (rf > 0)
				fillrect(nr, 0, 1, rf, '.');
			grid[0][0] = 'c';
			return 1;
		}
		else if ((nr >= 4) && (c >= 4) && (f > 16))
		{
			fillgrid(r, c, '*');
			fillrect(0, 0, nr, c, '.');
			fillrect(nr, 0, 1, 2, '.');			
			grid[0][c - 1] = '*';
			grid[0][0] = 'c';
			return 1;
		}
	}
	nr = (r > c) ? (c - 1) : (r - 1);
	while (nr > 1)
	{
		nc = f / nr;
		if ((nc > 1) && (nc < c))
		{
			rf = f - nc * nr;
			if (rf != 1)
			{
				fillgrid(r, c, '*');
				fillrect(0, 0, nr, nc, '.');
				if (rf > 0)
					fillrect(0, nc, rf, 1, '.');
				grid[0][0] = 'c';
				return 1;
			}
			else if ((nr >= 4) && (nc >= 4) && (f > 16))
			{
				fillgrid(r, c, '*');
				fillrect(0, 0, nr, nc, '.');
				fillrect(0, nc, 2, 1, '.');
				grid[nr - 1][0] = '*';
				grid[0][0] = 'c';
				return 1;
			}
		}
		nr--;
	}	
	fprintf(stderr, "??? #%-3d: R: %2d, C: %2d, M: %4d, F: %4d\n", cs, r, c, m, f);
	return 0;	
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Invalid number of arguments\n");
		return 1;
	}
	FILE *f = fopen(argv[1], "rt");
	if (f == NULL)
	{
		fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
		return 2;
	}
	FILE *out = stdout;
	if (argc > 2)
	{
		if ((out = fopen(argv[2], "wt")) == NULL)
		{
			fprintf(stderr, "Cannot open output file: %s\n", argv[2]);
			return 3;
		}
	}
	char line[MAX_LN_LEN];
	if (!fgets(line, MAX_LN_LEN - 1, f))
	{
		fprintf(stderr, "Empty input file: %s\n", argv[1]);
		return 4;
	}
	int n = atoi(line);
	if (n < 1)
	{
		fprintf(stderr, "Invalid input file: %s\n", argv[1]);
		return 5;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		int r;
		int c;
		int result = solve(f, &r, &c, i + 1);
		fprintf(out, "Case #%d:\n", i + 1);
		if (!result)
		{
			fprintf(out, "Impossible\n");
			continue;
		}
		int y;
		for (y = 0; y < r; y++)
		{
			fprintf(out, "%s\n", grid[y]);
		}
	}
	fclose(f);
	if (out != stdout)
		fclose(out);
	return 0;
}
