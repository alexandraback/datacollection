#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int solve()
{
	int n,add=0,stars=0;
	scanf("%d",&n);
	vector<bool> used(n);
	vector<pair<int,int> > x(n);
	for (int i=0;i<n;++i)
		scanf("%d%d",&x[i].second,&x[i].first);
	sort(x.begin(),x.end());
	for (int i=0;i<n;++i)
	{
		while (stars<x[i].first)
		{
			bool f = 1;
			for (int j=n-1;j>=i;--j)
				if (!used[j] && stars>=x[j].second)
				{
					used[j] = 1;
					stars++;
					add++;
					f = 0;
					break;
				}
			if (f)
				return -1;
		}
		stars += 1 + (!used[i]);
		used[i] = 1;
	}
	return n+add;
}

int main(int argc, char* argv[])
{
	if (argc>1)
		freopen(argv[1],"r",stdin);
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;++t)
	{
		int ans = solve();
		printf("Case #%d: ",t+1);
		if (ans!=-1)
			printf("%d\n",ans);
		else
			printf("Too Bad\n");
	}
	return 0;
}
