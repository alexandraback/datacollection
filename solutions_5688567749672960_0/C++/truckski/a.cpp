#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

long long ans[1010101]={0,1LL};

long long rev(long long n)
{
	long long ret=0, N=n;
	while(N)
	{
		ret*=10;
		ret+=N%10;
		N/=10;
	}
	return ret;
}

void build(int n)
{
	for(int i=2;i<=n; i++) ans[i]=1010101;
	for(int i=1;i<n; i++)
	{
		ans[i+1]=min(ans[i]+1,ans[i+1]);
		int r=rev(i);
		if(r>i&&r<=n) ans[r]=min(ans[r],ans[i]+1);
	}
}

void solve()
{
	int n;
	scanf("%d",&n);
	printf("%lld\n",ans[n]);
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	build(1000000);
	for(int i=1; i<=ncases; i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
