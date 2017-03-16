#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

int a[22], n, mask, X=0;

int dp[20][201], w[20][201];

int Rec(int pos, int t)
{
	if (t<0) return 0;
	if (!t) return 1;
	if (pos==n) return 0;

	int& res = dp[pos][t];
	if (res != -1) return (res>0);

	if (Rec(pos+1, t))
	{
		w[pos][t] = 0;
		return 1;
	}

	if (mask&(1<<pos))
	{
		if (Rec(pos+1, t-a[pos]))
		{
			w[pos][t] = 1;
			return 1;
		}
	}

	return 0;
}

bool Elimin(int nom, double M)
{
	double val = (double)a[nom] + M*X;

	double XX = 0, nn = 0;
	FOR(i, 0, n)
		if (i != nom && (double)a[i] <= val)	{
			XX = XX+a[i]; nn = nn+1;
		}

	double SP = (val*nn - XX)/(double)X;

	if (SP+M<1) return true;
	return false;
}

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int tc, ind=0; scanf("%d", &tc);
	while (tc --> 0)
	{
		scanf("%d", &n);
		X = 0; FOR(i, 0, n) { scanf("%d", a+i); X += a[i]; }

		double res[20]; FOR(i, 0, n) res[i] = 0;

		double curr = 1.0;
		FOR(i, 0, n)
		{
			double L=0, R=1;
			FOR(j, 0, 200)
			{
				double M = (L+R)/2.;
				if (Elimin(i, M))
					L = M;
				else
					R = M;
			}
			res[i] = (L+R)/2.;
			curr -= res[i];
		}

		double rr = 0;
		printf("Case #%d:", ++ind); FOR(i, 0, n) { printf(" %.12lf", res[i]); rr += res[i]; } printf("\n");

		fprintf(stderr, "%.12lf\n", rr);
	}
	return 0;
}