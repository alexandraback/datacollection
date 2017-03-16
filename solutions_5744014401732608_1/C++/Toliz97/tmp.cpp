#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

vector<bool> bin(int a, int d)
{
	vector<bool> binary(d);
	int mask = 1;

	for (int i = 0; i < d; i++)
	{
		if ((mask&a) >= 1)	binary[i] = true;
		else				binary[i] = false;
		mask <<= 1;
	}

	return binary;
}

int main()
{
	int t, T;
	int i, j;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		int b, m; cin >> b >> m;

		cout << "Case #" << t << ": ";
		if (m > pow(2, b-2)) cout << "IMPOSSIBLE" << endl;
		else
		{
			cout << "POSSIBLE" << endl;

			vector<bool> M = bin(m-1, b - 2);

			/*for (i = 0; i < b; i++)
			{
				for (j = 0; j < b-1; j++)
				{
					if (j > i && M[j - 1]) cout << 1;
					else cout << 0;
				}
				if (i == 0) cout << 1;
				else if (i > 0 && i < b-1 && M[i-1]) cout << 1;
				else cout << 0;
				cout << endl;
			}*/
			int max = 0; for (i = 0; i < b - 2; i++) if (M[i]) max = i + 1;

			vector<vector<int>> table(b); for (i = 0; i < b; i++) table[i].resize(b);
			table[0][b - 1] = 1;
			table[b - 1][b - 1] = 0;
			for (i = 0; i < b; i++)
			{
				for (j = 0; j < b-1; j++)
				{
					if (i >= j)
						table[i][j] = 0;
					else if (j <= max)
						table[i][j] = 1;
					else
						table[i][j] = 0;
				}
				if (i > 0 && i < b - 1) table[i][b - 1] = M[i - 1];
			}

			for (i = 0; i < b; i++)
			{
				for (j = 0; j < b; j++)
					cout << table[i][j];
				cout << endl;
			}
		}
	}

	return 0;
}