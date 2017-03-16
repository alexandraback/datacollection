#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll ;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen( "in", "r", stdin );
	freopen( "out", "w", stdout );

	int tt;
	cin >> tt ;
	for( int t=1; t<=tt; t++ )
	{
		ll  n ;
		cin >> n ;

		if( n == 0 )
		{
			cout << "Case #" << t << ": INSOMNIA"<< endl ;
			continue ;
		}

		ll  ans ;
		int  flag = 0 ;

		for( ll k=1; k <= 100; k++ )
		{
			ans = k*n ;

			while(ans)
			{
				int d = ans%10 ;
				ans /= 10 ;
				flag |= (1<<d) ;
			}

			if( flag == 1023 )
			{
				ans = k*n;
				break;
			}
		}

		cout << "Case #" << t << ": " << ans << endl ;
	}

	return 0 ;
}