#include "stdio.h"

int main()
{
	int t,i;
	scanf("%d",&t);

	for(i=0; i<t; i++)
	{
		int a,b,j;
		double min_key, p;
		scanf("%d %d",&a, &b);

		p=1.0;
		min_key = b+2;

		for(j=0; j<=a; j++)
		{
			double tmp_p;
			double tmp_e;
			int k = a-j;
			int h = b-a+2*k+1;
			
			tmp_e = p*h + (1-p)*(h+b+1);

//			printf(">> %.6lf p=%.6lf tmp_p=%.6lf h=%d h'=%d\n",tmp_e,p,tmp_p,h,h+b+1);

			if(tmp_e < min_key)
				min_key = tmp_e;

			if(j<a)
			{
				scanf("%lf", &tmp_p);
				p*=tmp_p;
			}
		}

		printf("Case #%d: %.6lf\n",i+1,min_key);
	}

	return 0;
}
