#include <stdio.h>

using namespace std;


int main()
{
	long long tc,t,r=0;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		int r=0;
		double c, f, x, t, y;
		scanf("%lf %lf %lf",&c,&f,&x);
		t=0;
		y=x;
		while (y>=t+x/(2+r*f))
		{
			y=t+x/(2+r*f);
			t+=c/(2+r*f);
			++r;
		}
		printf("Case #%lld: %.10lf\n",tc+1,y);
	}
	return 0;
}
