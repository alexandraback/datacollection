#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

int64_t ans = 0;

void dfs(std::multiset<int64_t> &q, int h = 0)
{
	int64_t mx = *q.rbegin();
	ans = min(ans, mx + h);
	if (mx < 1)
		return;
	q.erase(--q.end());
	for (int64_t i = 2; i <= mx - i; ++i)
	{
		q.insert(i);
		q.insert(mx - i);
		dfs(q, h + 1);
		q.erase(q.find(i));
		q.erase(q.find(mx-i));
	}
	q.insert(mx);
}

void solve(int test)
{
	int d;
	cin >> d;
	vector<int64_t> v(d);
	for (int i = 0; i < d; ++i)
	{
		cin >> v[i];
	}
	ans = 0;
	multiset<int64_t> q;
	for (int i = 0; i < d; ++i)
	{
		ans = max(ans, v[i]);
		q.insert(v[i]);
	}
	dfs(q, 0);
	cout << "Case #" << test << ": " << ans << endl;
}

int main()
{
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