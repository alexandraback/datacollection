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
		int n, res = 0;
		cin >> n;
		vector<pair<string, string> > sr;
		for (int i = 0; i < n; i++)
		{
			string fst, scd;
			cin >> fst >> scd;
			sr.push_back({ fst, scd });
		}
		for (int i = 0; i < (1 << n); i++)
		{
			map<string, vector<int>> mp1, mp2;
			int bitc = 0;
			for (int j = 0; j < n; j++)
			{
				if (!(i & (1 << j)))
					mp1[sr[j].first].push_back(j), mp2[sr[j].second].push_back(j);
				else
					bitc++;
			}
			bool q = true;
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j))
				{
					int s1 = mp1[sr[j].first].size();
					int s2 = mp2[sr[j].second].size();
					if (s1 >= 1 && s2 >= 1)
					{
						if (s1 <= 1 && s2 <= 1 && mp1[sr[j].first][0] == mp2[sr[j].second][0])
							q = false;
					}
					else
						q = false;
				}
			}
			if (q)
				res = max(res, bitc);
		}
		cout << "Case #" << cc + 1 << ": " << res << endl;
	}
	return 0;
}