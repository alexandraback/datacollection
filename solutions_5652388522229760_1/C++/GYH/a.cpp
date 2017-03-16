#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL; 
typedef long long LL;
ULL vis ;

void gao(LL n)
{
	while(n)
	{
		vis |= 1ULL << (n%10);
		n /= 10;
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("ansA.txt","w",stdout);
	LL n;
	int T = 100;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		vis = 0;
		scanf("%lld",&n);
		printf("Case #%d: ",z);
		if(n == 0) 
			puts("INSOMNIA");
		else
		{
			int cnt = 0;
			LL m = n;
			while(cnt < 2333)
			{
				++cnt;
				gao(n);
				if (vis == (1ULL << 10) -1) break;
				n += m;
			}
			if(cnt >= 2333)
				puts("INSOMNIA");
			else
				printf("%lld\n",n);
		}
	}
	return 0;
}
