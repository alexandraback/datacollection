#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int B;
		unsigned long long M;
		cin >> B >> M;

		cout << "Case #" << t << ": ";
		auto x = 1llu << (B - 2);
		if (x < M)
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;

		vector<vector<int>> v(B, vector<int>(B));

		for (unsigned long long i = 0llu; i < M; i++)
		{
			int k = 0;
			for (auto j = 0; j < B - 2; j++)
			{
				if ((1llu << j) & i)
				{
					v[k][j + 1] = 1;
					k = j + 1;
				}
			}
			v[k][B - 1] = 1;
		}

		for (int i = 0; i < B; i++)
		{
			for (int j = 0; j < B; j++)
			{
				cout << v[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}