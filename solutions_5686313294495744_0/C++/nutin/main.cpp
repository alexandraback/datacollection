#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int N;
vector<string> gens;
void gen(string s)
{
	if (s.size() == N)
	{
		int count = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '0')
			{
				++count;
			}
		}
		if (count >= 2)
			gens.push_back(s);
	}
	else
	{
		s.push_back('0');
		gen(s);
		s.pop_back();
		s.push_back('1');
		gen(s);
		s.pop_back();
	}
}



int main()
{
//	freopen("A-large.in", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
//	ofstream fout("out.txt");
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		gens.clear();
		gen("");
		vector <pair<string, string> > topics;
		for (int j = 0; j < N; ++j)
		{
			string s1, s2;
			cin >> s1 >> s2;
			topics.push_back(make_pair(s1, s2));
		}
		int max_fake = -1;
		for (int j = 0; j < gens.size(); ++j)
		{
			int cur_fake = 0;
			for (int k = 0; k < gens[j].size(); ++k)
			{
				bool is_fake = false;
				if (gens[j][k] == '1')
				{
					for (int l = 0; l < topics.size(); ++l)
					{
						if (l != k  && topics[k].first == topics[l].first)
						{
							is_fake = true;
						}
					}
					if (is_fake)
					{
						for (int l = 0; l < topics.size(); ++l)
						{
							if (l != k && gens[j][l] == '0' && topics[k].second == topics[l].second)
							{
								++cur_fake;
								break;
							}
						}
					}
				}
			}
			max_fake = max(cur_fake, max_fake);
		}
		printf("Case #%d: %d\n", i + 1, max_fake);
	}
	return 0;
}
