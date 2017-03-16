#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > gd;
vector<vector<string> > sd;

void gen_strings(int ind, string s, int k)
{
	if (ind == s.size())
	{
		gd[k].push_back(stoi(s));
		sd[k].push_back(s);
		return;
	}
	if (s[ind] != '?')
		gen_strings(ind + 1, s, k);
	else
	{
		for (int i = 0; i < 10; i++)
		{
			gen_strings(ind + 1, s.replace(ind, 1, string(1, '0' + i)), k);
		}
	}
}

int main()
{
	cin.tie(nullptr), ios::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	for (int cc = 0; cc < t; cc++)
	{
		string a, b;
		int ans1 = -999999, ans2 = 999999, a1 = -1, a2 = -1;
		cin >> a >> b;
		gd.assign(2, vector<int>());
		sd.assign(2, vector<string>());
		gen_strings(0, a, 0);
		gen_strings(0, b, 1);
		for (auto qq = 0; qq < gd[0].size(); qq++)
		{
			for (auto ww = 0; ww < gd[1].size(); ww++)
			{
				int q = gd[0][qq], w = gd[1][ww];
				if (abs(q - w) < abs(ans1 - ans2) || (abs(q - w) == abs(ans1 - ans2) && make_pair(q, w) < make_pair(ans1, ans2)))
					ans1 = q, ans2 = w, a1 = qq, a2 = ww;
			}
		}
		cout << "Case #" << cc + 1 << ": " << sd[0][a1] << ' ' << sd[1][a2] << endl;
	}
	return 0;
}