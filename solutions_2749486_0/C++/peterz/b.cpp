#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define LL long long
#define EPS 1e-9
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,n)
int n, m;
int vis[202][202][600] = {0};
int p[202][202][501][4];
int a, b;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char mp[4] = {'E', 'W', 'N', 'S'};
int dfs(int x, int y, int z){
	//printf("%d %d %d\n", x, y, z);
	if (z > 500) return 0;
	if (x == a && y == b) return 1;
	FOR(i,0,4){
		int nx = x + dx[i] * (z + 1);
		int ny = y + dy[i] * (z + 1);
		if (nx > 200 || ny > 200 || nx < 0 || ny < 0) continue;
		if (vis[nx][ny][z]) continue;
		vis[nx][ny][z] = 1;
		if (dfs(nx, ny, z + 1)) return p[x][y][z][i] = 1;
		p[x][y][z][i] = 0;
	}
	return 0;
}
int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		memset(p, 0, sizeof(p));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &a, &b);
		a += 100;
		b += 100;
		vis[100][100][0] = 1;
		//printf("%d\n", dfs(100, 100, 0));
		dfs(100, 100, 0);
		printf("Case #%d: ", cc);
		int x = 100, y = 100, tmp = 0;
		while(x != a || y != b){
			FOR(i,0,4){
				if (!p[x][y][tmp][i]) continue;
				printf("%c", mp[i]);
				x += dx[i] * (tmp + 1);
				y += dy[i] * (tmp + 1);
				tmp++;
				break;
			}
		}
		puts("");
	}

	return 0;
}

