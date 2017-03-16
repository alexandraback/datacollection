#include<cstdio>
#include<algorithm>

using namespace std;

int cnt[2048];

int f(int x, int _max)
{
	int ret=x;
	for(int i = x+1; i <= _max; i++)
	{
		ret+=cnt[i]*((i-1)/x);
	}
	return ret;
}

int solve()
{
	int D, ans=0x7FFFFFFF, _max=0;
	for(int i = 0; i < 2048; i++)
		cnt[i]=0;
	scanf("%d",&D);
	for(int i = 0; i < D; i++)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
		_max=max(_max,x);
	}
	for(int i = 1; i<=_max; i++)
	{
//		printf("i=%d f(i)=%d\n",i,f(i,_max));
		ans=min(ans,f(i,_max));
	}
	return ans;
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	for(int i = 1; i <= ncases; i++)
		printf("Case #%d: %d\n",i,solve());
	return 0;
}
