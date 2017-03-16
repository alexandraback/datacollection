#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int T;
int n;
queue<int> bfs;

int main(){
	freopen("q1.in", "r", stdin);
	freopen("q1.out", "w", stdout);
	scanf("%d", &T);
	for(int trololo = 1; trololo <= T; trololo++){
		bool seen[1005];
		bool pos = false;
		vector<int> adjlist[1005];
		scanf("%d", &n);
		int tmp, ntmp;
		for(int i = 1; i <= n; i++){
			seen[i] = false;
			scanf("%d", &tmp);
			for(int j = 0; j < tmp; j++){
				scanf("%d", &ntmp);
				adjlist[i].push_back(ntmp);
			}
		}
		for(int i = 1; i <= n; i++){
			bfs.push(i);
			seen[i] = true;
			while(!bfs.empty()){
				int cur = bfs.front(); bfs.pop();
			//	printf("Cur is %d\n", cur);
				for(int j = 0; j < adjlist[cur].size(); j++){
				//	printf("here %d %d %d\n", adjlist[cur][j], cur, adjlist[cur].size());
					if(seen[adjlist[cur][j]] && adjlist[cur][j] != i){
						pos = true;
						break;
					}
					else if(!seen[adjlist[cur][j]]){
						seen[adjlist[cur][j]] = true;
						bfs.push(adjlist[cur][j]);
					}
				}
			}
			if(pos) break;
			for(int j = 1; j <= n; j++){
				seen[j] = false;
			}			
		}
		if(pos){
			printf("Case #%d: Yes\n", trololo);
		}
		else printf("Case #%d: No\n", trololo);
	}
	return 0;
}
			
		
