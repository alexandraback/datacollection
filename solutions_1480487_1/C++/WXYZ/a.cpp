#include<stdio.h>
#include<string.h>
int a[200];
int main()
{
	int t,n,i,j,tt,s;
	double l,r,c,ss;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%d",&n);
		s=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",a+i);
			s+=a[i];
		}
		printf("Case #%d:",tt);
		for (i=0;i<n;i++)
		{
			l=a[i];
			r=s;
			while (r-l>1e-12)
			{
				ss=0;
				c=(r+l)/2;
				for (j=0;j<n;j++)
				{
					if (c>a[j])
						ss+=c-a[j];
				}
				if (ss>s)
					r=c;
				else
					l=c;
			}
			printf(" %.5lf",(l-a[i])/s*100);
		}
		printf("\n");
	}
	return 0;
}