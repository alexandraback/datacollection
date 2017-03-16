#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream.h>

#define ccMAX(a, b) ((a > b) ? a : b)
#define ccMIN(a, b) ((a < b) ? a : b)
#define LEN 50
static char g[LEN+1][LEN+1] = {0};

void draw(bool reverse)
{
	if (!reverse)
	{
		for (int i = 0; i < LEN; i++)
		{
			if (0 == g[i][0])
			{
				return;	
			}
			
			printf("%s\n", g[i]);	
		}			
	}
	else
	{
		int r = strlen(g[0]);
		for (int i = 0; i < r; i++)
		{
			char line[LEN+1];
			memset(line, 0, sizeof(line));
			int ic = 0;
		
			for (int j = 0; j < LEN+1; j++)
			{
				line[ic++] = g[j][r - i - 1];
			}
			
			printf("%s\n", line);
		}		
	}
}

void build1(int r, int c, int m)
{
	memset(g, 0, sizeof(g));
	
	int nmax = ccMAX(r, c);
	
	for (int i = 0; i < nmax; i++)
	{
			if (i < m)
			{
				g[0][i] = '*';
			}
			else if ((nmax - 1) == i)
			{
				g[0][i] = 'c';
			}
			else
			{
				g[0][i] = '.';
			}
	}
	
	if (1 == r)
	{
		draw(false);	
	}
	else
	{
		draw(true);
	}
}

void build2(int r, int c, int m)
{
	memset(g, 0, sizeof(g));
	int nmax = ccMAX(r, c);
	
	for (int i = 0; i < nmax; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if ((2 * i + j) < m)
			{
				g[j][i] = '*';
			}
			else if ((nmax - 1 == i)
				&& (1 == j))
			{
				g[j][i] = 'c';
			}
			else
			{
				g[j][i] = '.';
			}
		}
	}

	if (2 == r)
	{
		draw(false);	
	}
	else
	{
		draw(true);	
	}
}

void build3(int r, int c, int m)
{
	memset(g, 0, sizeof(g));
	
	int newr = ccMAX(r, c);
	int newc = ccMIN(r, c);
	int ocount = r * c - m;
	
	if (newc < 3)
	{
		printf("error!!!!!!\n");
		return;
	}
	// for 1 case
	if (1 == ocount)
	{
		for (int i = 0; i < newr; i++)
		{
			for (int j = 0; j < newc; j++)
			{
				g[i][j] = '*';
			}
		}
		
		g[newr-1][newc-1] = 'c';
	}
	// for m <= (r-2)*c - 2
	else if ((ocount > 2 * newc + 1)
		|| (ocount == 2 * newc))
	{
		int vmod = m % newc;
		int vdiv = (m - vmod) / newc;
		for (int i = 0; i < vdiv; i++)
			for (int j = 0; j < newc; j++)
		{
			g[i][j] = '*';
		}
		
		if (vmod == newc - 1)
		{
			g[vdiv+1][0] = '*';
			for (int i = 0; i < vmod - 1; i++)
			{
				g[vdiv][i] = '*';
			}
			g[vdiv][vmod - 1] = '.';
			g[vdiv][vmod] = '.';
			
			for (int i = 1; i < newc; i++)
			{
				g[vdiv+1][i] = '.';
			}
			
			for (int i = vdiv+2; i < newr; i++)
				for (int j = 0; j < newc; j++)
			{
				g[i][j] = '.';
			}
			
			g[newr-1][newc-1] = 'c';
		}
		else
		{
			for (int i = 0; i < newc; i++)
			{
				if (i < vmod)
				{
					g[vdiv][i] = '*';
				}
				else
				{
					g[vdiv][i] = '.';
				}
				
				for (int i = vdiv+1; i < newr; i++)
					for (int j = 0; j < newc; j++)
				{
					g[i][j] = '.';
				}
			}
			g[newr-1][newc-1] = 'c';
		}
	}
	// for m = (r-2)*c - 1 case
	else if (ocount == 2 * newc + 1)
	{
		// fill all cells default value
		for (int i = 0; i < newr; i++)
		{
			for (int j = 0; j < newc; j++)
			{
				g[i][j] = '*';
			}	
		}
		
		for (int i = newr-3; i < newr; i++)
		{
			for (int j = newc-3; j < newc; j++)
			{
				g[i][j] = '.';
			}
		}
		
		for (int i = newr-2; i < newr; i++)
			for (int j = newc - (3+((ocount-9)/2)); j < newc - 3; j++)
			{
				g[i][j] = '.';
			}
			
		g[newr-1][newc-1] = 'c';
	}
	// for m > (r-2)*c case
	else
	{
		// fill all cells default value
		for (int i = 0; i < newr; i ++)
		{
			for (int j = 0; j < newc; j++)
			{
				g[i][j] = '*';
			}	
		}
		
		if (ocount % 2 == 1)
		{
			for (int i = newr-3; i < newr; i++)
			{
				for (int j = newc-3; j < newc; j++)
				{
					g[i][j] = '.';
				}
			}
			
			for (int i = newr-2; i < newr; i++)
				for (int j = newc - (3+((ocount-9)/2)); j < newc - 3; j++)
				{
					g[i][j] = '.';
				}
				
			g[newr-1][newc-1] = 'c';
		}
		else
		{
			for (int i = newr-2; i < newr; i++)
				for (int j = newc - (ocount/2); j < newc; j++)
				{
					g[i][j] = '.';
				}
				
			g[newr-1][newc-1] = 'c';
		}
	}
	
	if (r >= c)
	{
		draw(false);
	}
	else
	{
		draw(true);
	}
}

int main (void)
{
	int t = 0;
	cin >> t;
	
	for (int ti = 1; ti < t+1; ti++)
	{
		int r = 0;
		int c = 0;
		int m = 0;
		
		cin >> r;
		cin >> c;
		cin >> m;
		
		int ocount = r*c - m;
		if (1 == r
			|| 1 == c)
		{
			if (m < r*c)
			{
				printf("Case #%d:\n", ti);
				build1(r, c , m);
			}
			else
			{
				printf("Case #%d:\n", ti);
				printf("Impossible\n");
			}
		}
		else if (2 == r
			|| 2 == c)
		{
			if (1 == ocount
				|| ((4 <= ocount) && (ocount % 2 == 0)))
			{
				printf("Case #%d:\n", ti);
				build2(r, c, m);
			}
			else
			{
				printf("Case #%d:\n", ti);
				printf("Impossible\n");
			}
		}
		else 
		{
			if (ocount == 2 
				|| ocount == 3
				|| ocount == 5
				|| ocount == 7)
			{
				printf("Case #%d:\n", ti);
				printf("Impossible\n");
			}
			else
			{
				printf("Case #%d:\n", ti);
				build3(r, c, m);
			}
		}
	}  
	return 0;
}
