#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=2.0*asin(1.0),eps=1e-12;
const int maxn=1100000,maxm=1100000,inf=0x3f3f3f3f;
#define ll long long 
long long a[maxn];
int main()
{
	ll t,i,n,x,y,now,ans,ca=1,ti;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&now,&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		printf("Case #%lld: ",ca++);
		if(now==1)
		{
			printf("%lld\n",n);
			continue;
		}
		ans=n;
		sort(a,a+n);
		ti=0;
		for(i=0;i<n;i++)
		{
			if(now>a[i])
			{
				now+=a[i];
			}
			else
			{
				while(now<=a[i])
				{
					now+=now-1;
					ti++;
				}
				now+=a[i];
			}
			ans=min(ans,ti+n-i-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

