#include <stdio.h>

char s[10][10];

int verif (char ch)
{
	int a[6][6] = {0};
	int i, j, x;
	
	for (i = 1; i <= 4; i ++)
		for (j = 1; j <= 4; j ++)
			if (s[i][j] == ch || s[i][j] == 'T')
				a[i][j] = 1;
	if (a[1][1] + a[2][2] + a[3][3] + a[4][4] == 4 || a[4][1] + a[3][2] + a[2][3] + a[1][4] == 4)
		return 1;
	for (i = 1; i <= 4; i ++)
	{
		x = 0;
		for (j = 1; j <= 4; j ++)
			x += a[i][j];
		if (x == 4)
			return 1;
	}
	for (j = 1; j <= 4; j ++)
	{
		x = 0;
		for (i = 1; i <= 4; i ++)
			x += a[i][j];
		if (x == 4)
			return 1;
	}
	return 0;
}

int main ()
{
	freopen ("input.in", "r", stdin);
	freopen ("output.out", "w", stdout);

	int tt, t, i, j;
	
	scanf ("%d", &tt);
	for (t = 1; t <= tt; t ++)
	{
		for (i = 0; i <= 4; i ++)
			gets (s[i] + 1);
		if (verif ('X'))
		{
			printf ("Case #%d: X won\n", t);
			continue;
		}
		if (verif ('O'))
		{
			printf ("Case #%d: O won\n", t);
			continue;
		}
		int ok = 0;
		for (i = 1; i <= 4; i ++)
			for (j = 1; j <= 4; j ++)
				if (s[i][j] == '.')
					ok = 1;
		if (ok == 0)
			printf ("Case #%d: Draw\n", t);
		else
			printf ("Case #%d: Game has not completed\n", t);
	}
	return 0;
}
