#include <cstdio>
#include <cstring>


void work()
{
	int T,S,N,P;
	int cas;
	int i,re,k;
	
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		re=0;
		scanf("%d%d%d",&N,&S,&P);
		
		for (i=1;i<=N;i++)
		{
			scanf("%d",&k);
			if (k>=P*3-2)
			{				
				re++;
			}
			else if (k>=P*3-4 && P!=1)
			{
				if (S)
				{
					S--;
					re++;
				}
			}
		}
		
		
		printf("Case #%d: %d\n",cas,re);
	
	}
}

int main()
{
	//int i;
	
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	
	
	work();

	
	return 0;
}


