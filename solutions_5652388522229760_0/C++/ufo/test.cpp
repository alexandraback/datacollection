#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,cnt;
bool app[20];
void done(long long x)
{
	while(x)
	{
		if(!app[x%10])
		{
			app[x%10]=1;
			++cnt;
		}
		x/=10;
	}
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int t,tt;
	int i,j;
	scanf("%d",&tt);
	for(t=1;t<=tt;++t)
	{
		scanf("%lld",&n);
		memset(app,0,sizeof(app));
		cnt=0;
		for(i=1;cnt<10&&i<=100000000;++i)
			done(n*i);
		if(cnt<10)
			printf("Case #%d: INSOMNIA\n",t);
		else
			printf("Case #%d: %lld\n",t,n*(i-1));
	}
	return 0;
} 
