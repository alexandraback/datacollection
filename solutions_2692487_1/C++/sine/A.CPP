#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *p1, const void *p2)
{
	return *(int *)p1 - *(int *)p2;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("l'.out", "w", stdout);

	int t, cas;
	__int64 a;
	int n, i;
	int mote[105];
	int add[105];
	int res;
	
	scanf("%d", &t);
	for(cas=1; cas<=t; cas++)
	{
		scanf("%I64d%d", &a, &n);
		for(i=0; i<n; i++)
			scanf("%d", mote+i);
		res=n;
		qsort(mote, n, sizeof(int), cmp);
		memset(add, 0, sizeof(add));
		if(a!=1)
		{
			for(i=0; i<n; )
			{
				if(a>mote[i])
				{
					a+=mote[i];
					i++;
				}
				else
				{
					a+=a-1;
					add[i]++;
				}
			}
			for(i=1; i<n; i++)
				add[i]+=add[i-1];
			if(add[n-1]==0) res=0;
			else
			{
				for(i=0; i<n; i++)
					if(add[i]+n-1-i<res) res=add[i]+n-1-i;
			}
		}
		
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}