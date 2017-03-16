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

int a[1000];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int i, j, k, sum, n;
	double t, ll, rr, mid;
	int cases = 1, T;

	cin >> T;
	while( T-- )
	{
		cin >> n;
		sum = 0;
		for( i = 0; i < n; ++i )
		{
			cin >> a[i];
			sum += a[i];
		}

		printf("Case #%d:", cases++);
		for( i = 0; i < n; ++i )
		{
			ll = 0, rr = sum;
			
			for( k = 0; k < 100; ++k )
			{
				mid = (ll+rr)/2;
				t = sum - mid;
				for( j = 0; j < n; ++j )	if( j != i )
				{
					if( a[j] < a[i]+mid )
						t -= a[i]+mid-a[j];
				}
				if( t > 0 )
					ll = mid;
				else
					rr = mid;
			}
			
			printf(" %.10lf", ll*100./sum);
		}
		printf("\n");
	}

	return 0;
}