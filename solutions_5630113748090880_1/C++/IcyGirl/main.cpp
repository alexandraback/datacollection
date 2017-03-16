#define N (1<<12)
#include <bits/stdc++.h>
using namespace std;

vector<int> res;
int T,n,x,cas,cnt[N];

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);

	for(cin>>T;T--;)
	{
		cin>>n;
		res.clear();
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<n+n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&x),cnt[x]++;
		for(int i=1;i<N;i++)
			if(cnt[i] && (cnt[i]&1)) res.push_back(i);
		sort(res.begin(),res.end());

		printf("Case #%d:",++cas);
		for(int i=0;i<res.size();i++)
			printf(" %d",res[i]);
		putchar('\n');
	}
	return 0;
}
