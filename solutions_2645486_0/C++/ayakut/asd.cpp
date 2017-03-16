#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long big;
big E,R,N;
big ar[102000];
big dp[123][123];
int solve(int k,int e)
{
	if(k==N+1) return 0;
	e=min(e,(int)E);
	int i;
	int res=0;
	for(i=0;i<=e;i++)
	{
		res=max(res,(int)(i*ar[k]+solve(k+1,e-i+R)));
	}
	return res;
}
int main()
{
	int i;
	double ss;
	int Test,tt;
	int bs,sn;
	big ort;
	double a,b,c,mm;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++)
	{
		printf("Case #%d: ",tt);
		scanf(" %lld %lld %lld",&E,&R,&N);
		for(i=1;i<=N;i++) scanf(" %lld",&ar[i]);

		printf("%d\n",solve(1,E));
	}	 
	return 0;
}