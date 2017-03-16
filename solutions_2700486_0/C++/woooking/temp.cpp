
#include <cstdio>
#include <cmath>
#include <algorithm>

int cases;

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&cases);
	for(int i=0;i<cases;++i)
	{
		int n,x,y;
		double ans;
		scanf("%d%d%d",&n,&x,&y);
		x=x>=0?x:-x;
		int k=(x+y)/2;
		if(n>2*k*k+3*k+1)ans=1;
		else if(n<=2*k*k-k)ans=0;
		else
		{
			n-=2*k*k-k;
			if(y==2*k)
			{
				if(n==4*k+1)ans=1;
				else ans=0;
			}
			else if(n<2*k+y+1)
			{
				double f[2000]={0};
				f[0]=1;
				for(int i=1;i<=n;++i)
				{
					for(int j=i;j>=1;--j)f[j]=(f[j]+f[j-1])/2;
					f[0]/=2;
				}
				ans=0;
				for(int i=y+1;i<=n;++i)ans+=f[i];
			}
			else ans=1;
		}
		printf("Case #%d: %.6lf\n",i+1,ans);
	}
	return 0;
}
