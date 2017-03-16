# include <stdio.h>
# include <string.h>


char g[55][55];


int gao(int r, int c, int m)
{
	int i, j;
	memset (g, 0, sizeof(g));
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			g[i][j] = '*';
			
	if (m == 1)
	{
		g[1][1] = 'c';
		goto OUTPUT;
	}
	
	if (r == 1){
		for (j = 1; j <= m; j++)
			g[1][j] = '.';
		g[1][1] = 'c';
		goto OUTPUT;
	}
	
	if (c == 1){
		for (i = 1; i <= m; i++)
			g[i][1] = '.';
		g[1][1] = 'c';
		goto OUTPUT;
	}
	
	if (r == 2)
	{
		for (j = 1; j <= m/2; j++)
			g[1][j] = g[2][j] = '.';
		g[1][1] = 'c';
		if (m % 2 != 0 || m == 2){
			puts ("Impossible");
			return 0;
		}
		else goto OUTPUT;
	}
	
	if (c == 2)
	{
		for (i = 1; i <= m/2; i++)
			g[i][1] = g[i][2] = '.';
		g[1][1] = 'c';
		if (m % 2 != 0 || m == 2){
			puts ("Impossible");
			return 0;
		}
		else goto OUTPUT;
	}
	//r >= 3, c >= 3
	int mm = r*c-m;
	if (mm <= (r-2)*(c-2))
	{
		for(i = 1; i <= r; i++)
			for (j = 1; j <= c; j++)
				g[i][j] = '.';
		for (i = r; i >= 3 && mm; i--)
			for (j = c; j >= 3 && mm; j--)
			{
				g[i][j] = '*';
				mm--;
			}
		g[1][1] = 'c';
		goto OUTPUT;
	}
	
	if (m == 2 || m == 3 || m == 5 || m == 7)
	{
		puts ("Impossible");
		return 0;
	}
	int a, b;
	g[1][1] = g[1][2] = g[2][1] = g[2][2] = '.';
	m  -= 4, a = 3, b = 3;
	if (m % 2 == 1)
		g[1][3] = g[2][3] = g[3][3] = g[3][2] = g[3][1] = '.', 
		m-=5, a = 4, b = 4;

	for (j = a; j <= c && m > 0; j++)
	{
		g[1][j] = g[2][j] = '.';
		m -= 2;
	}
	for (i = b; i <= r && m > 0; i++)
	{
		g[i][1] = g[i][2] = '.';
		m -= 2;
	}
	g[1][1] = 'c';
OUTPUT:

	for (i = 1; i <= r; i++)
		puts (g[i]+1);
	return 1;
}


int main()
{
	int T, nCase = 1;
	int r, c, m;
	freopen ("C-small-attempt2.in", "r", stdin);
	freopen ("c-small.txt", "w", stdout);
	scanf ("%d", &T);
	while (T--)
	{
		scanf ("%d%d%d", &r, &c, &m);
		printf ("Case #%d:\n", nCase++);
		int rst = gao(r, c, r*c-m);
		/*if (rst  == 0)
			fprintf (stdout, "%d %d %d\n", r, c, m);
		*/
	}
	return 0;
}
