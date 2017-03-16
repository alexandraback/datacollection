#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	int turn=1;
	while(turn<=t)
	{
		double c,f,x;
		double prev,tot,ans;
		int i=0,j=0;
		double mul=2;
		scanf("%lf %lf %lf",&c,&f,&x);
		prev=x/mul;
		tot=(c/mul)+(x/(mul+f));
		mul+=f;
		while(tot<=prev)
		{
			prev=tot;
			double t1=c/mul;
			double t2=x/mul;
			mul+=f;
			tot=prev-t2+t1+x/mul;
		}
		ans=prev;
		printf("Case #%d: ",turn);
		printf("%.7lf\n", ans);
		turn++;
	}

	return 0;
}
