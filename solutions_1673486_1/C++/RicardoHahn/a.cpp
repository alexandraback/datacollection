#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 111000

double pFalse[MAX];
double p[MAX];

int main()
{
	int t;
	scanf("%d",&t);
	for(int tcnt=1; tcnt<=t; ++tcnt)
	{
		int a,b;
		double resp = 2*b+10;
		scanf("%d %d",&a, &b);
		for(int i=0; i<a;++i)
			scanf("%lf",&p[i]);

		pFalse[0] = 1-p[0];
		for(int i=1; i<a; ++i)
			pFalse[i] = pFalse[i-1] + (1-pFalse[i-1])*(1-p[i]);

		resp = 2+b;

		for(int i=0; i<a; ++i)
		{
			double tmp =0;
			tmp += pFalse[i]*(a-i + b-i + b );
			tmp += (1-pFalse[i])*(a-i + b-i - 1);
			if(tmp < resp)
				resp = tmp;
		}

		printf("Case #%d: %.7f\n",tcnt,resp);
	}
	return 0;
}

