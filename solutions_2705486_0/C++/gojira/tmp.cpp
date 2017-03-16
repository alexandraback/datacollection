#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dp[4001][5];

pair<int, int> check(const string &s, int pos, const string &t, int lst)
{
	if (pos + t.length() > s.length())
		return make_pair(-1, 0);
	int ret = 0;
	int last = -5 + lst;
	for(int i = 0; i < t.length(); i++)
	{
		if (s[pos + i] == t[i]) continue;
		if (i - last < 5)
			return make_pair(-1, 0);
		last = i;
		++ret;
	}
	return make_pair(ret, max(last - (int)t.length() + 5, 0));
}

int main()
{
	freopen("dict.txt", "r", stdin);
	vector<string> dict(521196);
	int len = 0;
	for(int i = 0; i < dict.size(); i++)
	{
		cin >> dict[i];
		len = max(len, (int)dict[i].length());
	}
	cout << len << endl;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k, n, T, a;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		string s;
		cin >> s;
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for(i = 0; i < s.length(); i++)
			for(int last = 0; last < 5; last++)
			{
				if (dp[i][last] == -1) continue;
				for(j = 0; j < dict.size(); j++)
				{
					pair<int, int> x = check(s, i, dict[j], last);
					if (x.first == -1) continue;
					if (dp[i + dict[j].length()][x.second] == -1 || dp[i + dict[j].length()][x.second] > dp[i][last] + x.first)
						dp[i + dict[j].length()][x.second] = dp[i][last] + x.first;
				}
			}
		int ans = (int)1e9;
		for(i = 0; i < 5; i++)
			if (dp[s.length()][i] != -1)
				ans = min(ans, dp[s.length()][i]);
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}