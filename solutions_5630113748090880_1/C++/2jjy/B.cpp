#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
int tct[2501];
void task()
{
	int n;scanf("%d",&n);
	memset(tct,0,sizeof tct);
	rep(i,2*n-1)
	{
		rep(j,n)
		{
			int ta;
			scanf("%d",&ta);
			tct[ta]++;
		}
	}
	rep(i,2500)
	{
		if(tct[i]&1)
		{
			printf(" %d",i);
		}
	}
	printf("\n");
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int nt;scanf("%d",&nt);
	rep(i,nt)
	{
		printf("Case #%d:",i);
		task();
	}
}
	
