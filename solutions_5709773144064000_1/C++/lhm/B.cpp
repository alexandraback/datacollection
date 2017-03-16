#include <iostream>
#include <string.h>
#include <stdio.h>

#define eps 0.00000001
using namespace std;

double res,now,C,F,X,sped;
int T;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);

	scanf("%d",&T);
	for ( int cas = 1; cas <= T; ++cas )
	{
		scanf("%lf%lf%lf",&C,&F,&X);
		now = 0;
		sped = 2.0;
		res = X/sped; 
		while ( 1 )
		{
			res = min(res,now+X/sped);
			//printf("%0.8lf\n",res);
			now += ( C / sped );
			sped += F;
			if (  res - (now + X / sped ) < eps) break;
		}
		printf("Case #%d: %0.7lf\n",cas,res);
	}
	return 0;
}