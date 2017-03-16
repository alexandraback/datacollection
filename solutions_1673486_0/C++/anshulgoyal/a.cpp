#include<stdio.h>
#include<algorithm>
using namespace std;
double inp[100009];
int main()
{
	double prob;
	int t, i, j, a, b;
	scanf("%d",&t);
	for(int tc=1; tc<=t; tc++)
	{
		scanf("%d%d",&a,&b);
		double ans = min(b-a+b+2, b+2);
		prob = 1.0;
		for(int i=0; i<a; i++)
		{
			scanf("%lf",&inp[i]);
			prob*=inp[i];
			ans = min(ans, (a-i-1+b-i-1 + 1) + (1-prob)*(b+1));
		}
		printf("Case #%d: %lf\n",tc, ans);
	}
	return 0;
}
			
