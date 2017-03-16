#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main()
{
	int TC;
	cin >> TC;
	for ( int tc=1 ; tc<=TC ; ++tc )
	{

		int A, B;
		double p[A+1];
		cin >> A >> B;
		for ( int i=0 ; i<A ; ++i ) cin >> p[i];
	
		double accu[A+2];
		accu[0] = p[0];
		for ( int i=1 ; i<A ; ++i ) accu[i] = accu[i-1] * p[i];

		double res = min(A + B + 1, B + 2);
		// backspace
		for ( int i=0 ; i<A ; ++i )
		{
			double t = accu[A - i - 1];
			double c1 = B - A + 1 + 2 * i;
			double c2 = c1 + B + 1;
			double expect = t * c1 + (1 - t) * c2;
			//printf("%.5lf %.3lf %.3lf %.6lf\n", t, c1, c2, expect);
			if ( res > expect ) res = expect;
		}

		printf("Case #%d: ", tc);
		printf("%.9lf\n", res);
	}
	return 0;
}
