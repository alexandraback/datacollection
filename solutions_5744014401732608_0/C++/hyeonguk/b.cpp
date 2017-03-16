#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <cctype>
#include <functional>
#include <future>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

struct TestCase
{
	int b;
	LL m;
	
	bool fail = false;
	vector<vector<bool>> adj;
	vector<int> cnt;

	void input()
	{
		cin >> b >> m;
	}

	void process()
	{
		LL limit = 1;
		limit <<= (b - 2);

		if (limit < m)
		{
			fail = true;
			return;
		}

		adj = vector<vector<bool>>(b, vector<bool>(b));
		cnt.resize(b);
		cnt[0] = 1;

		for (int i = 0; i < b; i++)
		{
			for (int j = i + 1; j < b; j++)
			{
				adj[i][j] = true;
				cnt[j] += cnt[i];
			}
		}
		if (limit == m)
		{
			return;
		}

		adj[0][b - 1] = false;

		for (int i = 1; i < b; i++)
		{
			adj[i][b - 1] = false;
		}

		LL mask = 1;
		int k = 1;
		while (m > 0)
		{
			if (m & mask)
			{
				m -= mask;
				adj[k][b - 1] = true;
			}
			mask <<= 1;
			k++;
		}
	}
	void output()
	{
		if (fail)
		{
			cout << "IMPOSSIBLE";
			return;
		}
		cout << "POSSIBLE";
		for (int i = 0; i < b; i++)
		{
			printf("\n");
			for (int j = 0; j < b; j++)
			{
				printf("%d", !!adj[i][j]);
			}
		}
	}
};

int main()
{
	int t;
	cin >> t;

	vector<TestCase> tc(t);
	vector<future<void>> f;
	for (int i = 0; i < t; i++) tc[i].input();
	for (int i = 0; i < t; i++)
		f.push_back(async(launch::async,
			[&](int p){ tc[p].process(); }, i));
	for (int i = 0; i < t; i++) f[i].wait();
	for (int i = 0; i < t; i++)
	{
		f[i].wait();
		cout << "Case #" << i + 1 << ": ";
		tc[i].output();
		cout << endl;
	}
	return 0;
}
