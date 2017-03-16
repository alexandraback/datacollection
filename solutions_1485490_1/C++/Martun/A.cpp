#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

struct timestamp
{
	long long time_period;
	long long num;
};

long long n, m;
timestamp boxes[110];
timestamp toys[110];
long long d[110][110];

void read()
{
	long long i, j;
	cin >> n >> m;
	
	for (i = 1; i <= n; ++i)
	{
		cin >> boxes[i].time_period;
		cin >> boxes[i].num;
	}
	
	for (j = 1; j <= m; ++j)
	{
		cin >> toys[j].time_period;
		cin >> toys[j].num;
	}
}

void solve()
{
	long long i,j, i1, j1;
	
	memset(d,0,sizeof(d));

	long long tmp_max;
	long long bc;
	long long tc;

	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
		{
			// If they match
			if (boxes[i].num == toys[j].num)
			{
				tmp_max = -1;
				bc = 0;
				for (i1 = i - 1; i1 >= 0; --i1)
				{
					if (boxes[i1 + 1].num == boxes[i].num)
					{
						bc += boxes[i1 + 1].time_period;
					}

					tc = 0;
					for (j1 = j - 1; j1 >= 0; --j1)
					{
						if (toys[j1 + 1].num == toys[j].num)
						{
							tc += toys[j1 + 1].time_period;
						}

						if (tmp_max < min(tc, bc) + d[i1][j1])
						{
							tmp_max = min(tc, bc) + d[i1][j1];
						}
					}
				}
				d[i][j] = tmp_max;
			}
			else
			{
				d[i][j] = max(d[i-1][j], d[i][j-1]);
			}
		}
	}

	std::cout << d[n][m] << "\n";
} 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long t;
	cin >> t;
	long long i;
	for (i = 1; i <= t; ++i)
	{
		read();
		std::cout << "Case #" << i << ": ";
		solve();
	}
}