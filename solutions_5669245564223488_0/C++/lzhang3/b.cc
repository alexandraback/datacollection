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

int check(const vector<int> &p)
{
	int c[26]; memset(c, 0, sizeof c);
	char cur = a[p[0]].front(); c[cur-'a'] = 1;
	for (int i = 0; i < n; ++i)
	{
		string s = a[p[i]];
		for (int j = 0; j < s.size(); ++j)
		{
			if (s[j] != cur) {
				if (c[s[j]-'a']) return 0;
				c[s[j]-'a'] = 1;
				cur = s[j];
			}
		}
	}
	return 1;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> p(n);
	for (int i = 0; i < n; ++i)
		p[i] = i;
	long long sum = 0;
	while (true)
	{
		sum += check(p);
		if (!next_permutation(begin(p), end(p)))
			break;
	}
	cout << sum << endl;
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