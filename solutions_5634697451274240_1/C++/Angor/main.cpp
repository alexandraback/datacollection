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
		string s;
		cin >> s;
		int ans = 0;
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] != s[i - 1])
			{
				ans++;
			}
		}

		if ((s[0] == '-') == ((ans % 2) == 0))
		{
			ans++;
		}

		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}