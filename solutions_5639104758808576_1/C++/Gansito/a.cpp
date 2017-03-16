#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int T , ans , cnt , n , d , add;
	string s;
	cin >> T;
	for( int k = 1; k <= T; k++ )
	{
		cin >> n;
		cin >> s;
		cnt = ans = 0;
		for( int i = 0; i <= n; i++ )
		{
			d = s[ i ] - '0';
			add = 0;
			if( i > cnt )
			{
				add = (i - cnt);
			}
			cnt += d + add;
			ans += add;
		}
		printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}