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
		vector<pair<string, string>> topics(n);
		for (int i = 0; i < n; i++)
		{
			cin >> topics[i].first;
			cin >> topics[i].second;
		}
		
		int ans = 0;
		for (int mask = 0; mask < 1 << n; mask++)
		{
			set<string> dict_first;
			set<string> dict_second;

			int count_false = 0;
			for (int i = 0; i < n; i++)
			{
				if ((1 << i) & mask)
				{
					dict_first.insert(topics[i].first);
					dict_second.insert(topics[i].second);
				}
				else
				{
					count_false++;
				}
			}

			if (ans >= count_false)
			{
				continue;
			}

			bool isOk = true;
			for (int i = 0; i < n; i++)
			{
				if ((1 << i) & mask)
				{
					continue;
				}
				
				if (dict_first.find(topics[i].first) == dict_first.end()
					|| dict_second.find(topics[i].second) == dict_second.end())
				{
					isOk = false;
					break;
				}
			}

			if (isOk)
			{
				ans = max(ans, count_false);
			}
		}
		//printf( "Case #%d: ", tt );
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}