#include <stdio.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <string>

using namespace std;

struct T
{
	int s;
	int m;
}v[(1<<20)+10];

bool operator <(T t1,T t2)
{
	return t1.s<t2.s;
}

int TT,ts,i,j,m1,m2,m,n,ok;
int a[30];

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<(1<<n);i++)
		{
			v[i].s=0;
			for(j=0;j<n;j++)
				if(i&(1<<j))
					v[i].s+=a[j];
			v[i].m=i;
		}
		sort(v,v+(1<<n));
		for(i=1;i<(1<<n);i++)
			if(v[i].s==v[i-1].s)
				break;
		printf("Case #%d:\n",++ts);
		if(i==(1<<n))
		{
			printf("Impossible\n");
			continue;
		}
		m1=v[i-1].m;
		m2=v[i].m;
		m=m1&m2;
		m1^=m;
		m2^=m;
		ok=0;
		for(j=0;j<n;j++)
			if(m1&(1<<j))
			{
				if(ok)
					printf(" ");
				ok=1;
				printf("%d",a[j]);
			}
		printf("\n");
		ok=0;
		for(j=0;j<n;j++)
			if(m2&(1<<j))
			{
				if(ok)
					printf(" ");
				ok=1;
				printf("%d",a[j]);
			}
		printf("\n");
	}
	return 0;
}