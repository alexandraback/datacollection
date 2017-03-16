#define _SCL_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

const int MAX_N = 64;

int n;
int lists[MAX_N * 2][MAX_N];
int sorted[MAX_N * 2][MAX_N];

int sb_sort()
{
	bool used[MAX_N * 2] = {};
	int missing = -1;
	for (int i = 0; i < n; ++i)
	{
		std::vector<std::pair<int, int>> pairs;
		for (int j = 0; j < n * 2 - 1; ++j)
		{
			if (used[j]) continue;
			pairs.push_back(std::make_pair(lists[j][i], j));
		}
		std::sort(pairs.begin(), pairs.end());
		int k = pairs[0].second;
		std::copy(lists[k], lists[k] + n, sorted[i * 2]);
		used[k] = true;
		if (pairs.size() >= 2 && pairs[0].first == pairs[1].first)
		{
			k = pairs[1].second;
			std::copy(lists[k], lists[k] + n, sorted[i * 2 + 1]);
			used[k] = true;
		}
		else
		{
			missing = i;
		}
	}
	return missing;
}

void solve()
{
	int missing = sb_sort();
	std::map<int, int> count;
	for (int i = 0; i < n * 2; ++i)
	{
		if (i == missing * 2 + 1) continue;
		++count[sorted[i][missing]];
	}
	++count[sorted[missing * 2][missing]];
	for (int i = 0; i < n; ++i)
	{
		--count[sorted[missing * 2][i]];
	}
	for (auto pair : count)
	{
		for (int i = 0; i < pair.second; ++i)
		{
			printf(" %d", pair.first);
		}
	}
	puts("");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		scanf("%d", &n);
		for (int i = 0; i < n * 2 - 1; ++i)
		{
			for (int j = 0; j < n; ++j) scanf("%d", &lists[i][j]);
		}
		printf("Case #%d:", cs);
		solve();
	}
	return 0;
}