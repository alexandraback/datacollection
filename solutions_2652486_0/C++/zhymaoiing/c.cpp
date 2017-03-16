#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tCase = 1; tCase <= T; ++tCase)
	{
		printf("Case #%d: \n", tCase);

		int R, N, M, K;
		cin >> R >> N >> M >> K;

		vector< pair< int, set<int> > > valid;
		for (int f = 222; f <= 555; ++f)
		{
			bool fail = false;
			int a[3];
			for (int i = 0, d = f; i < 3; i++)
			{
				int x = d % 10;

				if (x < 2 || x > M)
				{
					fail = true;
					break;
				}

				a[i] = x;

				d /= 10;
			}

			if (fail) continue;

			set<int> st;

			for (int i = 0; i < 8; ++i)
			{
				int c = 1;
				for (int j = 0; j < 3; ++j)
					if (i & (1 << j))
						c *= a[j];
				st.insert(c);
			}

			valid.push_back(make_pair(f, st));
		}

		for (int i = 0; i < R; ++i)
		{
			int a[8];
			for (int j = 0; j < K; ++j)
				cin >> a[j];

			vector<int> optional;

			for (pair< int, set<int> > p : valid)
			{
				set<int>& st = p.second;
				bool fail = false;
				for (int j = 0; j < K; ++j)
				{
					if (st.find(a[j]) == st.end())
					{
						fail = true;
						break;
					}
				}

				if (fail) continue;
				optional.push_back(p.first);
			}

			cout << optional[rand() % optional.size()] << endl;
		}
	}

	return 0;
}
