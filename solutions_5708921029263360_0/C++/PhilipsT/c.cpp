#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

int Out[MAXN][3],cnt,Cur[MAXN][3];
int Co[3][15][15],Apear[15][15][15],a,b,c,k,least;

bool Fal(int a,int b,int c,int k)
{
	if (Apear[a][b][c]) return 0;
	if (Co[0][a][b] == k || Co[1][a][c] == k || Co[2][b][c] == k) return 0;
	return 1;
}

void Push(int a,int b,int c)
{
	Apear[a][b][c] = 1;
	least --;
	Co[0][a][b] ++,Co[1][a][c] ++,Co[2][b][c] ++;
}

void Pop(int a,int b,int c)
{
	Apear[a][b][c] = 0;
	least ++;
	Co[0][a][b] --,Co[1][a][c] --,Co[2][b][c] --;
}

void Dfs(int x,int y,int z,int cr)
{
	if (cr > cnt)
	{
		cnt = cr;
		for(int i = 1;i <= cr;i ++) memcpy(Out[i],Cur[i],sizeof Out[i]);
	}
	if (x > a) return;
	if (y > b) {Dfs(x + 1,1,1,cr);return;}
	if (z > c) {Dfs(x,y + 1,1,cr);return;}
	Dfs(x,y,z + 1,cr);
	if (Fal(x,y,z,k))
	{
		Push(x,y,z);
		Cur[++ cr][0] = x,Cur[cr][1] = y,Cur[cr][2] = z;
		Dfs(x,y,z + 1,cr);
		Pop(x,y,z);
		cr --;
	}
}

void Solve()
{
	memset(Apear,0,sizeof Apear),memset(Co,0,sizeof Co);
	cnt = 0;
	scanf("%d%d%d%d", &a, &b, &c, &k);
	least = a * b * c;
	Dfs(1,1,1,0);
	printf("%d\n", cnt);
	for(int i = 1;i <= cnt;i ++)
		printf("%d %d %d\n", Out[i][0], Out[i][1], Out[i][2]);
}

int main()
{
	freopen("data.in","r",stdin),freopen("data.out","w",stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i ++)
	{
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
