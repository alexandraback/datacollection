#include<cstdio>
#include<cassert>
using namespace std;
typedef long long LL;
int N,J;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int testcount;scanf("%d",&testcount);
	while(testcount--)
	{
		static int kase=0;
		printf("Case #%d:\n",++kase);
		scanf("%d%d",&N,&J);
		if(N==16)assert(J==50);
		else if(N==32)assert(J==500);
		else assert(0);
		assert(J<=(1<<(N/2-2)));
		for(int n=0;n<J;++n)
		{
			for(int type=0;type<2;++type)
			{
				putchar('1');
				for(int i=N/2-3;i>=0;--i)putchar('0'+((n>>i)&1));
				putchar('1');
			}
			for(int d=2;d<=10;d++)
			{
				LL ans=1LL;
				for(int i=0;i<N/2;++i)ans*=d;
				ans++;
				printf(" %lld",ans);
			}
			puts("");
		}
	}
	return 0;
}
