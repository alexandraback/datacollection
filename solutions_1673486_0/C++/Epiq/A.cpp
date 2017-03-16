#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <utility>
#define mp make_pair
#define pb push_back
#define f(x, n) for (int (x) = 0; (x) < (n); (x)++)
#define Max 100000
using namespace std;

int T, A, B;
double p[Max];

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	
	scanf("%d", &T);
	f (test, T)
	{
		scanf("%d %d", &A, &B);
		f (i, A) scanf("%lf", &p[i]);
		
		double ok = 1.0;
		double r = 2 * B + 2;
		
		f (i, A)
		{
			double back = (A - i + B - i + 1) * ok  + (A - i + B - i + 1 + B + 1) * (1.0 - ok);
			r = min(r, back);
			ok *= p[i];
		}
		
		// Keep typing
		double keep = (B - A + 1) * ok + (B - A + B + 2) * (1.0 - ok);
		// Give up
		double giveup = (B + 2);
		
		r = min(r, min(keep, giveup));
		
		printf("Case #%d: %lf\n", test + 1, r);
	}
	
	
	return 0;
}
