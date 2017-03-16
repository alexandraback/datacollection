#include <cstdio>
#include <bitset>
using namespace std;
int tcs, x, y, graph[105][105], dx[]={-1, 0, 1, 0}, dy[]={0, -1, 0, 1};
bool ended;
bitset<5> hit;
bool dfs(int cx, int cy, int cd, int val){
	int nx = cx + dx[cd], ny = cy + dy[cd];
	if(nx < 0 || nx >= x || ny < 0 || ny >= y) return false;
	if(graph[nx][ny] > val) return true;
	return dfs(nx, ny, cd, val);
}
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		ended = 0;
		scanf("%i%i", &x, &y);
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				scanf("%i", &graph[i][j]);
			}
		}
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				hit.reset();
				for(int cd=0;cd<4;cd++){
					hit[cd] = dfs(i, j, cd, graph[i][j]);
					if((hit[0] || hit[2]) && (hit[1] || hit[3])) {ended = 1; break;}
				}
			}
			if(ended) break;
		}
		printf("Case #%i: ", tc);
		if(ended) printf("NO\n");
		else printf("YES\n");
	}
}