#include<bits/stdc++.h>
using namespace std;
const int maxn=2501;
int sum[maxn];
vector<int> ans;
int main()
{
	int n,v,T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;++cas)
	{
		memset(sum,0,sizeof(sum));
		ans.clear();
		scanf("%d",&n);
		for(int i=0;i<2*n-1;++i)
			for(int j=0;j<n;++j)
			{
				scanf("%d",&v);
				++sum[v];
			}
		for(int i=1;i<=2500;++i)
			if(sum[i]&1)ans.push_back(i);
		sort(ans.begin(),ans.end());
		printf("Case #%d:",cas);
		for(int i=0;i<ans.size();++i)
			printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}
