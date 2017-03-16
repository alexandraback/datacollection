#include <cstdio>
int CAS,cas;
long double c,f,x,q,ans,v;
double oo,o1,o2,o3;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&CAS);
	for (cas=1; cas<=CAS; ++cas)
	{
		scanf("%lf%lf%lf",&o1,&o2,&o3);
		c=o1,f=o2,x=o3;
		ans=1e12;
		q=0;
		v=2;
		while (q<ans)
		{
			if (q+x/v<ans) ans=q+x/v;
			q+=c/v;
			v+=f;
		}
		oo=ans;
		printf("Case #%d: %.7lf\n",cas,oo);
	}
	return 0;
}
