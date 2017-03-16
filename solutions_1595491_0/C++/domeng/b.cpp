#include <cstdio>
#include <memory.h>
using namespace std;
int Cost[31][11];
int main()
{
	memset(Cost,-1,sizeof(Cost));
	for (int q=0;q<=10;++q)
	{
		for (int w=q;w<=q+2 && w<=10;++w) for (int e=w;e<=q+2 && e<=10;++e)
		{
			int s = q + w + e;
			int z = (e-q==2);
			for (int r=e;r>=0;--r)
				if (Cost[s][r]<0 || z<Cost[s][r])
					Cost[s][r] = z;
		}
	}
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int n,k,h;
		scanf("%d %d %d",&n,&k,&h);
		int ret = 0;
		for (int q=0;q<n;++q)
		{
			int u;
			scanf("%d",&u);
			if (Cost[u][h]<0) continue;
			if (Cost[u][h]==0) ret++;
			else if (k>0)
			{
				k--;
				ret++;
			}
		}
		printf("Case #%d: %d\n",kase,ret);
	}
	return 0;
}