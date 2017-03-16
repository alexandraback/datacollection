//Andrew Yang
#define _CRT_SECURE_NO_DEPRECATE
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
vector<pair<string, string>> v;
vector<pair<string, string>> order;
bool used[1001];
bool equals(string a, string b)
{
	if (a.length() != b.length())
	{
		return false;
	}
	FOR(i, 0, a.length())
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}
int go()
{
	FOR(i, 0, v.size())
	{
		used[i] = false;
	}
	RFOR(i, v.size() - 1, -1)
	{
		bool match1 = false;
		bool match2 = false;
		FOR(j, 0, v.size())
		{
			if (i == j)
			{
				continue;
			}
			if (equals(v[j].first, v[i].first))
			{
				match1 = true;
			}
			if (equals(v[j].second, v[i].second))
			{
				match2 = true;
			}
		}
		if (!match1 || !match2)
		{
			used[i] = true;
		}
	}
	RFOR(i, v.size() - 1, -1)
	{
		if (used[i])
		{
			order.push_back(v[i]);
			v.erase(v.begin() + i);
		}
	}
	bool done = false;
	int ans = 0;
	FOR(i, 0, v.size())
	{
		bool match1 = false;
		bool match2 = false;
		FOR(j, 0, order.size())
		{
			if (equals(v[j].first, v[i].first))
			{
				match1 = true;
			}
			if (equals(v[j].second, v[i].second))
			{
				match2 = true;
			}
		}
		if (match1 && match2)
		{
			order.push_back(v[i]);
			v.erase(v.begin() + i);
			i--;
			ans++;
		}
	}
	return ans;
}

int main(void)
{
	freopen("technobabble.in", "r", stdin);
	freopen("technobabble.out", "w", stdout);
	int sets;
	cin >> sets;
	FOR(set, 1, sets + 1)
	{
		int n;
		cin >> n;
		v.clear();
		FOR(i, 0, n)
		{
			string a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}
		order.clear();
		int ans = 0;
		int x = go();
		while (x > 0)
		{
			ans += x;
			x = go();
		}
		ans += max((int)(v.size() - 2), 0);
		/*int best = 0;
		int iter = 1;
		FOR(i, 1, v.size() + 1)
		{
			iter *= i;
		}
		FOR(x, 0, iter)
		{
			std::next_permutation(v.begin(), v.end());
			int ans = 0;
			FOR(i, 0, v.size())
			{
				bool match1 = false;
				bool match2 = false;
				FOR(j, 0, i)
				{
					if (equals(v[j].first, v[i].first))
					{
						match1 = true;
					}
					if (equals(v[j].second, v[i].second))
					{
						match2 = true;
					}
				}
				if (match1 && match2)
				{
					ans++;
				}
			}
			best = max(best, ans);
		}
		ans += best;*/
		cout << "Case #" << set << ": " << ans << endl;
	}
}