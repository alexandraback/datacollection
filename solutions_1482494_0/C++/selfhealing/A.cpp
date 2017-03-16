#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1005], b[1005], vst[1005];
struct Node
{
	int a,b;
}p[1005];
bool cmp(Node p1,Node p2)
{
	if(p1.b!=p2.b)
		return p1.b > p2.b;
	return p1.a < p2.a;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas=0;scanf("%d",&T);
	while(T--)
	{
		int n;scanf("%d",&n);
		memset(vst,0,sizeof(vst));
		for(int i = 0; i < n; i++)
			scanf("%d%d",&p[i].a,&p[i].b);
		sort(p,p+n,cmp);
		for(int i = 0; i < n; i++)
			a[i] = p[i].a, b[i] = p[i].b;
		int s = 0, ret = 0;
		while(1)
		{
			int ok = 0;
			for(int i = 0; i < n && !ok; i++)
				if(vst[i]==1 && b[i]<=s)
				{
					s++;
					ret++;
					vst[i] = 2;
					ok = 1;
				}
			if(ok)continue;
			for(int i = 0; i < n && !ok; i++)
				if(vst[i]==0 && b[i]<=s)
				{
					s+=2;
					ret++;
					vst[i] = 2;
					ok = 1;
				}
			if(ok)continue;
			for(int i = 0; i < n && !ok; i++)
				if(vst[i]==0 && a[i]<=s)
				{
					s++;
					ret++;
					vst[i] = 1;
					ok = 1;
				}
			if(!ok)break;
		}
		int ok = 1;
		for(int i = 0; i < n; i++)
			if(vst[i]!=2)ok = 0;
		printf("Case #%d: ",++cas);
		if(!ok)printf("Too Bad\n");
		else printf("%d\n",ret);
	}

	return 0;
}
