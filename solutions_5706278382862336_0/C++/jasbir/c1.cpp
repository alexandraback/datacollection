#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
long long ar[50];
long long gcd(long long a,long long b)
{
	if(b==0) return a;
	if(b>a) return gcd(b,a);
	return gcd(b,a%b);
}
int main()
{
	for(int i=0;i<50;i++) ar[i]=1LL<<i;
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		int f1=0;int f2=0;
		printf("Case #%d: ",tc);
		long long p,q;
		scanf("%lld/%lld",&p,&q);
		long long g=gcd(p,q);
		p=p/g;q=q/g;
		//printf("p=%lld  q=%lld \n",p,q);
		int ans=0;
		for(int i=0;i<48;i++)
		{if(q==ar[i]) f1=1;
	
		}
		if(f1==0 || p>q)
		{
			printf("impossible\n"); continue;
		}
		for(int i=0;i<42;i++)
		{	
			p=2*p;ans++;
			if(p>=q) break;
		}
		printf("%d\n",ans);
	}
}
