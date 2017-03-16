#include <cstdio>
#include <cassert>

char in[4][5];

int full()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (in[i][j] == '.') return 0;
	return 4;
}

int check(int i, int j, int di, int dj)
{
	bool x = 1, o = 1;
	while (i >= 0 && i < 4 && j >= 0 && j < 4)
	{
		if (in[i][j] != 'X' && in[i][j] != 'T') x = 0;
		if (in[i][j] != 'O' && in[i][j] != 'T') o = 0;
		i += di;
		j += dj;
	}
	if (!x && !o) return 0;
	if (x) return 1;
	return 2;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int q = 1; q <= t; ++q)
	{
		printf("Case #%d: ", q);
		for (int i = 0; i < 4; ++i)
			scanf("%s", in[i]);
		int a = 0;
		for (int i = 0; i < 4; ++i)
		{
			a |= check(i, 0, 0, 1);
			a |= check(0, i, 1, 0);
		}
		a |= check(0, 0, 1, 1);
		a |= check(3, 0, -1, 1);
		a |= full();
		assert(!(a&1) || !(a&2));
		if (a&1) printf("X won\n");
		else if (a&2) printf("O won\n");
		else if (a) printf("Draw\n");
		else printf("Game has not completed\n");
	}
}

