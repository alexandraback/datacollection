#include <cstdio>
#include <algorithm>
#include <cstring>
#define Sort sort

using namespace std;

const int Maxn=1200;

pair <int,int> p[Maxn];
bool vis1[Maxn],vis2[Maxn];
int n,m,Test;

int main()
{
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	
	scanf("%d",&Test);
	for (int ii=1;ii<=Test;++ii)
	{
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d%d",&p[i].second,&p[i].first);
		Sort(p,p+n);
		
		memset(vis1,false,sizeof(vis1));
		memset(vis2,false,sizeof(vis2));
		int star=0;
		int res=0;
		bool flag=true;
		int cnt=0;
		for (;cnt<n;)
		{
			int t=-1;
			for (int i=0;i<n;++i)
				if (!vis2[i] && star>=p[i].first)
				{
					t=i;break;
				}
			if (t!=-1)
			{
				if (vis1[t]) ++star;
				else star+=2;
				vis2[t]=true;
				++res;
				++cnt;
				continue;
			}
			for (int i=n-1;i>=0;--i)
				if (!vis1[i] && !vis2[i] && star>=p[i].second)
				{
					t=i;break;
				}
			if (t==-1) { flag=false;break; }
			++res;++star;vis1[t]=true;
		}
		
		printf("Case #%d: ",ii);
		if (flag) printf("%d\n",res);
		else printf("Too Bad\n");
	}
	
	return 0;
}