#include <iostream>
#include <fstream>
#include <cmath>

#define cin in
#define cout out

using namespace std;

ifstream in("in");
ofstream out("out");

int main()
{
	int T, b;
	long long m;

	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		cin >> b >> m;

		if (m > pow(2ll, b - 2))
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}

		cout << "POSSIBLE\n";

		long long ways[55];
		bool grid[55][55] = {0};

		ways[b] = 1;
		long long ans = 1;

		for (int i = b - 1; i >= 1; --i)
		{
			ways[i] = ways[i + 1];
			grid[i][i + 1] = 1;

			for (int j = i + 2; j <= b; ++j)
			{
				if (ways[j] <= m - ans)
				{
					ways[i] += ways[j];
					ans += ways[j];
					grid[i][j] = 1;
				}
			}

			if (ans == m)
			{
				if (i != 1)
					grid[1][i] = 1;

				break;
			}
		}

		for (int i = 1; i <= b; ++i)
		{
			for (int j = 1; j <= b; ++j)
			{
				cout << grid[i][j];
			}

			cout << endl;
		}
	}
}