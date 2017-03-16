#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	freopen( "..\\input.txt", "r", stdin );
	freopen( "..\\output.txt", "w", stdout );

	int t;
	cin >> t;
	for( int tt = 1; tt <= t; tt++ )
	{
		int k, c, s;
		cin >> k >> c >> s;
		vector<long long> degrees(c, 0);
		degrees[0] = 1;
		for (int i = 1; i < c; i++)
		{
			degrees[i] = degrees[i - 1] * k;
		}

		vector<long long> ans;
		long long shift = 0;
		while (k > 0)
		{
			long long val = 0;
			for (int i = 0; i < min(c, k); i++)
			{
				val += (shift + i) * degrees[c - 1 - i];
			}
			ans.push_back(val);

			k -= c;
			shift += c;
		}

		if (ans.size() > s)
		{
			cout << "Case #" << tt << ": IMPOSSIBLE" << endl;
			continue;
		}

		cout << "Case #" << tt << ":";
		for (auto val : ans)
		{
			cout << " " << val + 1;
		}
		cout << endl;
	}
	return 0;
}