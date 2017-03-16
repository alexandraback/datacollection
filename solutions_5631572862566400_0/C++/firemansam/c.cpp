#include <bits/stdc++.h>
using namespace std;
int n, tcs, nms[1005], bc[1005];
vector<int> rev[1005];
bool visited[1005];
int dfs(int k, int org){
	if(visited[k]) return -1;
	visited[k] = 1;
	if(nms[k] == org) return 1;
	int next = dfs(nms[k], org);
	if(next == -1) return next;
	else return next + 1;
}

int rvs(int k, int avd){
	if(rev[k].size() == 0) return 1;
	int xm = 0;
	for(int i=0;i<rev[k].size();i++){
		if(rev[k][i] == avd) continue;
		xm = max(xm, rvs(rev[k][i], avd));
	}
	return xm+1;
}

int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i", &n);
		for(int i=1;i<=n;i++){
			rev[i].clear();
		}
		for(int i=1;i<=n;i++){
			scanf("%i", &nms[i]);
			rev[nms[i]].push_back(i);
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			memset(visited, 0, sizeof visited);
			bc[i] = dfs(i, i);
			ans = max(ans, bc[i]);
		}
		int ans2 = 0;
		memset(visited, 0, sizeof visited);
		for(int i=1;i<=n;i++){
			if(bc[i] == 2) {
				if(visited[i]) continue;
				visited[i] = 1;
				visited[nms[i]] = 1;
				ans2 += max(ans, rvs(i, nms[i]) + rvs(nms[i], i));
			}
		}
		ans = max(ans, ans2);
		printf("Case #%i: %i\n", tc, ans);
	}
}