#include <stdio.h>
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt = 1; tt <=t; ++tt)
	{
		int n,s,p,z;
		scanf("%d%d%d",&n,&s,&p);
		int r=0;
		for(int i = 0; i < n ;++i)
		{
			scanf("%d",&z);
			if(z>=p+p+p-2)
				++r;
			else if(s&&z>=p+p+p-4&&p>1)
			{
				++r,--s;
			}
		}
		printf("Case #%d: %d\n",tt,r);
	}
	return 0;
}
