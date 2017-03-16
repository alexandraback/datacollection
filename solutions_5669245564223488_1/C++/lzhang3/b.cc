#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <climits>

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

string a[200];
int n;

int eq(const string &s)
{
	char c = s.front();
	for (int i = 1; i < s.size(); ++i)
		if (s[i] != c) return 0;
	return 1;
}

int e[26];
const int modu = 1000000007;

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	memset(e, 0, sizeof e);

	int val = 1;
	vector<int> z(n);

	for (int i = 0; i < n; ++i)
		if (eq(a[i])) {
			if (++e[a[i].front()-'a'] > 1)
				z[i] = 1;
			val = val * e[a[i].front()-'a'] % modu;

		}

	vector<vector<int> > e(n);
	vector<vector<int> > in(n);
	for (int i = 0; i < n; ++i) {
		if (z[i]) continue;
		for (int j = i + 1; j < n; ++j) {
			if (z[j]) continue;
			if (a[i].back() == a[j].front())
			{
				e[i].push_back(j);
				in[j].push_back(i);
			}
			if (a[j].back() == a[i].front())
				e[j].push_back(i);
				in[i].push_back(j);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (e[i].size() > 1 && in[i].size()) {
			cout << 0 << endl;
			return;
		}
	}



	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < e[i].size(); ++j)
	// 		cout << e[i][j] << " ";
	// 	cout << endl;
	// }
	// vector<int> f(n);
	// fill(begin(f), end(f), -1);

	// int cnt = 0;
	// vector<int> v(n);
	// for (int i = 0; i < n; ++i)
	// {
	// 	if (v[i] || z[i]) continue;
	// 	++cnt;
	// 	val = val * cnt % modu;
	// 	int cur = i;
	// 	while (true) {
	// 		v[cur] = 1;
	// 		if (e[cur].size())
	// 			cur = e[cur].front();
	// 		else 
	// 			break;
	// 	}
	// }

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (z[i] == 0) cnt++;
	for (int i = 0; i < n; ++i)
		cnt -= e[i].size();

	for (int i = 1; i <= cnt; ++i)
		val = val * i % modu;

	vector<int> middle(26), ending(26);

	for (int i = 0; i < n; ++i)
	{
		++ending[a[i].front()-'a'];
		++ending[a[i].back()-'a'];
	}


	for (int i = 0; i < n; ++i)
	{
		if (z[i] || a[i].size() <= 2) 
			continue;
		int l = 1, r = a[i].size() - 2;
		for (; l < a[i].size(); ++l)
			if (a[i][l] != a[i][l-1]) break;
		for (; r >= 0; --r)
			if (a[i][r] != a[i][r+1]) break;
		//cout << l << " " << r << endl;
		if (l <= r) {
			char cur = -1;
			for (int j = l; j <= r; ++j) {
				if (a[i][j] != cur) {
					if (middle[a[i][j]-'a'] || ending[a[i][j]-'a']) {
						cout << 0 << endl; return;
					}
					cur = a[i][j];
				}
				++middle[a[i][j]-'a'];
			}		
		}
	}
	cout << val << endl;
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}