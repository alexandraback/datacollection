#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int game=0;
	LL ans=0;
	int n;
	LL r,t;
	scanf("%d",&n);
	while(n--)
	{
		game++;
		scanf("%lld%lld",&r,&t);
		LL sum;
		ans=0;
		while(1)
		{
			sum=(r+1)*(r+1)-(r*r);
			if(t>=sum)
			{
				ans++;
				t-=sum;
				r+=2;
			}
			else break;
			
		}
		printf("Case #%d: %lld\n",game,ans);
	}
	return 0;
}
