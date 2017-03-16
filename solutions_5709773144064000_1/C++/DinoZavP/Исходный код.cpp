#include<cstdio>
using namespace std;

void main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	double C, F, X, time, min_time, k, z, l;
	int T;
	scanf("%d", &T);
	for(int i=1;i<=T;i++)
	{
		scanf("%lf %lf %lf", &C, &F, &X);
		time=X/2;
		z=2;
		k=1;
		l=0;
		min_time=0;
		while(time>=min_time)
		{
			l=l+C/z;
			z=z+F;
			min_time=l+(X/z);
			if (min_time<=time) time=min_time;
		}
		printf("Case #%d: %0.7lf\n", i, time);
	}
}