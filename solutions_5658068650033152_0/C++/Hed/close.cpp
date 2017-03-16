#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for (int i = a;i <= b;i ++)

using namespace std;

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
int T,N,M,K,ans;
bool bz[25][25],map[25][25];

void Floodfill(int x,int y)
{
	bz[x][y] = 1;
	fo(i,0,3)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx <= N+1 && yy <= M+1)
			if (!map[xx][yy] && !bz[xx][yy]) Floodfill(xx,yy);
	}
}

void dfs(int x,int y,int tot)
{
	if (tot >= ans) return;
	if (x > N)
	{
		fo(i,0,N+1) fo(j,0,M+1) bz[i][j] = 0;
		Floodfill(0,0);
		int cnt = 0;
		fo(i,1,N) fo(j,1,M) cnt += (bz[i][j] != 1);
		if (cnt >= K) ans = tot;
		return;
	}
	map[x][y] = 1;
	if (y == M) dfs(x+1,1,tot+1); else dfs(x,y+1,tot+1);
	map[x][y] = 0;
	if (y == M) dfs(x+1,1,tot); else dfs(x,y+1,tot);
}

int main()
{
	freopen("close.in","r",stdin);
	freopen("close.out","w",stdout);
	scanf("%d",&T);
	fo(cs,1,T)
	{
		scanf("%d%d%d",&N,&M,&K);
		ans = N*M;
		memset(map,0,sizeof map);
		dfs(1,1,0);
		printf("Case #%d: %d\n",cs,ans);
	}
	return 0;
}
