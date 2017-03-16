
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int tt;
int n;
int g[1010];
int in[1010];
int ans;
int f1[1010],f2[1010];
int dist[1010];

void dfs(int x) {
	for (int i=0;i<n;++i)
		f1[i]=0;

	int st=x;
	int cur=1;
	while (f1[x]==0) {
		f1[x]=cur;
		cur++;
		x=g[x];
	}

	cur--;
	if (f1[x]==1) ans=max(ans,cur);
}

void work() {
	memset(dist,0,sizeof(dist));
	memset(f1,0,sizeof(f1));
	while (1) {
		int cur=-1;
		for (int i=0;i<n;++i)
			if (f1[i]==0 && in[i]==0) cur=i;
		if (cur==-1) break;
		f1[cur]=1;
		dist[g[cur]]=max(dist[g[cur]],dist[cur]+1);
		in[g[cur]]--;
	}

	int res=0;
	vector<int> tmp;
	for (int i=0;i<n;++i)
		if (g[g[i]]==i) res+=dist[i]+1;

	ans=max(ans,res);
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		printf("Case #%d: ",ii);
		scanf("%d",&n);
		memset(in,0,sizeof(in));
		for (int i=0;i<n;++i) {
			scanf("%d",&g[i]);
			g[i]--;
			in[g[i]]++;
		}

		ans=0;
		for (int i=0;i<n;++i) dfs(i);
		work();

		printf("%d\n",ans);
	}
}