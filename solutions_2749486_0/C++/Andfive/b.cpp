#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

struct point
{
	int x,y;
	void input()
	{
		scanf("%d%d",&x,&y);
	}
}kk;

int main ()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int cas;
	scanf("%d",&cas);
	for(int ii=1;ii<=cas;++ii)
	{
		kk.input();
		printf("Case #%d: ",ii);

		if(kk.x>0)
		{
			for(int i=0;i<kk.x;++i)
				printf("WE");
		}
		else
		{
			for(int i=0;i>kk.x;--i)
				printf("EW");
		}

		if(kk.y>0)
		{
			for(int i=0;i<kk.y;++i)
				printf("SN");
		}
		else
		{
			for(int i=0;i>kk.y;--i)
				printf("NS");
		}

		puts("");
	}
	return 0;
}


