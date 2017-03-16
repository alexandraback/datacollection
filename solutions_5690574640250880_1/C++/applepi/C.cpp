#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 55;

char mat[N][N];

int main ()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout); 
	int kase; scanf("%d", &kase);
	for (int _ = 1; _ <= kase; ++_)
	{
		int r, c, m; scanf("%d %d %d", &r, &c, &m);
		int d = r * c - m;
		bool swaped = false, ok;
		if (r < c)
		{
			swap(r, c);
			swaped = true;
		}
		if (c == 1)
		{
			ok = true;
			mat[0][0] = 'c';
			for (int i = 1; i < d; i++) mat[i][0] = '.';
			for (int i = d; i < r; i++) mat[i][0] = '*';
		}
		else if (c == 2)
		{
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++) mat[i][j] = '*';
			if (d == 1)
			{
				ok = true;
				mat[0][0] = 'c';
			}
			else if (d == 2 || d % 2 == 1)
			{
				ok = false;
			}
			else
			{
				// d >= 4 and d is even.
				ok = true;
				mat[0][0] = 'c', mat[0][1] = '.';
				int tt = d / 2;
				for (int i = 1; i < tt; i++) mat[i][0] = mat[i][1] = '.';
			}
		}
		else
		{
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++) mat[i][j] = '*';
			if (d == 1)
			{
				ok = true;
				mat[0][0] = 'c';
			}
			else if (d == 2 || d == 3 || d == 5 || d == 7)
			{
				ok = false;
			}
			else
			{
				ok = true;
				int tt = 2 * (r + c) - 4;
				if (d <= tt + 1)
				{
					if (d % 2 == 1) mat[2][2] = '.', --d;
					d -= 4;
					mat[0][0] = 'c'; mat[0][1] = mat[1][0] = mat[1][1] = '.';
					int rc = min(c - 2, d / 4);
					for (int i = 2; i < 2 + rc; i++)
						mat[i][0] = mat[i][1] = mat[0][i] = mat[1][i] = '.';
					d -= 4 * rc;
					int tr = d / 2;
					for (int i = 2 + rc; i < 2 + rc + tr; i++)
						mat[i][0] = mat[i][1] = '.'; 
				}
				else
				{
					d -= tt;
					for (int i = 0; i < r; i++) mat[i][0] = mat[i][1] = '.';
					for (int i = 0; i < c; i++) mat[0][i] = mat[1][i] = '.';
					mat[0][0] = 'c';
					for (int i = 2; d && i < r; i++)
						for (int j = 2; d && j < c; j++)
							mat[i][j] = '.', --d;
				}
			}
		}
		printf("Case #%d:\n", _);
		if (!ok) printf("Impossible\n");
		else
		{
			if (!swaped)
			{
				for (int i = 0; i < r; i++)
				{
					for (int j = 0; j < c; j++)
						printf("%c", mat[i][j]);
					printf("\n");
				}	
			}
			else
			{
				for (int i = 0; i < c; i++)
				{
					for (int j = 0; j < r; j++)
						printf("%c", mat[j][i]);
					printf("\n");
				}	
			}
		}
	}
	return 0;
}
