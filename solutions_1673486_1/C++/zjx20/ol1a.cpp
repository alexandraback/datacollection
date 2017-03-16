#include <cstdio>

double p[200000];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("ol1a_output.txt", "w", stdout);

	int t;
	int a,b;
	scanf("%d",&t);
	int ca=0;
	while(t--)
	{
		printf("Case #%d: ", ++ca);
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++)
			scanf("%lf",&p[i]);

		double minp = 1/*enter*/ + b + 1/*enter*/;
		double tot_cor = 1.0;
		for(int i=0;i<=a;i++)
		{
			int right = ((a-i)/*back*/ + (b-i)/*rest*/ + 1/*enter*/);
			int wrong = ((a-i)/*back*/ + (b-i)/*rest*/ + 1/*enter*/ + b/*total*/ + 1/*enter*/);
			//printf("backto: %d tot_cor: %lf ifright: %d, ifwrong: %d\n", i, tot_cor, right, wrong);
			
			double tmp = tot_cor * right + (1.0-tot_cor) * wrong;
			if(tmp < minp) minp = tmp;
			tot_cor *= p[i];
		}
		printf("%.8lf\n", minp);
	}
	return 0;
}