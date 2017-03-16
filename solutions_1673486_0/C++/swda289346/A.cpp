#include <stdio.h>
#define A 99999

int main()
{
	int t;
	int a, b;
	double p[A], pn[A], ans;
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		scanf("%d%d", &a, &b);
		for (int j=0;j<a;++j)
			scanf("%lf", &p[j]);
		pn[0] = p[0];
		for (int j=1;j<a;++j)
			pn[j] = pn[j-1]*p[j];
		ans = 1+b+1;
		for (int j=0;j<a;++j)
			ans <?= (j+b-a+j+1)*pn[a-j-1]+(j+b-a+j+1+b+1)*(1-pn[a-j-1]);
		printf("Case #%d: %.6lf\n", i, ans);
	}
	return 0;
}
