#include<cstdio>
#include<algorithm>

using namespace std;

#define MX 300

int tt;
int n;
int J[MX];
int X;

int main()
{
	scanf("%d",&tt);
	for(int t=1;t<=tt;++t)
	{
		scanf("%d",&n);
		X=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",J+i);
			X+=J[i];
		}
		printf("Case #%d:",t);
		int nn=n;
		int tot=X+X;
		double mn=tot/(double)n;
		for(int i=0;i<n;++i)
		{
			if (J[i]>mn)
			{
				--nn;
				tot-=J[i];
				mn=tot/(double)nn;
			}
		}
		for(int i=0;i<n;++i)
		{
			double x=0;
			if (J[i]<=mn)
				x=(mn-J[i])*100/X;
			printf(" %.9lf",x);
		}
		puts("");
	}
	return 0;
}
