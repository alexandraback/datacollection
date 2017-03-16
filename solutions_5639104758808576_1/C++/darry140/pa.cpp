#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
char ar[1003];
int sol()
{
	int ret=0,sum=0;
	for(int i=0;i<=n;i++)
	{
		if(sum<i)
		{
			ret+=(i-sum);
			sum=i;
		}
		sum+=ar[i]-'0';
	}
	return ret;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		scanf("%d",&n);
		scanf("%s",ar);
		printf("Case #%d: %d\n",cas,sol());
	}
	return 0;
}
