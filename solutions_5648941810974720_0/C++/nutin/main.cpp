#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	freopen("A-small-attempt2.in", "r", stdin);
//	freopen("in.txt", "r", stdin);
//	ofstream fout("out.txt");
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
		map <char, pair<string, int> > ch = {
			{'Z', pair<string, int>("ZERO", 0)},
			{'W', pair<string, int>("TWO", 2)},
			{'U', pair<string, int>("FOUR", 4)},
			{'X', pair<string, int>("SIX", 6)},
			{'G', pair<string, int>("EIGHT", 8)}
		};
		map <char, pair<string, int> > nch = {
			{'O',  pair<string, int>("ONE", 1)},
			{'H',  pair<string, int>("THREE", 3)},
			{'V',  pair<string, int>("FIVE", 5)},
			{'S',  pair<string, int>("SEVEN", 7)},
		};
	for (int i = 0; i < T; ++i)
	{
		string s;
		cin >> s;
		vector <int> freq(256, 0);
		vector <int> ans;
		for (int j = 0; j < s.size(); ++j)
		{
			freq[s[j]]++;
		}
		for (auto it = ch.begin(); it != ch.end(); ++it)
		{
			while (freq[it->first] > 0)
			{
				string s1 = (it->second).first;
				for (int j = 0; j < s1.size(); ++j)
				{
					freq[s1[j]]--;
				}
				ans.push_back((it->second).second);
			}
		}
		for (auto it = nch.begin(); it != nch.end(); ++it)
		{
			while (freq[it->first] > 0)
			{
				string s1 = (it->second).first;
				for (int j = 0; j < s1.size(); ++j)
				{
					freq[s1[j]]--;
				}
				ans.push_back((it->second).second);
			}
		}
		for (int j = 0; j < freq['I']; ++j)
		{
			ans.push_back(9);
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d: ", i + 1);
		for (int j = 0; j < ans.size(); ++j)
		{
			cout << ans[j];
		}
		cout << endl;
//		printf("Case #%d: %s\n", i + 1, ans.c_str());
	}
	return 0;
}

