#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
#define NN 1000

int main()
{
	int T;
	double c,f,x;
	freopen("B-large.in", "r", stdin);
	freopen("b-large.out", "w", stdout);
	scanf("%d",&T);;
	for (int cas=1; cas<=T; cas++)
	{
		scanf("%lf%lf%lf", &c,&f,&x);
		double mint, t, bt=0;
		int k;
		mint = x/2;
		for (k=0; ; k++)
		{
			bt += c/(2+k*f);
			t = bt + x/(2+k*f+f);
			if (t<mint) mint=t;
			else break;
		}
		printf("Case #%d: %.8lf\n", cas, mint);
	}
	return 0;
}

