#include <stdio.h>
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,s,p,i,r,k,n,x;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d%d%d",&n,&s,&p);
		r=0;
		while(n--)
		{
			scanf("%d",&x);
			if(p*3-2<=x)
			{
				r++;
				continue;
			}
			if(s&&p>=2&&p*3-4<=x)
			{
				r++;
				s--;
				continue;
			}
		}
		printf("Case #%d: %d\n",k,r);
	}
	return 0;
}