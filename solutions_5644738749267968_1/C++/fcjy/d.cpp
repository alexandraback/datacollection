#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

pair<double, int> p[4000];

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, N, cases = 1, x, y, st;
	double tmp;

	scanf("%d", &T);
	while( T-- )
	{
		scanf("%d", &N);
		for( int i = 0; i < N; ++i )	
		{
			scanf("%lf", &tmp);
			p[i] = make_pair(tmp, 0);
		}
		for( int i = 0; i < N; ++i )
		{
			scanf("%lf", &tmp);
			p[N+i] = make_pair(tmp, 1);
		}
		sort(p, p+2*N);

		st = x = 0;
		for( int i = 0; i < 2*N; ++i )
		{
			if( p[i].second == 0 )
				st++;
			else
			{
				if( st > 0 )
					st--;
				else
					x++;
			}
		}

		st = y = 0;
		for( int i = 2*N-1; i >= 0; --i )
		{
			if( p[i].second == 0 )
				st++;
			else
			{
				if( st > 0 )
					y++;
				st--;
			}
			st = max(st, 0);
		}

		printf("Case #%d: %d %d\n", cases++, y, x);
	}

	return 0;
}
