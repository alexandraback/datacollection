#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <queue>
#include <ctime>
#include <functional>
#include <cstring>
#include <map>
#include <cctype>
#include <unordered_map>

using namespace std;
using pr = pair<int, int>;

int getTotal(string let, string need, int S)
{
	set<char> all;
	for (char ch : let)
	{
		all.insert(ch);
	}
	for (char ch : need)
	{
		if (all.count(ch) == 0)
		{
			return 0;
		}
	}

	int d = 0;
	for (int l = need.size() - 1; l > 0; l--)
	{
		bool ok = true;
		for (int i = 0; i < l; i++)
		{
			if (need[i] != need[need.size() - l + i])
			{
				ok = false;
			}
		}
		if (ok)
		{
			d = l;
			break;
		}
	}
	int next = need.size() - d;
	int res = 0;
	int cur = S - need.size();
	while (cur >= 0)
	{
		res++;
		cur -= next;
	}
	return res;
}

double solve(string let, string need, int S)
{
	map<char, int> cnt;
	int total = let.size();
	for (char ch : let)
	{
		cnt[ch]++;
	}

	double res = 0;
	int dif = S - need.size() + 1;
	if (dif > 0)
	{
		double cur = dif;
		for (char ch : need)
		{
			cur *= ((double)cnt[ch]) / total;
		}
		return getTotal(let, need, S) - cur;
	}
	else
	{
		return 0.0;
	}
}


int main()
{
	cout.precision(15);
	freopen("INPUT.TXT", "r", stdin); freopen("OUTPUT.TXT", "w", stdout);
	int t, k, l, s;
	string let, need;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> k >> l >> s;
		cin >> let >> need;
		double res = solve(let, need, s);
		cout << "Case #" << i + 1 << ": " << res << endl;
	}
}