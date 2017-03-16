#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<algorithm>

using namespace std;

//#define _INFILE		"A.in"
//#define _OUTFILE	"A.out"

#define _INFILE		"A-small-attempt0.in"
#define _OUTFILE	"A-small.out"


typedef long long ll;

double solve()
{
	int a, b;
	scanf("%d%d",&a,&b);
	double prob = 1.0;
	double result = b + 2;
	for(int i=0; i<a; i++)
	{
		double p;
		scanf("%lf",&p);
		prob *= p;

		int backspaces = a - i - 1;
		int types = backspaces * 2 + (b - a + 1);
		double pp = (prob * types) + (1 - prob) * (types + b + 1);
		result = min(result, pp);
	}
	return result;
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d: %lf\n", i+1, solve());
	}
	return 0;
}

