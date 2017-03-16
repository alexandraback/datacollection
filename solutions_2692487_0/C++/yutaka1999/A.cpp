#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105
#define INF 100000000

using namespace std;
typedef long long int ll;

int in[SIZE];
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		ll a;
		int n;
		scanf("%lld %d",&a,&n);
		memset(in,0,sizeof(in));
		for(int i=0;i<n;i++) scanf("%d",&in[i]);
		sort(in,in+n);
		ll ret=n,move=0;
		for(int i=0;i<n;i++)
		{
			if(in[i]>=a)
			{
				if(a==1) break;
				int diff=in[i]-a+1;
				while(move<=ret&&a<=in[i])
				{
					a+=a-1;
					move++;
				}
			}
			a+=in[i];
			if(move>=ret) break;
			ret=min(ret,move+(n-i-1));
		}
		printf("Case #%d: %lld\n",t,ret);
	}
	return 0;
}
