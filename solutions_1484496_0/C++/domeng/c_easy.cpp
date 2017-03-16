#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int n,dt[20];
		scanf("%d",&n);
		for (int q=0;q<n;++q) scanf("%d",&dt[q]);
		printf("Case #%d:\n",kase);
		int good = 0;
		vector< pii > v;
		for (int q=1;q<(1<<n);++q)
		{
			int a;
			a=0;
			for (int w=0;w<n;++w) if (q&(1<<w)) a+=dt[w];
			v.push_back(pii(a,q));
		}
		sort(v.begin(),v.end());
		for (int q=0;q<v.size();++q)
		{
			for (int w=q+1;w<v.size();++w)
				if (v[q].first != v[w].first) break;
				else if (v[q].second & v[w].second) continue;
				else
				{
					for (int e=0;e<n;++e)
						if (v[q].second&(1<<e)) printf("%d ",dt[e]);
					printf("\n");
					for (int e=0;e<n;++e)
						if (v[w].second&(1<<e)) printf("%d ",dt[e]);
					printf("\n");
					good = 1;
					break;
				}
			if (good) break;
		}
		if (!good) printf("Impossible\n");
	}
	
	return 0;
}