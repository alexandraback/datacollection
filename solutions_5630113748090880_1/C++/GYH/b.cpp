#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2510;
int vis[maxn],n;
vector<int> ans;

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("ansB.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		memset(vis,0,sizeof vis);
		scanf("%d",&n);
		for(int i=0;i<2*n-1;++i)
			for(int j=0;j<n;++j)
			{
				int t;
				scanf("%d",&t);
				++vis[t];
			}
		ans.clear();
		for(int i=0;i<maxn;++i)
		{
			if(vis[i]&1)
			{
				ans.push_back(i);
			}
		}
		sort(ans.begin(),ans.end());
		printf("Case #%d:",z);
		for(int i=0;i<ans.size();++i) printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}
