#include <stdio.h>

int main()
{
	int cases;scanf("%d",&cases);
	for (int cs=1;cs<=cases;cs++)
	{
		int j,p,s,k;scanf("%d%d%d%d",&j,&p,&s,&k);
		int m=0;
		int jp[10][10];
		int js[10][10];
		int sp[10][10];
		for (int i=0;i<10;i++)
			for (int t=0;t<10;t++)
			{
				jp[i][t]=js[i][t]=sp[i][t]=0;
			}
		for (int i=0;i<j*p*s;i++)
		{
			int j0=i%j,p0=(i/j)%p,s0=i/(j*p);
			if (jp[j0][p0]<k && js[j0][s0]<k && sp[s0][p0]<k)
			{
				jp[j0][p0]++;
				js[j0][s0]++;
				sp[s0][p0]++;
				m++;
			}
		}
		printf("Case #%d: %d\n",cs,m);
		for (int i=0;i<10;i++)
			for (int t=0;t<10;t++)
			{
				jp[i][t]=js[i][t]=sp[i][t]=0;
			}
		for (int i=0;i<j*p*s;i++)
		{
			int j0=i%j,p0=(i/j)%p,s0=i/(j*p);
			if (jp[j0][p0]<k && js[j0][s0]<k && sp[s0][p0]<k)
			{
				jp[j0][p0]++;
				js[j0][s0]++;
				sp[s0][p0]++;
				printf("%d %d %d\n",j0+1,p0+1,s0+1);
			}
		}
	}
}