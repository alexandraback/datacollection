#include <stdio.h>
#include <algorithm>
using namespace std;

int T;
double C, F, X, tmin;

int main()
{	int tt;
	double tc, tost, z1, z2;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(tt=1; tt<=T; ++tt)
	{
		scanf("%lf %lf %lf", &C, &F, &X);
		tmin = X/2.;
		tc=0; 
		tost=0; 
		z1 = 2; 
		z2 = 2+F;
		while(true)
		{
			tc += C/z1;
			tost = X/z2;
			if(tc+tost >= tmin)
				break;
			tmin = tc + tost;
			z1 = z2;
			z2 += F;
		}
		printf("Case #%d: %.7lf\n", tt, tmin);
	}

	return 0;
}