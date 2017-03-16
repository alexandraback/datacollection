#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<map>
#define fill(a,v) memset(a,v,sizeof(a))
#define sn(n) scanf("%d",&n)
#define REP(i,a,b) for(i=a;i<b;i++)
#define MOD 747474747
#define MAX 10001
using namespace std;
int main()
{
int test;
sn(test);
long long r1,t1,i=0,ans1,j,k,ans2;
double r,t;
double ans;
while(test--)
	{
	i++;
	scanf("%lld",&r1);
	scanf("%lld",&t1);
	r=r1;
	t=t1;
	ans = (-(2*r-1) + sqrt((2*r-1)*(2*r-1) +8*t)   )/4;
	ans1=(long long)ans;
	ans2=ans1-10;
	for(j=-10;j<10;j++)
		{
		k=ans1+j;
		if(k<=0)
			continue;
		if(k*(2*r+2*k-1)<=t)
			ans2=k;
		
		}
	
	printf("Case #%lld: %lld\n",i,ans2);
	}

return 0;

}
