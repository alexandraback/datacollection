#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 1003
using namespace std;


struct Node
{
	int num;
	int id;
};

Node level[M];
Node fuck[M];
bool flag[M];

bool cmp(Node a,Node b)
{
	return a.num<b.num;
}
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);

	int cas,n,i,j,k,t;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		memset(flag,0,sizeof(flag));
		
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&level[i].num);
			scanf("%d",&fuck[i].num);
			level[i].id = fuck[i].id = i;
		}
		
		sort(level,level+n,cmp);
		sort(fuck,fuck+n,cmp);

		int  cot = 0, ans = 0;
		j = 0;
		bool ff = false;
		
		for(i=0;i<n;)
		{
			if(ff)
				break;
			if(fuck[i].num <= cot)
			{
				ans ++;
				if(flag[fuck[i].id] )
					cot += 1;
				else 
					cot += 2;
				
				flag[fuck[i].id] = true;

				i++;
				continue;
			}

			for(;j<n;j++)
			{
				if(level[j].num <= cot && !flag[ level[j].id ])
				{
					ans ++;
					cot+= 1;
					flag[level[j].id] = true;
					break;
				}
				else
				{
					ff = true;
					break;
				}
			}

		}
		
		printf("Case #%d: ",t);
		if(ff)
			printf("Too Bad\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
