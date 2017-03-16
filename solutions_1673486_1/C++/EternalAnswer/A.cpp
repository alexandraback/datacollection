#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int Maxn=101000;

double s[Maxn];
int n,m,Test;

int main()
{
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	
	scanf("%d",&Test);
	for (int ii=1;ii<=Test;++ii)
	{
		scanf("%d%d",&n,&m);
		s[0]=1;
		for (int i=1;i<=n;++i)
		{
			scanf("%lf",&s[i]);
			s[i]*=s[i-1];
		}
		
		double res=m+2;
		double one=1;
		for (int i=0;i<n;++i)
		{
			double ans=s[n-i]*((double)m-n+1+i+i)+(one-s[n-i])*((double)m-n+1+i+i+m+1);
			res=min(res,ans);
		}
		
		printf("Case #%d: %.8lf\n",ii,res);
	}
	
	return 0;
}