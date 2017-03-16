#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int v[100000], rr[100000];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int T, cases = 1;
	int i, j;
	int N;
	long long ans, a, b, E, R, k;

	cin >> T;
	while( T-- )
	{
		cin >> E >> R >> N;
		for( i = 0; i < N; ++i )
			cin >> v[i];
		v[N] = 99999999;

		rr[N] = N;
		for( i = N-1; i >= 0; --i )
		{
			for( j = i+1; v[j] <= v[i]; j = rr[j] );
			rr[i] = j;
		}

		k = E;
		ans = 0;
		for( i = 0; i < N; ++i )
		{
			if( rr[i] == N )
				b = k;
			else
			{
				a = (rr[i]-i)*R;
				b = min(k+a-E, k);
			}
			
			if( b > 0 )
			{
				ans += b*v[i];
				k -= b;
			}

			k += R;
		}

		printf("Case #%d: %lld\n", cases++, ans);
	}

	return 0;
}