#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
struct node
{
	int a;
	int b;
	int flag;
};
bool comp1(node one, node two)
{
	if(one.a == two.a)
		return one.b>two.b;
	else
		return one.a<two.a;
}
bool comp2(node one, node two)
{
	if (one.b == two.b)
		return one.flag < two.flag;
	else
		return one.b<two.b;
}
int main()
{
	freopen("G://GCJ/B-small.in","r",stdin);
	freopen("G://GCJ/2.out","w",stdout);
	node level[1005];
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		memset(level,0,sizeof(level));
		int N;
		scanf("%d",&N);
		for (int j=0;j<N;j++)
		{
			scanf("%d%d",&level[j].a, &level[j].b);
		}
		int star_num=0;
		int res=0;
		while(1)
		{
			sort(level,level+N,comp2);
			if (level[0].b == 100000)
			{
				break;
			}
			if (level[0].b <= star_num)
			{
				if (level[0].flag == 0)
				{
					star_num+=2;
					level[0].a=100000;
					level[0].b=100000;
				}
				else
				{
					star_num++;
					level[0].b=100000;
				}
				res++;
				continue;
			}
			sort(level,level+N,comp1);
			if (level[0].a == 100000 || level[0].a > star_num)
			{
				res=-1;
				break;
			}
			star_num++;
			level[0].flag=1;
			level[0].a=100000;
			res++;
		}
		if(res == -1)
			printf("Case #%d: Too Bad\n",i+1);
		else
			printf("Case #%d: %d\n",i+1,res);
	}	
	return 0;
}