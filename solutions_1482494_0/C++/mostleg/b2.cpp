#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct _level
{
	int a,b,sol;	
}S_level;

S_level tar[2048];

void swap(int p, int q)
{
	if (p == q)
		return;
	S_level tmp = tar[p];
	tar[p] = tar[q];
	tar[q] = tmp;
}

void work()
{
	int T,N;
	int cas;
	int i,l;
	int star,re,big;
	int suc;
	
	scanf("%d",&T);
	
	for (cas=1;cas<=T;cas++)
	{
		scanf("%d",&N);
		for (i=0;i<N;i++)
		{
			scanf("%d%d",&tar[i].a,&tar[i].b);				
			tar[i].sol = 0;
		}
		
		star = 0;		
		re = 0;
		while (N)
		{
			suc = 0;
			for (i=0;i<N;i++)
			{				
				if (star >= tar[i].b)
				{
					if (tar[i].sol)
					{
						star += 1;
					}
					else
					{
						star += 2;
					}					
					re++;
					suc = 1;
					swap(i,N-1);
					N--;
					//printf("%d(%d), star=%d\n", tar[i].id, tar[i].value, star);
				}				
			}
			if (suc)
				continue;
			suc = 0;
			big = -1;
			l = -1;
			for (i=0;i<N;i++)
			{				
				if (tar[i].sol)
					continue;
				if (tar[i].a <= star)
				{
					if (big < tar[i].b)
					{
						big = tar[i].b;
						l = i;
					}
					suc = 1;
				}
			}
			if (!suc)
			{
				break;
			}
			star+=1;
			re++;
			tar[l].sol=1;
		}
		if (N)
		{
			printf("Case #%d: %s\n",cas,"Too Bad");
		}
		else
		{
			printf("Case #%d: %d\n",cas,re);
		}
	}
}

int main()
{
	//int i;
	
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.std","w",stdout);
	//freopen("B-large.in","r",stdin);
	//freopen("B-large.out","w",stdout);
	
	work();

	
	return 0;
}
