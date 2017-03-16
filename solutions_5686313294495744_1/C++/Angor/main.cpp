#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> g;
vector<int> mt;
vector<char> used;

bool try_kuhn(int v) {
	if (used[v])
	{
		return false;
	}

	used[v] = true;

	for (int i = 0; i < g[v].size(); ++i)
	{
		int to = g[v][i];
		if (mt[to] == -1
			|| try_kuhn(mt[to]))
		{
			mt[to] = v;
			return true;
		}
	}

	return false;
}

int main()
{
	cin.sync_with_stdio(0);
	freopen( "..\\input.txt", "r", stdin );
	freopen( "..\\output.txt", "w", stdout );

	int t;
	cin >> t;
	for( int tt = 1; tt <= t; tt++ )
	{
		int n;
		cin >> n;
		map<string, int> first_dict;
		int first_len = 0;
		map<string, int> second_dict;
		int second_len = 0;

		g.clear();
		mt.clear();
		used.clear();

		for (int i = 0; i < n; i++)
		{
			string first;
			string second;
			cin >> first >> second;

			int first_v = first_len;
			auto first_it = first_dict.find(first);
			if (first_it == first_dict.end())
			{
				first_dict[first] = first_len;
				first_len++;
			}
			else
			{
				first_v = first_it->second;
			}

			int second_v = second_len;
			auto second_it = second_dict.find(second);
			if (second_it == second_dict.end())
			{
				second_dict[second] = second_len;
				second_len++;
			}
			else
			{
				second_v = second_it->second;
			}
			
			if (first_v >= g.size())
			{
				g.push_back(vector<int>());
			}

			g[first_v].push_back(second_v);
		}
		
		mt.assign(second_len, -1);
		for (int i = 0; i < first_len; ++i)
		{
			used.assign(first_len, false);
			try_kuhn(i);
		}


		int par_count = 0;
		for (int i = 0; i < second_len; ++i)
		{
			if (mt[i] != -1)
			{
				par_count++;
			}
		}

		int min_e = first_len + second_len - par_count;
		int ans = n - min_e;
		//printf( "Case #%d: ", tt );
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}