#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	long long test,r,c,wid;
	scanf("%lld",&test);
	for(long long a=1;a<=test;a++)
	{
		long long ans;
		scanf("%lld %lld %lld",&r,&c,&wid);
		ans=c/wid;
		if(c%wid!=0) ans++;
		ans=r*ans+wid-1;
		printf("Case #%lld: %lld\n",a,ans);
	}
}
