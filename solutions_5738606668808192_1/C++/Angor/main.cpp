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
	
		int n, j;
		cin >> n >> j;
		
		cout << "Case #" << tt << ":" << endl;
		int mask = 0;
		while ( j-- > 0)
		{
			string s(n - 1, '0');
			s[0] = '1';
			s[n - 2] = '1';
			for (int i = 0; i < (n - 4) / 2; i ++)
			{
				s[2 + i * 2] = ((mask & (1 << i)) == 0) ? '0' : '1';
			}
			
			string ans(n, '0');
			for (int i = 0; i < n - 1; i++)
			{
				if (s[i] == '1' || (i > 0 && s[i - 1] == '1'))
				{
					ans[i] = '1';
				}
			}
			ans[n - 1] = '1';

			cout << ans;
			for (int b = 2; b <= 10; b++)
			{
				cout << " " << b + 1;
			}
			cout << endl;

			mask++;
		}
		//printf( "Case #%d: ", tt );
	}
	return 0;
}