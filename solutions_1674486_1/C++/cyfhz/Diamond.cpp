#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#include <set>
using namespace  std;
vector<vector<int> >map;
vector<vector<int> >fmap;
int n;
int h[1100];
bool bfs(int v)
{
	queue<int> Q;
	Q.push(v);
	h[v] = 1;
	while(!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for(int i = 0 ; i < map[cur].size(); i ++) {
			int next = map[cur][i];
			if(h[next] == 1)
				 return true;
			else {
				Q.push(next);
				h[next] = 1;
			}
		}
	}
	return false;
	
}
void Diamond ()
{
	freopen("./A-large.in", "r", stdin);
	freopen("./A-large.out", "w", stdout);
	int t, i, j, k, cas = 0, m, v;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		map.clear();
		fmap.clear();
		map.resize(n + 10);
		fmap.resize(n + 10);
		for(i = 1; i <= n; i ++)
			fmap[i].clear();
		for(i = 0; i < n; i ++) {
			scanf("%d", &m);
			map[i+1].clear();
			for(j = 0; j < m; j ++) {
				scanf("%d", &v);
				map[i+1].push_back(v);
				fmap[v].push_back(i + 1);
			}
		}
		for(i = 1; i <= n; i ++) {
			if(map[i].size() > 1 && fmap[i].size() == 0) {
				memset(h, 0, sizeof(h));
				if(bfs(i))
					break;
			}
		}
		printf("Case #%d: ", ++cas);
		if(i <= n)
			printf("Yes\n");
		else printf("No\n");
	}
}


 int main() {
 // 	int T;
 // 	scanf("%d", &T);
 // 	for (int t = 1; t <= T; t++) {
 // 		int n, m, ans = 0;
 // 		scanf("%d %d", &n, &m);
 // 		ans = solve(n, m);
 // 		printf("Case #%d: %d\n", t, ans);
 // 	}
 	Diamond();
 	return 0;
 }
