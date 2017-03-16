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
int e,r,n;
int vi[10];

long long spend(int a, int left)
{
int i;
if(a==n)return 0;
left+=r;
left=min(left,e);
long long ans=0;
REP(i,0,left+1)
	{
	ans= max(ans , spend(a+1,left-i) +vi[a]*i);
	
	}
return ans;	
}

int main()
{
int test;
sn(test);int i,t=0;long long ans;

while(test--)
	{
	t++;
	sn(e);sn(r);sn(n);
	for(i=0;i<n;i++)
		sn(vi[i]);
	ans=0;
	REP(i,0,e+1)
		{
		ans = max(spend(1,e-i) + vi[0]*i,ans);
		}
	printf("Case #%d: %lld\n",t,ans);
	
	}


}
