#include <cstdio>
int CAS,cas;
double c,f,x,q,ans,v;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&CAS);
	for (cas=1; cas<=CAS; ++cas)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		ans=1e12;
		q=0;
		v=2;
		while (q<ans)
		{
			if (q+x/v<ans) ans=q+x/v;
			q+=c/v;
			v+=f;
		}
		printf("Case #%d: %.7lf\n",cas,ans);
	}
	return 0;
}
