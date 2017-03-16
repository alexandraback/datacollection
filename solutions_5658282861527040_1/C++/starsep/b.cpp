#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define scanf(args...) scanf(args) ? : 0
using namespace std;
void solve()
{
	long long a,b,k;
	scanf("%lld%lld%lld",&a,&b,&k);
	long long w=k*b;
	long long pot=1;
	for(long long i=k;i<a;i++)
	{
		w+=k;
		//while(pot<=i)pot*=2;
		//printf("POT: %lld\n",pot);
	}
	printf("%lld\n",w);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}