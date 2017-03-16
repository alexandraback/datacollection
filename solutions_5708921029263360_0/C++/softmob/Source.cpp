#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;

void solve(int num_test)
{
	int j, p, s, k;
	cin >> j >> p >> s >> k;
	int mx = j * p * s;
	map<pair<int, int>, int> qa, qb, qc;
	vector<pair<int,  pair<int, int> > > ans;
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < mx; ++i)
	{
		int a = x;
		int b = y;
		int c = z;

		++z;
		if (z == s)
		{
			z = 0;
			++y;
		}

		if (y == p)
		{
			++x;
			y = 0;
			z = 0;
		}
		
		if (qa[{a, b}] >= k)
			continue;
		if (qb[{a, c}] >= k)
			continue; 
		if (qc[{b, c}] >= k)
			continue;

		ans.push_back({ a, {b, c} });

		++qa[{a, b}];
		++qb[{a, c}];
		++qc[{b, c}];
	}
	cout << "Case #" << num_test << ": " << ans.size() << endl;
	for (int u = 0; u < (int)ans.size(); ++u)
	{
		int a = ans[u].first;
		int b = ans[u].second.first;
		int c = ans[u].second.second;
		cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve(i+1);
	}
	return 0;
}