#include <stdio.h>
int main()
{
	int t,k;
	scanf("%d",&t);
	k=t;
	while(t--)
	{
		unsigned long long int p,q,tem;
		scanf("%llu/%llu",&p,&q);
		printf("Case #%d: ",k-t);
		int c=0;
		for(tem=q;tem%2==0;tem/=2)c++;
		if(p>q)printf("impossible\n");
		else if(p%tem!=0)printf("impossible\n");
		else
		{
			p/=tem;q/=tem;
			while(p%2==0&&q%2==0)
			{
				p/=2;q/=2;c--;
			}
			int c2=0;
			while(p>1){p/=2;c2++;}
			printf("%d\n",c-c2);
		}
	}
	return 0;
}

