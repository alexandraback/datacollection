#include <cstdio>
using namespace std;

// Main
int main(void)
{
	int tc,cs,A,B,K,a,b,ans;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		ans=0;
		scanf("%d%d%d",&A,&B,&K);
		for(a=0;a<A;a++)
			for(b=0;b<B;b++)
				if((a&b)<K) ans++;
		printf("Case #%d: %d\n",cs,ans);
	}
	return 0;
}