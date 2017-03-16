#define _SCL_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

const int MAX_N = 1 << 10;

int n;
int bff[MAX_N];
int ans;
bool in_circle[MAX_N];

void find_circle()
{
	int visited[MAX_N];
	std::fill(visited, visited + n, -1);
	std::fill(in_circle, in_circle + n, false);
	for (int start = 0; start < n; ++start)
	{
		int entry = -1;
		for (int i = start; ; i = bff[i])
		{
			//printf("i=%d\n", i + 1);
			if (visited[i] != -1)
			{
				entry = i;
				break;
			}
			visited[i] = start;
		}
		if (visited[entry] != start) continue;
		int size = 0;
		for (int i = entry; ; )
		{
			in_circle[i] = true;
			++size;
			i = bff[i];
			if (i == entry) break;
		}
		if (ans < size) ans = size;
	}
}

int parent[MAX_N];

int dfs(int x)
{
	if (parent[x] == x) return x;
	int y = dfs(bff[x]);
	parent[x] = y;
	return y;
}

int solve()
{
	ans = 0;
	find_circle();
	for (int i = 0; i < n; ++i)
	{
		parent[i] = in_circle[i] ? i : -1;
	}
	for (int i = 0; i < n; ++i)
	{
		parent[i] = dfs(i);
	}
	for (int i = 0; i < n; ++i)
	{
		int x = parent[i];
		if (bff[bff[x]] != x) continue;
		bool used[MAX_N] = {};
		int size1 = 0;
		for (int j = i; j != x; j = bff[j])
		{
			++size1;
			used[j] = true;
		}
		ans = std::max(ans, size1 + 2);
		//printf("i = %d, size1 = %d, x = %d\n", i + 1, size1, x + 1);
		for (int k = 0; k < n; ++k)
		{
			if (parent[k] != bff[x]) continue;
			int size2 = 0;
			for (int j = k; j != bff[x]; j = bff[j])
			{
				++size2;
				if (used[j])
				{
					size2 = -1;
					break;
				}
			}
			//printf("  k = %d, size 2 = %d\n", k + 1, size2);
			if (size2 < 0) continue;
			ans = std::max(ans, size1 + size2 + 2);
		}
	}
	return ans;
}

int brute()
{
	std::vector<int> pos;
	for (int i = 0; i < n; ++i) pos.push_back(i);
	std::vector<int> init = pos;
	int ans = 1;
	while (true)
	{
		int i = 1;
		for (; i < n; ++i)
		{
			if ((bff[pos[0]] == pos[1] || bff[pos[0]] == pos[i]) && (bff[pos[i]] == pos[i - 1] || bff[pos[i]] == pos[0]))
			{
				if (ans < i + 1 && i + 1 == 4)
				{
					//for (int j = 0; j <= i; ++j)
					//{
					//	printf(" %d", pos[j] + 1);
					//}
					//puts("");
				}
				ans = std::max(ans, i + 1);
			}
			if (bff[pos[i]] != pos[i - 1] && (i < n - 1 && bff[pos[i]] != pos[i + 1])) break;
		}
		std::next_permutation(pos.begin(), pos.end());
		if (init == pos) break;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &bff[i]);
			--bff[i];
		}
		int ans = brute();
		printf("Case #%d: %d\n", cs, ans);
	}
	return 0;
}