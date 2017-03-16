#include"stdio.h"
#include"vector"
#include"set"
#include"map"
#include"assert.h"
#include"algorithm"
#include"math.h"
#include"stdlib.h"
#include"string.h"
#include"string"
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;
#define REP(i,n) for(unsigned int i=0;i<(n);i++)
#define LOOP(i,x,n) for(int i=(x);i<(n);i++)
#define ALL(v) v.begin(),v.end()
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%lld",&x)
#define ul(x) scanf("%lld",&x)
char inp[1000005];
int dp[1000005];
int vowel(char c)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return 1;	//vowel
	else
		return 0;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int test,n,l,k=-1,index=0,res;
	scanf("%d",&test);
	for(int tes=1;tes<=test;tes++)
	{
		k=-100000000;
		index=0;
		scanf("%s%d",inp,&n);
		l=strlen(inp);
		for(int i=0;i<=l;i++)
			dp[i]=0;
		for(int i=1;i<=l;i++)
		{
			res=vowel(inp[i-1]);
			if(res==1)		//char is vowel
			{
				dp[i]=max(dp[i-1],dp[i-1]+k-(n-1));
				index=0;
			}
			else
			{
				index++;
				if(index==n)
				{
					dp[i]=max(dp[i],dp[i-1]+i-n+1);
					index=n-1;
					k=i;
				}
				else
					dp[i]=max(dp[i],dp[i-1]+k-(n-1));
			}
		}
		printf("Case #%d: %d\n",tes,dp[l]);
	}
	return 0;
}