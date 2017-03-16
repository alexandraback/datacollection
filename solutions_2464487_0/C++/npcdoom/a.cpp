#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

int main ()
{
	int T;
	scanf("%d",&T);

	for (int j = 1; j <= T; j++)
	{
		long long int r,t;
		scanf("%lld %lld",&r,&t);

		long long r1 = r;
		long long r2 = r1+1;
		long long int count = 0;
		while (t)
		{
			t -= (r2*r2-r1*r1);

			if ( t < 0)
				break;

			r2 += 2;
			r1 += 2;
			++count;
		}

		printf("Case #%d: %lld\n",j,count);
	}
	return 0;
}
