#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	freopen("A-small-1.in", "r", stdin);
	freopen("A-small-1.out", "w", stdout);
	int t, n, x, m;
	bool flag;
	vector< vector<int> > g;
	vector<bool> used;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%d", &n);
		g.resize(n);
		used.resize(n);
		for(int j=0;j<n;j++)
				g[j].resize(0);
		for(int j=0;j<n;j++){
			scanf("%d", &m);
			for(int k=0;k<m;k++){
				scanf("%d", &x);
				g[j].push_back(x-1);
				}
			}
		for(int j=0;j<n;j++){
			queue<int> q;
			flag = false;
			for(int k=0;k<n;k++)
				used[k] = 0;
			q.push(j);
			used[j] = true;
			while(!q.empty()){
				int v = q.front();
				q.pop();
				for(int k=0;k<g[v].size();k++){
					if(used[g[v][k]]){
						flag = true;
						break;
						}
					else{
						used[g[v][k]] = true;
						q.push(g[v][k]);
						}
					if(flag) break;
					}
				if(flag) break;
				}
			if(flag) break;
			}
		printf("Case #%d: ", i+1);
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
		}
	return 0;
	}
