#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >
#define MAX 10000000

vector < LL > nums;
bool ispalin(LL x)
{
	string str;
	while(x)
	{
		str+='0'+x%10;
		x/=10;
	}
	string strr=str;
	reverse(strr.begin(),strr.end());
	return str==strr;

}

void precompute(void)
{
	LL i;
	for(i=1;i<=MAX;i++)
	{
		if(ispalin(i)&&ispalin(i*i))
		{
			nums.PB(i*i);
	//		printf("%lld %lld\n",i,i*i);
		}
	}
}

int main()
{
	long long t,ans,kase,A,B;
	precompute();
	while(scanf("%lld",&t)!=EOF)
	{
		kase=1;
		while(t--)
		{
			scanf("%lld %lld",&A,&B);
			ans=upper_bound(nums.begin(),nums.end(),B)-lower_bound(nums.begin(),nums.end(),A);
			printf("Case #%lld: %lld\n",kase,ans);
			kase++;
		}
	}
	return 0;
}
