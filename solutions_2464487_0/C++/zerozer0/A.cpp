#include <stdio.h>
int main()
{
	int t,T,test=0,i,tmp,r;
//	freopen("A-small-attempt0.in","r",stdin);
//	freopen("As.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&r,&t);
		i=1;
		while(1)
		{
			tmp=2*r*i+(2*i-1)*i;
			if(tmp>t)
				break;
			i++;
		}
		printf("Case #%d: %d\n",++test,i-1);
	}

	return 0;
}