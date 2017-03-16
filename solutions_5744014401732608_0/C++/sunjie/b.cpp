#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int mp[55][55];
long long bit[55];

void pre()
{
	bit[0] = 1ll;
	for (int i = 1; i < 50; ++i)
	{
		bit[i] = bit[i - 1] * 2ll;
	}
}




int main()
{
	int T;
	cin >> T;
	int cas = 0;
	pre();
	while (T--)
	{
		cout << "Case #" << ++cas << ": ";
		int B;
		long long M;
		cin >> B >> M;
		memset(mp, 0, sizeof(mp));
		if (M > bit[B - 2])
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << "POSSIBLE\n";
		if (M == bit[B - 2])
		{
			for (int i = 1; i < B; ++i)
			{
				for (int j = i + 1; j <= B; ++j)
				{
					mp[i][j] = 1;
				}
			}
			for (int i = 1; i <= B; ++i)
			{
				for (int j = 1; j <= B; ++j)
				{
					cout << mp[i][j];
				}
				cout << endl;
			}
			continue;
		}
		vector<int> mm;
		while (M)
		{
			mm.push_back(M % 2);
			M /= 2ll;
		}
		int size = mm.size();
		for (int i = 2; i < B; ++i)
		{
			for (int j = i + 1; j <= B; ++j)
			{
				mp[i][j] = 1;
			}
		}

		for (int i = 0; i < size; ++i)
		{
			if (mm[i])
			{
				mp[1][B - 1 - i] = 1;
			}
		}
		for (int i = 1; i <= B; ++i)
		{
			for (int j = 1; j <= B; ++j)
			{
				cout << mp[i][j];
			}
			cout << endl;
		}

	}



	return 0;
}