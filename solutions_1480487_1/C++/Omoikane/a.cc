#include <stdio.h>

int t, n, x, y[200];
double f;

int main()
{
	scanf(" %d", &t);
	for(int cs=1; cs<=t; cs++)
	{
		scanf(" %d", &n);
		x=0; f=200;
		for(int i=0; i<n; i++)
		{
			scanf(" %d", y+i);
			x+=y[i];
			if (y[i]<f) f=y[i];
		}
		
		int x1=x;
		while(x1)
		{
			int m=1000;
			for(int i=0; i<n; i++)
				if ((y[i]<m) && (y[i]>f)) m=y[i];
			int a=0;
			for(int i=0; i<n; i++)
				if (y[i]<=f)
					a++;
			if (a*(m-f)>=x1)
			{
				f+=double(x1)/a;
				x1=0;
			}
			else
			{
				x1-=a*(m-f);
				f=m;
			}
		}

		printf("Case #%d:", cs);
		for(int i=0; i<n; i++)
		{
			if (y[i]>=f) printf(" 0.000000");
			else printf(" %f", (f-y[i])/x*100);
		}
		printf("\n");
	}
	return 0;
}
