#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define LL long long
LL r,t;
LL f(LL n)
{
	return n*(2*n+2*r-1);
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("AA.txt","w",stdout);
	int n,m;
	int i,j,k;
	int cas=0,T;
	cin>>T;
	while(T--)
	{
		int ans=0;
		cas++;
		
		scanf("%lld%lld",&r,&t);
		
		k=3;
		LL l=1,rr=sqrt(double(t/2)),mid;
		rr=min(rr,t/r/2);
		while(l<rr)
		{
			mid=(l+rr+1)/2;
			if(f(mid)>0&&f(mid)<=t)
				l=mid;
			else
				rr=mid-1;
		}
		
		printf("Case #%d: %lld\n",cas,l);
	}
	return 0;	
}
