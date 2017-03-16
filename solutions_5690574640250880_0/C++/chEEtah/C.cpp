#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
int n, m, mines;

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d:\n", tt);
		
		scanf("%d %d %d", &n, &m, &mines);

		if (!mines)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if (!i && !j) putchar('c'); else putchar('.');
				}
				puts("");
			}
			continue;
		}

		if (mines == n * m - 1)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if (!i && !j) putchar('c'); else putchar('*');
				}
				puts("");
			}
			continue;
		}

		if (n == 1)
		{
			for(int j = 0; j < m; j++)
			{
				if (!j) putchar('c');
				else 
					if (j < m - mines) putchar('.');
				else
					putchar('*');
			}
			puts("");
			continue;
		}	

		if (m == 1)
		{
			for(int j = 0; j < n; j++)
			{
				if (!j) puts("c");
				else 
					if (j < n - mines) puts(".");
				else
					puts("*");
			}
			continue;
		}

		// n, m >= 2, mines != 0, mines != n * m - 1

		bool ok = false;
		for(int A = 2; A <= n && !ok; A++)
			for(int B = 2; B <= m && !ok; B++)
			{
				if (A * B + mines < n * m) continue; // not enough emptiness
				int empty = 2 * (A + B) - 4;
				int rest = n * m - mines - empty;
				if (rest < 0) continue; // not enough mines

				// success!

				for(int i = 0; i < n; i++)
				{
					for(int j = 0; j < m; j++)
					{
						if (!i && !j) putchar('c');
						else
							if (i < 2 && j < B) putchar('.');
						else
							if (j < 2 && i < A) putchar('.');
						else
							if (rest && i < A && j < B)
							{
								rest--;
								putchar('.');
							}
						else
							putchar('*');
					}
					puts("");
				}
				ok = true;
			}

		if (!ok) puts("Impossible");
	}
	return 0;
}