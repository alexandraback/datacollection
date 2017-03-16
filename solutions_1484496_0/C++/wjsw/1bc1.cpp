#include <stdio.h>
#include <map>
using namespace std;
int a[20],n;
void out(int i)
{
	for(int j=0;j<n;++j)if(i&(1<<j))printf("%d ",a[j]);
	putchar('\n');
}
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt)
	{
		scanf("%d",&n);
		for(int i =0;i<n;++i)
			scanf("%d",a+i);
		map<int,int> s;
		printf("Case #%d:\n",tt);
		bool p=true;
		for(int i=1;i<(1<<n);++i)
		{
			int x=0;
			for(int j=0;j<n;++j)if(i&(1<<j))
			{
				x+=a[j];
			}
			if(s.find(x)!=s.end())
			{
				out(s[x]);
				out(i);
				p=false;
				break;
			}
			else s[x]=i;
		}
		if(p)puts("Impossible");
	}
	return 0;
}
