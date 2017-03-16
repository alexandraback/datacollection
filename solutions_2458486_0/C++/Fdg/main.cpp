#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

vector <vector <int> > v;
int can[202][202];
int open[202],have[202],n,init[202];
bool was[202],u[202];

vector <int> order;

void dfs(int v) {
	u[v]=true;
	for(int i=0;i<n;++i)
		if (!u[i]&&can[v][i]) dfs(i);
	order.push_back(v);
}

int comp[202];

void dfs2(int v,int col) {
	comp[v]=col;
	for(int i=0;i<n;++i)
		if (comp[i]==0&&can[i][v]) dfs2(i,col);
}

bool check() {
	memcpy(u,was,sizeof(u));
	order.clear();
	for(int i=0;i<n;++i)
		if (!u[i]) dfs(i);
	reverse(order.begin(),order.end());
	memset(comp,0,sizeof(comp));
	int color=1;
	for(int i=0;i<order.size();++i) {
		if (comp[order[i]]==0) dfs2(order[i],color++);
	}
	bool opened[202]={0};
	for(int i=0;i<order.size();++i) {
		int to=order[i];
		if (opened[comp[to]]) continue;
		bool canOpen=false;
		for(int j=0;j<n;++j)
			if (comp[j]==comp[to]&&have[open[j]]) {
				canOpen=true;
				break;
			}
		if (canOpen) {
			for(int j=0;j<n;++j)
				if (comp[j]==comp[to]) {
					have[open[j]]--; opened[comp[to]]=true;
					for(int t=0;t<v[j].size();++t)
						have[v[j][t]]++;
				}
		} else return false;
	}
	return true;
}

bool dp[1<<20];

bool check_mask() {
	memset(dp,0,sizeof(dp));
	int cmask=0;
	for(int i=0;i<n;++i)
		if (was[i]) cmask|=(1<<i);
	dp[cmask]=true;
	for(int mask=cmask;mask<(1<<n);++mask)
		if (dp[mask]) {
			for(int i=0;i<n;++i)
				if ((mask&(1<<i))==0) {
					int cnt=init[open[i]];
					for(int j=0;j<n;++j)
						if (mask&(1<<j)) {
							cnt+=can[j][open[i]];
							if (open[j]==open[i]) cnt--;
						}
					if (cnt) dp[mask|(1<<i)]=true;
				}
		}
	return dp[(1<<n)-1];
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;++test) {
		int k;
		scanf("%d%d",&k,&n);
		int keys[202]={0},a;
		for(int i=0;i<k;++i) {
			scanf("%d",&a); --a;
			keys[a]++;
		}
		memcpy(init,keys,sizeof(init));
		memset(can,0,sizeof(can));
		v.clear(); v.resize(n);
		for(int i=0;i<n;++i) {
			scanf("%d",&a); --a; open[i]=a;
			scanf("%d",&a);
			for(int j=a-1;j>=0;--j) {
				scanf("%d",&a); --a;
				v[i].push_back(a);
				can[i][a]++;
			}
		}
		vector <int> ans;
		bool used[202]={0};
		for(int i=0;i<n;++i) {
			for(int j=0;j<n;++j) {
				if (!used[j]&&keys[open[j]]) {
					memcpy(was,used,sizeof(was));
					memcpy(have,keys,sizeof(have));
					have[open[j]]--;
					for(int t=0;t<v[j].size();++t)
						have[v[j][t]]++;
					was[j]=true;
					if (check_mask()) {
						ans.push_back(j);
						used[j]=true;
						keys[open[j]]--;
						for(int t=0;t<v[j].size();++t)
							keys[v[j][t]]++;
						break;
					}
				}
			}
			if (ans.size()==i) break;
		}
		printf("Case #%d:",test);
		if (ans.size()==n) {
			for(int i=0;i<n;++i)
				printf(" %d",ans[i]+1);
			printf("\n");
		} else puts(" IMPOSSIBLE");
	}
	return 0;
}