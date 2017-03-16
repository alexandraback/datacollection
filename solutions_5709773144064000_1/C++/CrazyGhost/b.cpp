#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
void solve()
{
	double C,F,X;
	scanf("%lf%lf%lf", &C, &F, &X);
	double ft = 0, rt = 2;
	int nf;
	double previous = 1e100;
	for(nf = 0;; nf ++, rt += F)
	{
		double cur = X/rt + ft;
		if(cur - previous >= -1e-7 )
		{
			printf("%.7lf\n", previous);
			return;
		}
		previous = cur;
		ft += C/rt;
	}
	return ;
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
