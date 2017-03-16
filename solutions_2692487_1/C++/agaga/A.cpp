#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector < long long > v;
int main ()
{
	int t;
	scanf ( "%d", &t );
	for ( int j = 1; j <= t; j ++ )
	{
		printf ( "Case #%d: ", j );
		long long a, n, x;
		scanf ( "%lld %lld", &a, &n );
		while ( n -- )
		{
			scanf ( "%lld", &x );
			if ( x < a ) a += x;
			else v.push_back ( x );
		}
		sort ( v.begin(), v.end() );
// 		printf ( "a: %d\n", a );
		int ans = v.size(), ans2 = 0, ans3 = v.size();
		for ( int i = 0; i < v.size() and ans2 < ans; i ++ )
		{
			while ( v[i] >= a ) 
			{
				a += ( a - 1 );
				ans2 ++;
				if ( ans2 == ans ) break;
			}
			a += v[i];
// 			printf ( "a: %d\n", a );
			ans3 = min ( ans3, ans - i - 1 + ans2 );
		}
		printf ( "%d\n", ans3 );
		v.clear();
	}
	return 0;
}