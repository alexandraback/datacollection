#include <cstdio>
using namespace std;

// Main
int main(void)
{
	int tc,cs;
	double C,F,X,ans,sec;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		ans=0.0;
		sec=2.0;
		scanf("%lf%lf%lf",&C,&F,&X);

		// Wait and Buy
		while(X/sec>C/sec+X/(sec+F))
		{
			ans+=(C/sec);
			sec+=F;
		}

		// Output
		printf("Case #%d: %.7lf\n",cs,ans+X/sec);
	}
	return 0;
}