#include <stdio.h>

void main(int argc, char **argv)
{
	int T;
	scanf("%d",&T);
	int i;
	for(i=1;i<=T;i++)
	{
		int n,s,p,j,aw=0,us;
		scanf("%d%d%d",&n,&s,&p);
		for(j=0;j<n;j++)
		{
			int avg,sco,sco2,m0,m1;
			scanf("%d",&sco);
			avg = sco / 3;
			sco2 = avg * 3;
			m0 = avg + (sco > sco2);
			m1 = m0 + (sco && sco - sco2 != 1);
			//fprintf(stderr,"\n-- p %d s %d sco %d avg %d sco2 %d m0 %d m1 %d ", p, s, sco, avg, sco2, m0, m1);
			if (sco - sco2 != 1 && m1 == p && s > 0)
			{
				//fprintf(stderr," !");
				aw++;
				s--;
			}
			else if (m0 >= p)
			{
				//fprintf(stderr," ?");
				aw++;
			}
			//fprintf(stderr,"\n");
		}
		printf("Case #%d: %d\n",i,aw);
	}
}
