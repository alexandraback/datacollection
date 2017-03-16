#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int maxBananas(string kb, string wd, int types)
{
	for (auto c : wd)
	{
		if (kb.find(c) == -1)
			return 0;
	}
	
	int mx = 0;

	for (int i = 1; i < kb.size(); i++)
	{
		string suf = kb.substr(i); 
		string pref = kb.substr(0, i);
		if (suf == pref)
		{
			mx = i;
			break;
		}
	}
	
	return (types - wd.size() + mx) / mx;
}

int k, l, s;
string kb, wd;
int mx, sum = 0, amnt = 0;

void rec(string cur)
{
	if (cur.size() == s)
	{
		int cnt = 0;
		for (int i = 0; i <= cur.size() - wd.size(); i++)
		{
			if (cur.substr(i, wd.size()) == wd)
				cnt++;
		}
		mx = max(cnt, mx);
		sum += cnt;
		amnt++;
	}
	else
	{
		for (auto c : kb)
		{
			string nw = cur + c;
			rec(nw);
		}
	}
}	

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> k >> l >> s >> kb >> wd;
		amnt = sum = mx = 0;
		rec("");
		printf("Case #%d: %.9f\n", i, mx - sum * 1.0 / amnt);
	}
	return 0;
}
