#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define scanf(args...) scanf(args) ? : 0
using namespace std;
const int MAX=112;
void solve()
{
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	int w=0;
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			if((i&j)<k)
				w++;
	printf("%d\n",w);
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