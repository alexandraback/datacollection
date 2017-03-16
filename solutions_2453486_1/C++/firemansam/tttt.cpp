#include <cstdio>
using namespace std;
int n, dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, -1, -1, -1, 0, 1, 1, 1}, bl, skippy;
char graph[6][6];
bool dfs(int x, int y, int c, int cd, char ps){
	if(graph[x][y] != ps && graph[x][y] != 'T') return false;
	if(cd == 0){
		for(int i=0;i<8;i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx != 1 && ny != 1) continue;
			if(nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
			if(dfs(nx, ny, 1, i, ps)) return true;
		}
		return false;
	}else{
		int nx = x + dx[cd], ny = y+dy[cd];
		if((nx > 3 || ny > 3) && c == 3) return true;
		else dfs(nx, ny, c+1, cd, ps);
	}
}
int main(){
	scanf("%i", &n);
	for(int tc=1;tc<=n;tc++){
		bl = 0;
		skippy = 0;
		for(int i=0;i<4;i++){
			scanf("%s", &graph[i]);
			for(int j=0;j<4;j++){
				if(graph[i][j] == '.') bl++;
			}
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(i!=0&&j!=0) continue;
				if(dfs(i, j, 0, 0, 'X')) {printf("Case #%i: X won\n", tc); skippy = 1; break;}
				if(dfs(i, j, 0, 0, 'O')) {printf("Case #%i: O won\n", tc); skippy = 1; break;}
			}
			if(skippy) break;
		}
		if(!skippy) if(bl == 0) printf("Case #%i: Draw\n", tc);
		else printf("Case #%i: Game has not completed\n", tc);
	}
}