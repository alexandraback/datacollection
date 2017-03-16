#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		long long B, M;
		cin >> B >> M;

		ll totalWays = 0;
		ll ways[50] = {};
		int m[50][50] = {};

		totalWays = 1;
		ways[0] = 1;
		m[0][B - 1] = 1;

		for (int v = 1; v < B - 1; v++)
		{
			ll leftWays = M - totalWays;
			for (int prev_v = v - 1; prev_v >= 0; prev_v--)
			{
				if (leftWays - ways[prev_v] >= 0)
				{
					m[prev_v][v] = 1;
					ways[v] += ways[prev_v];
					leftWays -= ways[prev_v];
					totalWays += ways[prev_v];
				}
			}
			m[v][B - 1] = 1;
		}

		cout << "Case #" << t << ": ";
		if (totalWays != M)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			cout << "POSSIBLE\n";
			for (int r = 0; r < B; r++)
			{
				for (int c = 0; c < B; c++)
					cout << m[r][c];
				cout << endl;
			}
		}
	}
}