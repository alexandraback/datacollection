#include<cstdio>
#include<cmath>

int TestCase,Case;

double C,F,X,Sum,Sub;

int k,l;

int main()
{
//	freopen("b.in","rb",stdin);
//	freopen("b.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%lf%lf%lf",&C,&F,&X);
		k=(int)(((X-C)*F-2.0*C)/(F*C))+1;
		for(l=0,Sum=X/2.0;l<=k;l++)
		{
			Sub=X/(F*(l+1)+2.0)-(X-C)/(F*l+2.0);
			if(Sub*(k-l)>=-(1e-6))break;
			Sum+=Sub;
		}
		printf("Case #%d: %lf\n",Case,Sum);
	}
	return 0;
}
