#include <iostream>
#include <cassert>

using namespace std;

int t;
char a[10][10];
int os, xs, ts;
int cases;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		os = xs = ts = 0;
		for (int i = 0; i < 4; ++i)
			scanf("%s", a[i]);

		bool owin = false, xwin = false;
		for (int i = 0; i < 4; ++i)
		{
			int o, x, t;
			o = 0, x = 0, t = 0;
			for (int j = 0; j < 4; ++j)
			{
				if (a[i][j] == 'O') o++;
				if (a[i][j] == 'X') x++;
				if (a[i][j] == 'T') t++;
			}

			if (o + t == 4) owin = true;
			if (x + t == 4) xwin = true;

			os += o; xs += x; ts += t;

			o = 0, x = 0, t = 0;
			for (int j = 0; j < 4; ++j)
			{
				if (a[j][i] == 'O') o++;
				if (a[j][i] == 'X') x++;
				if (a[j][i] == 'T') t++;
			}

			if (o + t == 4) owin = true;
			if (x + t == 4) xwin = true;
		}

		int o, x, t;
		o = 0, x = 0, t = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (a[i][i] == 'O') o++;
			if (a[i][i] == 'X') x++;
			if (a[i][i] == 'T') t++;
		}
		if (o + t == 4) owin = true;
		if (x + t == 4) xwin = true;

		o = 0, x = 0, t = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (a[i][3 - i] == 'O') o++;
			if (a[i][3 - i] == 'X') x++;
			if (a[i][3 - i] == 'T') t++;
		}
		if (o + t == 4) owin = true;
		if (x + t == 4) xwin = true;

		printf("Case #%d: ", ++cases);

		if (xwin && owin)
		{
			assert(false);
		}
		else if (xwin)
		{
			printf("X won\n");
		}
		else if (owin)
		{
			printf("O won\n");
		}
		else if (os + xs + ts == 16)
		{
			printf("Draw\n");
		}
		else
		{
			printf("Game has not completed\n");
		}
	}
}