#include<stdio.h>
#include<algorithm>
using namespace std;
int num[3333];
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int c, sc = 0;
	for(scanf("%d",&c); c; --c)
	{
		int l1 = 0, l2 = 0, n, s, p;
		scanf("%d%d%d",&n, &s, &p);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d",&num[i]);
			if(num[i] >= 3*p-2) 
				++l1;
			else if(num[i] >= max(2,3*p-4))
				++l2;
		}
		printf("Case #%d: %d\n",++sc,l1+min(l2,s));
	}
	return 0;
}
