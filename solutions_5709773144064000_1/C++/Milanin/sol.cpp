#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1000000
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		double c, f, x, v, r=1E20;
		scanf("%lf%lf%lf", &c, &f, &x);
		v=0;
		for(int i=0; i<N; i++)
		{
			r=min(r, v+x/(2+i*f));
			v+=c/(2+i*f);
		}
		printf("Case #%d: %.9lf\n", t, r);
	}
	return 0;
}
