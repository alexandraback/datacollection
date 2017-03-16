#include <cassert>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int K = 256;

struct Chest
{
	Chest(int o)
		: open(o)
	{
		memset(keys, 0, sizeof(keys));
	}

	int open;
	int keys[K];
};


const int N = 1 << 21;
bool vis[N];
bool dp[N];
int next[N];


bool f(const vector<Chest> & chests, const vector<int> & keys, const int mask)
{
	if(mask == 0)
		return true;

	if(vis[mask])
		return dp[mask];

	vis[mask] = true;
	dp[mask] = false;
	next[mask] = -1;

	for(int ci = 0; ci < chests.size(); ci++)
	{
		if((mask & (1 << ci)) == 0)
			continue;

		const Chest & c = chests[ci];

		int s = keys[c.open];
		for(int i = 0; i < chests.size(); i++)
			if((mask & (1 << i)) == 0)
			{
				s += chests[i].keys[c.open];
				if(chests[i].open == c.open)
					s--;
			}

		if(s < 1)
			continue;

		const int nmask = mask & (~(1 << ci));
		if(f(chests, keys, nmask))
		{
			dp[mask] = true;
			next[mask] = ci;
			return true;
		}
	}

	return false;
}

void testCase()
{
	int n, k;
	scanf("%i %i", &k, &n);

	vector<int> keys(K, 0);
	for(int i = 0; i < k; i++)
	{
		int ki;
		scanf("%i", &ki);
		keys[ki]++;
	}

	vector<Chest> chests;
	for(int i = 0; i < n; i++)
	{
		int open, sz;
		scanf("%i %i", &open, &sz);

		Chest chest(open);

		for(int j = 0; j < sz; j++)
		{
			int ki;
			scanf("%i", &ki);
			chest.keys[ki]++;
		}

		chests.push_back(chest);
	}

	memset(vis, 0, sizeof(vis));
	memset(next, 0xFF, sizeof(next));

	int initial = (1 << chests.size()) - 1;
	if(f(chests, keys, initial))
	{
		while(initial != 0)
		{
			int x = next[initial];
			printf(" %i", x + 1);
			initial &= ~(1 << x);
		}
	}
	else
		printf(" IMPOSSIBLE");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t = 0;
	scanf("%i\n", &t);

	for(int tn = 1; tn <= t; tn++)
	{
		printf("Case #%i:", tn);
		testCase();
		printf("\n");
	}

	return 0;
}
