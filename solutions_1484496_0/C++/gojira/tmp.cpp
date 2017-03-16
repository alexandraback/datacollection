#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 2000001;
vector<int> mask[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, n, t, i, j, S, s[20];

	cin >> T;
	for(t = 1; t <= T; t++)
	{
		cin >> n;
		for(i = 0; i < n; i++)
			cin >> s[i];
		sort(s, s + n);
		for(i = 0; i < N; i++)
			mask[i].clear();

		printf("Case #%d:\n", t);
		for(i = 1; i < (1 << n); i++)
		{
			S = 0;
			vector<int> num;
			for(j = 0; j < n; j++)
				if (i & (1 << j))
				{
					S += s[j];
					num.push_back(s[j]);
				}

			if (mask[S] != num && !mask[S].empty())
			{
				for(j = 0; j < num.size(); j++)
					printf("%d ", num[j]);
				puts("");
				for(j = 0; j < mask[S].size(); j++)
					printf("%d ", mask[S][j]);
				puts("");
				break;
			} else
				mask[S] = num;
		}

		if (i == (1 << n))
			puts("Impossible");
	}

	return 0;
}