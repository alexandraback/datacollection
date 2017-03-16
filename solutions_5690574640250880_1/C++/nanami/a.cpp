#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 55;
int r,c,m,ca,a[maxn];
bool flag,used[maxn][maxn];
char f[maxn][maxn];
void print()
{
	for(int i = 1; i <= r; ++i){
		for(int j = 1; j <= c; ++j) printf("%c",f[i][j]);
		printf("\n");
	}
}
bool check()
{
	for(int i = 1; i <= r; ++i){
		for(int j = 1; j <= a[i]; ++j) f[i][j] = '*';
		for(int j = a[i] + 1; j <= c; ++j) f[i][j] = '.';
	}
	f[r][c] = 'c';
	queue<int> qx,qy;
	qx.push(r);
	qy.push(c);
	memset(used,0,sizeof(used));
	used[r][c] = 1;
	int cnt = 0;
	while(!qx.empty()){
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		++cnt;
		bool mark = 1;
		for(int dx = -1; dx <= 1; ++dx)
			for(int dy = -1; dy <= 1; ++dy){
				int nx = x + dx,ny = y + dy;
				if(1 <= nx && nx <= r && 1 <= ny && ny <= c && f[nx][ny] == '*')
					mark = 0;
			}
		if(mark == 0) continue;
		for(int dx = -1; dx <= 1; ++dx)
			for(int dy = -1; dy <= 1; ++dy){
				int nx = x + dx,ny = y + dy;
				if(1 <= nx && nx <= r && 1 <= ny && ny <= c && !used[nx][ny]){
					qx.push(nx);
					qy.push(ny);
					used[nx][ny] = 1;
				}
			}
	}
	if(cnt == r * c - m) return true;
	else return false;
}
void dfs(int x,int y)
{
	if(y == 0 || x > r){
		if(check()) flag = 1;
		return;
	}
	if(a[x - 1] * (r - x + 1) < y) return;
	int tmp = min(y,a[x - 1]);
	for(int i = tmp; i >= 0; --i){
		a[x] = i;
		dfs(x + 1,y - i);
		if(flag) return;
		a[x] = 0;
	}
}
void solve()
{
	memset(a,0,sizeof(a));
	a[0] = c;
	flag = 0;
	dfs(1,m);
	printf("Case #%d:\n",++ca);
	if(flag) print();
	else puts("Impossible");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&r,&c,&m);
		solve();
	}
	return 0;
}

