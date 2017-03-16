#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#define PI pair<int, int>
#define MP make_pair

const double eps = 1e-10;
const int INF = (1<<30);

using namespace std;

int a[200], vis[1000000];

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int i, j, k, st, n, nn;
	int cases = 1, T;

	cin >> T;
	while( T-- )
	{
		cin >> n;
		nn = (1<<n);
		memset(vis, -1, sizeof(vis));

		for( i = 0; i < n; ++i )
			cin >> a[i];

		for( st = 0; st < nn; ++st )
		{
			k = 0;
			for( j = 0; j < n; ++j )	if( (1<<j) & st )
				k += a[j];
			
			if( vis[k] == -1 )
				vis[k] = st;
			else
				break;
		}

		printf("Case #%d:\n", cases++);
		if( st == nn )
			printf("Impossible\n");
		else
		{
			j = 0;
			for( i = 0; i < n; ++i )	if( (1<<i) & st )
			{
				if( j )
					printf(" ");
				else
					j = 1;
				printf("%d", a[i]);
			}
			printf("\n");
			st = vis[k];
			j = 0;
			for( i = 0; i < n; ++i )	if( (1<<i) & st )
			{
				if( j )
					printf(" ");
				else
					j = 1;
				printf("%d", a[i]);
			}
			printf("\n");
		}
	}

	return 0;
}