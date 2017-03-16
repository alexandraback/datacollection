#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

double C, F, X;

double cal( int tims )
{
	double res = 0, f = 2.0;
	
	while( tims-- )
	{
		res += C/f;
		f += F;
	}

	res += X / f;

	return res;
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, cases = 1;
	int L, R, p1, p2;
	double v1, v2, ans;

	scanf("%d", &T);
	while( T-- )
	{
		scanf("%lf %lf %lf", &C, &F, &X);
		L = 0, R = 100000;
		ans = 1e30;
		while( R != L )
		{
			int d = max(1, (R-L)/3);
			p1 = L + d;
			p2 = R - d;
			v1 = cal(p1);	ans = min(ans, v1);
			v2 = cal(p2);	ans = min(ans, v2);
			if( v1 > v2 )
				L = p1;
			else
				R = p2;
		}

		printf("Case #%d: %.10lf\n", cases++, ans);
	}

	return 0;
}
