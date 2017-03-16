#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double a[100005];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas=0;scanf("%d",&T);
	while(T--)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		double x = 1.0;
		for(int i = 0; i < A; i++)
			scanf("%lf",&a[i]), x*=a[i];
		double ret = min(2.0+B, (B-A+1)+(B+1)*(1-x));
		x = 1.0;
		for(int i = 0; i < A; i++)
		{
			ret = min(ret, (B-i+A-i+1)+(B+1)*(1-x));
			x *= a[i];
		}
		printf("Case #%d: %.6f\n",++cas,ret);
	}

	return 0;
}
