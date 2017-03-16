//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int c, d, v;
int ans;
set<int> coins;
bool covered[100];
void dfs()
{
	if (coins.size() >= ans)
	{
		return;
	}
	bool done = true;
	FOR(i, 1, v + 1)
	{
		if (!covered[i])
		{
			done = false;
			break;
		}
	}
	if (done)
	{
		ans = min(ans, (int)coins.size());
		return;
	}
	FOR(i, 1, v + 1)
	{
		if (coins.find(i) == coins.end())
		{
			vector<int> changed;
			RFOR(j, v, 0)
			{
				if (j - i >= 0)
				{
					if (covered[j - i] && !covered[j])
					{
						covered[j] = true;
						changed.push_back(j);
					}
				}
				else
				{
					break;
				}
			}
			if (changed.size() != 0)
			{
				coins.insert(i);
				dfs();
				coins.erase(coins.find(i));
			}
			for(int n : changed)
			{
				covered[n] = false;
			}
		}
	}
}
int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(s, 1, sets + 1)
	{
		coins.clear();
		scanf("%d%d%d", &c, &d, &v);
		memset(covered, 0, sizeof(covered));
		covered[0] = true;
		FOR(i, 0, d)
		{
			int coin;
			scanf("%d", &coin);
			coins.insert(coin);
			RFOR(j, v, 0)
			{
				if (j - coin >= 0)
				{
					if (covered[j - coin])
					{
						covered[j] = true;
					}
				}
				else
				{
					break;
				}
			}
		}
		ans = v;
		dfs();
		cout << "Case #" << s << ": " << ans - d << endl;
	}
}