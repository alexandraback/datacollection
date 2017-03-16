#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>
#define INF 1000000007
#define EPS 0.000000001
using namespace std;

int t,i,n,a[1<<20],sum[1<<20];
int mp[1<<20];
bool l;

void write(int x,int y)
{
	printf("\n");
	int q = x & y;
	x ^= q;
	y ^= q;
	for(int i=0;i<n;i++)
		if(x & (1<<i))
			printf("%d ",a[1<<i]);
	printf("\n");
	for(int i=0;i<n;i++)
		if(y & (1<<i))
			printf("%d ",a[1<<i]);
	printf("\n");
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&t);
	for(int T=1;T<=t;T++)
	{
		printf("Case #%d:",T);
		scanf("%d",&n);
		l=true;
		for(i=0;i<(1<<n);i++)
			mp[i]=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[1<<i]);
		for(i=1;i<(1<<n);i++)
		{
			sum[i] = sum[i & (i-1)] + a[i- (i&(i-1))];
			if(mp[sum[i]])
			{
				write(mp[sum[i]],i);
				l=false;
				break;
			}
			mp[sum[i]] = i;
		}
		if(l)
			printf(" Impossible\n");
	}
	return 0;
}