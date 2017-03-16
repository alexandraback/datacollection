#include <iostream>
#include <algorithm>
using namespace std;
double C,F,X;
int T;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%lf %lf %lf",&C,&F,&X);
		double ans = 0;
		double v = 2;
		bool ok = 0;
		while(!ok)
		{
			double tm1 = X/v;
			double tm2 = C/v + X/(v+F);
			if(tm1<=tm2)
			{
				ok=1;
				ans+=tm1;
				break;
			}
			else
			{
				ans+=C/v;
				v+=F;
			}
		}
		printf("Case #%d: %.7f\n",cas,ans);
	}
	return 0;	
}
