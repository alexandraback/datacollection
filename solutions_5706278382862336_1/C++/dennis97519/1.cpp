#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	cin>>T;
	for (int TT=1;TT<=T;++TT)
	{
		long long x,y;
		scanf("%lld/%lld",&x,&y);
		printf("Case #%d: ",TT);
			int cnt=0,ans=-1;
			while (cnt<=40&&x!=0)
			{
				x*=2;
				++cnt;
				if (x>=y) {x-=y;if (ans==-1) ans=cnt;}
			}
			if (cnt>40) printf("impossible\n");
			else printf("%d\n",ans);
	}
}
