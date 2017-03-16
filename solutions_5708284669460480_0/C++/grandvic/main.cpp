#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

int getCount(const string & one, const string & two)
{
	string s = two + "#" + one;
	int lengp = two.length();
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i<n; ++i) 
	{
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	int result = 0;
	for (int i = 0; i < z.size(); ++i)
	{
		if (z[i] == lengp)
			++result;
	}
	return result;
}

void solve()
{
	int K, L, S;
	string s, keyb;
	cin >> K >> L >> S;
	cin >> keyb;
	cin >> s;

	vector<vector<char> > ss(1);
	for (int len = 0; len < S; ++len)
	{
		int sz = ss.size();
		for (int cp = 1; cp < K; ++cp)
			for (int i = 0; i < sz; ++i)
				ss.push_back(ss[i]);
		int ind = 0;
		for (int k = 0; k < K; ++k)
		{
			for (int i = 0; i < sz; ++i)
			{
				ss[ind++].push_back(keyb[k]);
			}
		}
	}
	//for (int i = 0; i < ss.size(); ++i)
	//	cout << string(ss[i].begin(), ss[i].end()) << endl;

	int mx = 0;
	int sum = 0;
	for (int i = 0; i < ss.size(); ++i)
	{
		int cnt = getCount(string(ss[i].begin(), ss[i].end()), s);
		mx = max(mx, cnt);
		sum += cnt;
	}
	double mean = (double)sum / (double)ss.size();
	printf("%.7f\n", mx - mean);
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//freopen("d:/input.txt", "rt", stdin);
	int T; std::cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}