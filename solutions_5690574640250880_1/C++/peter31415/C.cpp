#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

void printArray(char** a, int r, int c);
void solve(int caseN);

void solve(int caseN)
{
	int r;
	int c;
	int m;

	scanf("%d %d %d", &r, &c, &m);
	char** ans = new char*[r];
	for(int i = 0; i < r; i++){
		ans[i] = new char[c];
	}

	for(int i = 0; i < r; i++)
		for(int j =0; j < c; j++)
			ans[i][j] = '*';

	printf("Case #%d:\n", caseN);
	int e = r*c-m;
	if (e == 1)
	{
		ans[0][0] = 'c';		
		printArray(ans, r, c);
		return;
	} 		
	else
	{
		for(int dr = 1; dr <= r; dr++)
		{
			int dc = ceil(((double)e) / ((double)dr));
			if (dc > c)
				continue;

			int ml = dc*dr - e;
			int nec = 2 * dr + 2 * dc - 4;

			if (ml > max(dc*dr - nec, 0))
			{
				continue;
			}

			if ((dr == 1 && r > 1) || (dc == 1) && c > 1)
			{
				continue;
			}

			// possible
			for(int i = 0; i < dr; i++)
			{
				for(int j = 0; j < dc; j++)
				{
					ans[i][j] = '.';
				}
			}

			if (ml > 0)
			{
				for(int i = dr - 1; i > 1; i--)
				{
					for(int j = dc - 1; j > 1; j--)
					{
						ans[i][j] = '*';
						if ((--ml) == 0)
							break;
					}

					if (ml == 0)
						break;
				}
			}

			ans[0][0] = 'c';
			printArray(ans, r, c);
			return;
		}

		printf("Impossible\n");
	}
}

void printArray(char** a, int r, int c)
{
	for(int i = 0; i < r; i++)
	{
		for(int j =0; j < c; j++)
		{
			printf("%c", a[i][j]);
		}

		printf("\n");
	}
}

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);

	for(int i = 1;i <= t; i++)
	{
		solve(i);
	}
}