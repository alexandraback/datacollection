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
#define INF 1000000000
ll min(ll a,ll b)
{
	if(a>b)
		return b;
	else
		return a;
}
int main()
{
	int t,n,k;
	ll A,array[100000],power[21],mini,ans,x,y,q;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld%d",&A,&n);
		mini=INF,ans=0;
		for(int j=0;j<n;j++)
			scanf("%lld",&array[j]);
		if(A==1)
		{
			printf("Case #%d: %lld\n",i,n);
			continue;
		}
		sort(array,array+n);
		for(int j=0;j<n;j++)
		{
			if(A>array[j])
				A=A+array[j];
			else
			{
				//delete it
				x=ans+n-j;
				if(x<mini)
					mini=x;
				//add sufficient
				//if(A==1)
				//	break;
				//else
				{
					while(A<=array[j])
					{
						A=A+A-1;
						ans++;
					}
					A=A+array[j];
				}
			}
		}
		mini=min(ans,mini);
		printf("Case #%d: %lld\n",i,mini);
	}
	return 0;
}