#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define mp(a,b) make_pair(a,b)

using namespace std;

char mas[55][55];
bool used[55][55];

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		int n, m, bomb, i, j;

		scanf("%d %d %d", &n, &m, &bomb);
		memset(mas, 0, sizeof(mas));
		for (i = 1; i <= n; i++)for (j = 1; j <= m; j++)mas[i][j] = 0;

		int rest = bomb;
		int y = 1, x = 1;
		while (rest)
		{
			if (m - x <= n - y)
			{
				if (rest >= m - x + 1 || rest < m - x || m - x == 1)
				{
					for (i = x; i <= m && rest; i++, rest--)
					{
						mas[y][i] = 1;
					}
				}
				else
				{
					for (i = x; i < m - 1 && rest; i++, rest--)
					{
						mas[y][i] = 1;
					}
				}
				y++;
			}
			else
			{
				if (rest >= n - y + 1 || rest < n - y || n - y == 1)
				{
					for (i = y; i <= n && rest; i++, rest--)
					{
						mas[i][x] = 1;
					}
				}
				else
				{
					for (i = y; i < n - 1 && rest; i++, rest--)
					{
						mas[i][x] = 1;
					}
				}
				x++;
			}
		}

		memset(used, 0, sizeof(used));
		int counter = 0;
		queue<pair<int, int> > q;
		q.push(mp(n, m));
		used[n][m] = true;
		while (!q.empty())
		{
			pair<int,int> p = q.front();
			q.pop();
			y = p.first;
			x = p.second;
			if (mas[y][x] || !x || !y || x>m || y>n) continue;
			counter++;

			int cnt = 0;
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if ((i || j) && mas[y + i][x + j]) cnt++;
				}
			}
			
			if (!cnt)
			{
				for (i = -1; i <= 1; i++)
				{
					for (j = -1; j <= 1; j++)
					{
						if ((i || j) && !used[y + i][x + j])
						{
							q.push(mp(y + i, x + j));
							used[y + i][x + j] = true;
						}
					}
				}
			}
		}

		printf("Case #%d:\n", step);
		if (counter == n*m - bomb)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= m; j++)
				{
					if (i == n && j == m) printf("c");
					else printf(mas[i][j] ? "*" : ".");
				}
				printf("\n");
			}
		}
		else printf("Impossible\n");

	}
	return 0;
}