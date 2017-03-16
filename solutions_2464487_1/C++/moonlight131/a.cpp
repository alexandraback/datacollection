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

const int maxn=1100,maxm=1100000,inf=0x3f3f3f3f;
const double pi=2.0*asin(1.0),eps=1e-8;



int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,ca=1;
	long long ans,x,z,r,bin[maxn],i,temp;
	scanf("%d",&t);
	bin[0]=1;
	for(i=1;i<maxn;i++)bin[i]=bin[i-1]*2;
	while(t--)
	{
		scanf("%lld%lld",&r,&z);
		ans=0;
		for(i=50;i>=0;i--)
		{
			x=ans+bin[i];
			if((z-x)/(r+x-1)<x*2)continue;
			temp=(r+x-1)*x*2+x;
			if(temp<=z)ans=x;
		}
		printf("Case #%d: %lld\n",ca++,ans);
	}
}
