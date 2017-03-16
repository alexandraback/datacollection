#include <cstdio>
#include <cstring>

int R, C, M, revealed;

char t[51][51], t2[51][51];

void rec (int y, int x)
{
	int bombs = 0;

	++revealed;

	// 0
	if (y - 1 >= 0 && t2[y-1][x] == '*')
	{
		bombs++;
	}

	// 1
	if (y - 1 >= 0 && x + 1 < C && t2[y-1][x+1] == '*')
	{
		bombs++;
	}

	// 2
	if (x + 1 < C && t2[y][x+1] == '*')
	{
		bombs++;
	}

	// 3
	if (x + 1 < C && y + 1 < R && t2[y+1][x+1] == '*')
	{
		bombs++;
	}

	// 4
	if (y + 1 < R && t2[y+1][x] == '*')
	{
		bombs++;
	}

	// 5
	if (x - 1 >= 0 && y + 1 < R && t2[y+1][x-1] == '*')
	{
		bombs++;
	}

	// 6
	if (x - 1 >= 0 && t2[y][x-1] == '*')
	{
		bombs++;
	}

	// 7
	if (x - 1 >= 0 && y - 1 >= 0 && t2[y-1][x-1] == '*')
	{
		bombs++;
	}

	t2[y][x] = bombs + '0';

	if (bombs == 0)
	{
		// 0
		if (y - 1 >= 0 && t2[y-1][x] == '.')
		{
			rec(y - 1, x);
		}

		// 1
		if (y - 1 >= 0 && x + 1 < C && t2[y-1][x+1] == '.')
		{
			rec(y - 1, x + 1);
		}

		// 2
		if (x + 1 < C && t2[y][x+1] == '.')
		{
			rec(y, x + 1);
		}

		// 3
		if (x + 1 < C && y + 1 < R && t2[y+1][x+1] == '.')
		{
			rec(y + 1, x + 1);
		}

		// 4
		if (y + 1 < R && t2[y+1][x] == '.')
		{
			rec(y + 1, x);
		}

		// 5
		if (x - 1 >= 0 && y + 1 < R && t2[y+1][x-1] == '.')
		{
			rec(y + 1, x - 1);
		}

		// 6
		if (x - 1 >= 0 && t2[y][x-1] == '.')
		{
			rec(y, x - 1);
		}

		// 7
		if (x - 1 >= 0 && y - 1 >= 0 && t2[y-1][x-1] == '.')
		{
			rec(y - 1, x - 1);
		}
	}
}

int variant0(int m)
{
	int dir, x, y;

	memset(t, '.', sizeof(t));
	dir = 0;
	x = y = 0;

	while (m > 0)
	{
		switch (dir)
		{
		case 0:
			if (x + 1 < C && t[y][x+1] == '.')
			{
				t[y][x++] = '*';
				--m;
			}
			else
			{
				dir = 1;
			}
			break;

		case 1:
			if (y + 1 < R && t[y+1][x] == '.')
			{
				t[y++][x] = '*';
				--m;
			}
			else
			{
				dir = 2;
			}
			break;

		case 2:
			if (x - 1 >= 0 && t[y][x-1] == '.')
			{
				t[y][x--] = '*';
				--m;
			}
			else
			{
				dir = 3;
			}
			break;

		case 3:
			if (y - 1 >= 0 && t[y-1][x] == '.')
			{
				t[y--][x] = '*';
				--m;
			}
			else
			{
				dir = 0;
			}
			break;
		}
	}

	return dir;
}

bool prep_1(void)
{
	int x, y;

	for (y = 0; y < R; y++)
	{
		for (x = 0; x < C; x++)
		{
			if (t[y][x] == '.')
			{
				t[y][x] = '*';
				return true;
			}
		}
	}

	return false;
}

bool prep_2(void)
{
	int x, y;

	for (y = 0; y < R; y++)
	{
		for (x = C - 1; x >= 0; x--)
		{
			if (t[y][x] == '.')
			{
				t[y][x] = '*';
				return true;
			}
		}
	}

	return false;
}

int prep_3(void)
{
	int x, y;

	for (y = R - 1; y >= 0; y--)
	{
		for (x = C - 1; x >= 0; x--)
		{
			if (t[y][x] == '.')
			{
				t[y][x] = '*';
				return true;
			}
		}
	}

	return false;
}

int prep_4(void)
{
	int x, y;

	for (y = R - 1; y >= 0; y--)
	{
		for (x = 0; x < C; x++)
		{
			if (t[y][x] == '.')
			{
				t[y][x] = '*';
				return true;
			}
		}
	}

	return false;
}

bool variant1(int dir)
{
	variant0(M-1);

	switch (dir)
	{
	case 1:
		return prep_1();

	case 2:
		return prep_2();

	case 3:
		return prep_3();

	case 4:
		return prep_4();
	}

	return false;
}

bool variant2(int dir1, int dir2)
{
	bool b = false;

	variant0(M-2);

	switch (dir1)
	{
	case 1:
		b = prep_1();
		break;

	case 2:
		b = prep_2();
		break;

	case 3:
		b = prep_3();
		break;

	case 4:
		b = prep_4();
		break;
	}

	if (b)
	{
		switch (dir2)
		{
		case 1:
			return prep_1();

		case 2:
			return prep_2();

		case 3:
			return prep_3();

		case 4:
			return prep_4();
		}
	}

	return false;
}

void variant00(int m)
{
	int y, x;

	memset(t, '.', sizeof(t));

	for (x = 0; x < C && m > 0; x++)
	{
		for (y = 0; y < R && m > 0; y++)
		{
			t[y][x] = '*';
			m--;
		}
	}
}

bool variant01(int dir)
{
	variant00(M-1);

	switch (dir)
	{
	case 1:
		return prep_1();

	case 2:
		return prep_2();

	case 3:
		return prep_3();

	case 4:
		return prep_4();
	}

	return false;
}

bool variant02(int dir1, int dir2)
{
	bool b = false;

	variant00(M-2);

	switch (dir1)
	{
	case 1:
		b = prep_1();
		break;

	case 2:
		b = prep_2();
		break;

	case 3:
		b = prep_3();
		break;

	case 4:
		b = prep_4();
		break;
	}

	if (b)
	{
		switch (dir2)
		{
		case 1:
			return prep_1();

		case 2:
			return prep_2();

		case 3:
			return prep_3();

		case 4:
			return prep_4();
		}
	}

	return false;
}

bool check(void)
{
	int i, j;
	bool b = true;

	for (i = 0; i < R && b; i++)
	{
		for (j = 0; j < C && b; j++)
		{
			if (t[i][j] == '.')
			{
				memcpy(t2, t, sizeof(t2));

				revealed = 0;
				rec(i, j);

				if ((R * C) - M == revealed)
				{
					t[i][j] = 'c';
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	int T, test, i, j, k, v;
	bool b;

	R = 5; C = 10;
	rec(2, 2);

	scanf("%d", &T);
	for (test = 1; test <= T; test++)
	{
		scanf("%d", &R);
		scanf("%d", &C);
		scanf("%d", &M);

		b = false;
		memset(t, '*', sizeof(t));

		v = (R*C) - M;
		for (i = 2; i <= v / 2 && !b; i++)
		{
			if (v % i == 0)
			{
				if (i <= R && v / i <= C)
				{
					for (j = 0; j < i; j++)
					{
						for (k = 0; k < v / i; k++)
						{
							t[j][k] = '.';
						}
					}

					t[0][0] = 'c';
					b = true;
				}
				else if (v / i <= R && i <= C)
				{
					for (j = 0; j < v / i; j++)
					{
						for (k = 0; k < i; k++)
						{
							t[j][k] = '.';
						}
					}

					t[0][0] = 'c';
					b = true;
				}
			}
		}

		if (!b)
		{
			variant0(M);

			memcpy(t2, t, sizeof(t2));
			b = check();

			for (i = 1; i <= 4 && !b; i++)
			{
				if (variant1(i))
				{
					memcpy(t2, t, sizeof(t2));
					b = check();
				}
			}
		}

		if (!b)
		{
			for (i = 1; i <= 4 && !b; i++)
			{
				for (j = 1; j <= 4 && !b; j++)
				{
					if (variant2(i, j))
					{
						memcpy(t2, t, sizeof(t2));
						b = check();
					}
				}
			}
		}

		if (!b)
		{
			variant00(M);
			memcpy(t2, t, sizeof(t2));
			b = check();
		}

		if (!b)
		{
			for (i = 1; i <= 4 && !b; i++)
			{
				if (variant01(i))
				{
					memcpy(t2, t, sizeof(t2));
					b = check();
				}
			}
		}

		if (!b)
		{
			for (i = 1; i <= 4 && !b; i++)
			{
				for (j = 1; j <= 4 && !b; j++)
				{
					if (variant02(i, j))
					{
						memcpy(t2, t, sizeof(t2));
						b = check();
					}
				}
			}
		}

		if (!b)
		{
			printf("Case #%d:\nImpossible\n", test);
		}
		else
		{
			printf("Case #%d:\n", test);
			for (i = 0; i < R; i++)
			{
				for (j = 0; j < C; j++)
				{
					printf("%c", t[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
