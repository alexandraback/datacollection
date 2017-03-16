#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void)
{
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
	int TK = 0;
	int T = 0;
	scanf("%d",&T);
	while(T--)
	{
		int A = 0;
		int B = 0;
		scanf("%d %d",&A,&B);
		
		double ans = B+2; // retype immediately.
		double allright = 1.0;
		for(int i = 0;i < A;i++)
		{
			ans = min(ans,allright*(A-i+B-i+1)+(1.0-allright)*(A-i+B-i+1+B+1)); // backspace.

			double p = 0.0;
			scanf("%lf",&p);
			allright *= p;
		}
		ans = min(ans,allright*(B-A+1)+(1.0-allright)*(B-A+1+B+1)); // keep typing.
		printf("Case #%d: %.12f\n",++TK,ans);
	}
	return 0;
}
