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
		string ans;
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				ans = s[i];
				continue;
			}

			if (ans[0] <= s[i])
			{
				ans = s[i] + ans;
			}
			else
			{
				ans = ans + s[i];
			}
		}


		//printf( "Case #%d: ", tt );
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}