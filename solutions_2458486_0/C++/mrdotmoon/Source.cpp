#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int N, K;
int keys[21][41], T[21];
map<int, int> regKey;

int ans[21];
bool visited[21];

int dp[1 << 20];

void addKey(map<int, int>& curK, int num)
{
	if (curK.find(num) == curK.end())
		curK[num] = 1;
	else
		curK[num]++;
}

bool delKey(map<int, int>& curK, int num)
{
	if (curK.find(num) == curK.end())
		return false;
	else if (curK[num] > 1)
		curK[num]--;
	else
		curK.erase(num);
	return true;
}

bool go(int mask, int cur)
{
	if (cur == N)
		return true;
	if (dp[mask] >= 0)
		return (bool)dp[mask];

	bool ret = false;
	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && regKey.find(T[i]) != regKey.end())
		{
			delKey(regKey, T[i]);
			for (int j = 0; j < keys[i][0]; j++)
				addKey(regKey, keys[i][j + 1]);
			visited[i] = true;
			ans[cur] = i;
			int can = (int)go(mask | (1 << i), cur + 1);
			if (can)
			{
				return dp[mask] = 1;
			}
			for (int j = 0; j < keys[i][0]; j++)
				delKey(regKey, keys[i][j + 1]);
			visited[i] = false;
			addKey(regKey, T[i]);
		}
	}
	dp[mask] = 0;
	return false;
}

void _main()
{
	scanf("%d%d", &K, &N);
	regKey.clear();

	for (int i = 0; i < K; i++)
	{
		int ki;
		scanf("%d", &ki);
		addKey(regKey, ki);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &T[i]);
		scanf("%d", &keys[i][0]);
		for (int j = 0; j < keys[i][0]; j++)
			scanf("%d", &keys[i][j + 1]);
		
	}

	memset(visited, 0, sizeof(visited));
	memset(dp, 0xff, sizeof(dp));
	bool hasAns = false;
	for (int i = 0; i < N; i++)
	{
		if (regKey.find(T[i]) != regKey.end())
		{
			delKey(regKey, T[i]);
			for (int j = 0; j < keys[i][0]; j++)
				addKey(regKey, keys[i][j + 1]);
			visited[i] = true;
			ans[0] = i;
			bool can = go(1 << i, 1);
			if (can)
			{
				hasAns = true;
				for (int j = 0; j < N - 1; j++)
					printf("%d ", ans[j] + 1);
				printf("%d\n", ans[N - 1] + 1);
				break;
			}
			for (int j = 0; j < keys[i][0]; j++)
				delKey(regKey, keys[i][j + 1]);
			visited[i] = false;
			addKey(regKey, T[i]);
		}
		if (hasAns)
			break;
	}
	if (!hasAns)
	{
		puts("IMPOSSIBLE");
	}
}


int main()
{
	freopen("D-small-attempt2.in", "r", stdin);
	freopen("D.out", "w", stdout);

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++)
	{
		printf("Case #%d: ", i);
		_main();
	}

}