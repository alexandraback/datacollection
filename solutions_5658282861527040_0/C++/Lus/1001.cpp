#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#define maxn 200
using namespace std;
int t,A,B,C;

long long dp(int a,int b,int c)
{
	int ret=0;
	for(int i=0;i<a;++i)
	{
		for(int j=0;j<b;++j)
		{
			if( (i&j) <c ) ++ret;
		}
	}
	return ret;
}
int ca=1;
int main()
{
	freopen("1001.in","r",stdin);
	freopen("1001.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&A,&B,&C);
		printf("Case #%d: %d\n",ca++,dp(A,B,C));
	}
}
