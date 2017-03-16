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


#define PB push_back
#define MP make_pair

const int maxn=11000,maxm=1100000,inf=0x3f3f3f3f;
const double pi=2.0*asin(1.0),eps=1e-8;

long long v[maxn],a[maxn];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	long long t,ca=1,i,j,x,r,e,n,ans,now;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&e,&r,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&v[i]);
		}
		a[1]=e;
		for(i=2;i<=n;i++)
		{
			a[i]=r;
			now=r;
			for(j=i-1;j>0&&v[j]<v[i]&&now<e;j--)
			{
				x=min(e-now,a[j]);
				a[i]+=x;
				a[j]-=x;
				now+=x;
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=a[i]*v[i];
		}
		printf("Case #%lld: %lld\n",ca++,ans);
	}
}
