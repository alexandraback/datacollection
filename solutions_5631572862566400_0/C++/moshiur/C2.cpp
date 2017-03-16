#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

#define SIZE 1005

int bff[SIZE];
int N;

vector<int> adj[SIZE];

void dfs(int u, vector<int>& nodes, bool seen[]) {
	if (seen[u]) return;
	nodes.push_back(u);
	seen[u]=true;
	for (int i=0;i<adj[u].size();++i) {
		int v=adj[u][i];
		dfs(v,nodes, seen);
	}
}

vector<int> findCycle(const vector<int>& nodes) {
	bool removed[SIZE]; memset(removed, 0, sizeof(removed));
	int in[SIZE]; memset(in, 0, sizeof(in));

	for (int i=0;i<nodes.size();++i){
		int u=nodes[i]; in[bff[u]]++;
	}

	while(1){
		bool found=false;
		for(int i=0;i<nodes.size();++i){
			int u=nodes[i];
			if (!removed[u] && in[u]==0){
				found=true;
				in[bff[u]]--;
				removed[u]=true;
			}
		}
		if(!found) break;
	}
	vector<int> ret;
	for(int i=0;i<nodes.size();++i){
		int u=nodes[i];
		if (!removed[u]) ret.push_back(u);
	}

	return ret;
}

int findExtensions(const vector<int>& nodes, const vector<int>& cycle) {
	if(nodes.size() == cycle.size()) return 0;

	bool removed[SIZE]; memset(removed, 0, sizeof(removed));
	int in[SIZE]; memset(in, 0, sizeof(in));

	for (int i=0;i<nodes.size();++i){
		int u=nodes[i]; in[bff[u]]++;
	}

	bool isCycle[SIZE]; memset(isCycle, 0, sizeof(isCycle));
	
	for (int i=0;i<cycle.size();++i){
		int u=cycle[i]; isCycle[u]=true;
	}
	
	int tail=0;	
	int best = -1;
	for (int i=0;i<nodes.size();++i){
		int u=nodes[i];
		if (in[u] == 0) {
			int cnt=0;
			int cur=u;
			while (!isCycle[cur]) {
				cur=bff[cur];
				++cnt;
			}
			if (cnt>tail) {
				tail=cnt; best=u;
			}
		}
	}

	while(!isCycle[best]) {
		removed[best]=true; best=bff[best];
	}

	removed[best]=true;

	int tail2=0;
	
	for (int i=0;i<nodes.size();++i){
		int u=nodes[i];
		bool valid=true;
		if (in[u] == 0) {
			int cnt=0;
			int cur=u;
			while (!isCycle[cur]) {
				if (removed[cur])valid=false;
				cur=bff[cur];
				++cnt;
			}
			if (removed[cur]) valid=false;
			if (valid) {
				if (cnt>tail2) {
					tail2=cnt;
				}
			}
		}
	}

	return tail + tail2;
}

int solve2(const vector<int>& nodes) {
	//for(int i=0;i<nodes.size(); ++i) {
		//printf("<%d>", nodes[i]);
	//}puts("");
	vector<int> cycle = findCycle(nodes);
	//printf("Cycle: "); 
	//for(int i=0;i<cycle.size(); ++i) {
		//printf("<%d>", cycle[i]);
	//}puts("");
	if (cycle.size() != 2) {
		return (int)cycle.size();
	}

	return cycle.size() + findExtensions(nodes, cycle);
}

int solve() {
	for (int u=1;u<=N;++u)adj[u].clear();
	for (int u = 1; u <= N; ++u) {
		adj[u].push_back(bff[u]);
		adj[bff[u]].push_back(u);
	}

	bool seen[SIZE];
	memset(seen, false, sizeof(seen));

	int ret=0;

	for (int u = 1; u <= N; ++u) {
		if (!seen[u]) {
			vector<int> nodes;
			dfs(u,nodes,seen);
			ret=max(ret,solve2(nodes));
		}
	}

	return ret;
}

int main() {
	int T;scanf("%d",&T);
	for (int t=1;t<=T;++t) {
		scanf("%d",&N);

		for (int u = 1; u <= N; ++u) {
			scanf("%d", &bff[u]);
		}

		printf("Case #%d: %d\n", t, solve());
	}
	return 0;
}
