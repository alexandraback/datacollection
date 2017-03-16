#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int v[10], h[10];

bool chk( int a, int b, int c )
{
	h[0] = 1;
	h[1] = a;	h[2] = b;	h[3] = c;
	h[4] = a*b;	h[5] = b*c;	h[6] = a*c;
	h[7] = a*b*c;

	int i, j;
	for( i = 0; i < 7; ++i )
	{
		for( j = 0; j < 8; ++j )	if( h[j] == v[i] )
			break;
		if( j == 8 )
			return 0;
	}
	return 1;
}

int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-attempt0.out", "w", stdout);

	int T, cases = 1;
	int i, j, k;
	int R, N, M, K;
	bool ok;

	cin >> T;
	while( T-- )
	{
		cin >> R >> N >> M >> K;
		printf("Case #%d:\n", cases++);
		while( R-- )
		{
			for( i = 0; i < K; ++i )
				scanf("%d", &v[i]);
			sort(v, v+K);

			ok = 0;
			for( i = 2; !ok && i <= M; ++i )
				for( j = 2; !ok && j <= M; ++j )
					for( k = 2; !ok && k <= M; ++k )
					{
						ok |= chk(i, j, k);
						if( ok )
							printf("%d%d%d\n", i, j, k);
					}

			if( ok == 0 )
				puts("!!");
		}
	}

	return 0;
}