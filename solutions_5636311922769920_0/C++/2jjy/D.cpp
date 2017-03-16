#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
int nk,nc,ns;
void task()
{
	scanf("%d%d%d",&nk,&nc,&ns);
	long long ng=1;
	assert(nk==ns);
	rep(i,nc-1)
	{
		ng*=nk;
	}
	long long tg=0;
	rep(i,ns)
	{
		tg+=ng;
		printf("%lld ",tg);
	}
	printf("\n");
}
int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int nt;scanf("%d",&nt);
	rep(i,nt)
	{
		printf("Case #%d: ",i);
		task();
	}
}
