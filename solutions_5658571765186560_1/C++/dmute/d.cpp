#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

bool check = true;
int tst, n, m, r, cnt;
int mp[10][10];
int all=0, fa[20];
bool vis[22][22];
int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}
void spread(int x,int y)  {
	if (vis[x][y] || x < 0 || y < 0 || x >= n || y >= m)return;
	all++;
	vis[x][y]=1;
	spread(x+1,y),spread(x-1,y),spread(x,y+1),spread(x,y-1);
}
void solve()  {
	//get a,b
	int a=0, b=0;
	
	for (int i = 0; i < r; i ++)  {
		bool yes=false;
		for (int j = 0; j < r; j ++)  
			if (mp[i][j])yes=true, b=max(b,j);
		if (yes) a=max(a,i);
	}
	for (int j=0;j<=b;j++)  {
		bool yes=false;
		for (int i=0;i<r;i++) if (mp[i][j])yes=true;
			if (!yes) return;
	}
	a++,b++;
	if (a<=n-2&&b<=m-2) return;
	bool ok=false; //ok=true gabriel win
	for (int i = 0; i + a - 1< n; i ++)
		for (int j = 0; j + b - 1 < m; j ++)   {
			memset(vis, 0, sizeof vis);
			for (int x=0;x<r;x++)
				for (int y=0;y<r;y++) vis[i+x][j+y]=mp[x][y];
			bool bad=false;
			for (int x=0;x<n;x++)
				for (int y=0;y<m;y++){
					all=0;
					if (!vis[x][y])  spread(x,y);
					if (all % cnt!=0)  {
						bad=true;
						break;
					}
				}
			if (!bad) ok=true;
		} 
	swap(n, m);
	for (int i = 0; i + a - 1< n; i ++)
		for (int j = 0; j + b - 1 < m; j ++)   {
			memset(vis, 0, sizeof vis);
			for (int x=0;x<r;x++)
				for (int y=0;y<r;y++) vis[i+x][j+y]=mp[x][y];
			bool bad=false;
			for (int x=0;x<n;x++)
				for (int y=0;y<m;y++){
					all=0;
					if (!vis[x][y])  spread(x,y);
					if (all % cnt!=0)  {
						bad=true;
						break;
					}
				}
			if (!bad) ok=true;
		} 
	swap(n,m);

	if (!ok) check=true;
}
void merge(int x,int y) {fa[F(x)]=F(y);}

void dfs(int x, int left)  {
	if (x == r)  {
		if (left == 0)  solve();
		return;
	}
	if (left==0){
		dfs(x+1,left);
		return;
	}
	for (int i = 1; i < 1 << r; i ++)  {
		int c = 0;
		for (int j = 0; j < r;j ++) c += (i >> j) & 1;
		if (c > left) continue;
		for (int j = 0; j < r; j ++)
			if ((i >> j) & 1)  {
				mp[x][j] = 1;
			}
		bool ok = true;
		for (int j = 0; j <= r; j ++)  fa[j]=j;
		for (int j=0;j<r;j++)
			if((i>>j)&1)  {
				if (x-1>=0&&mp[x-1][j]) merge(r, j);
				if (j-1>=0&&mp[x][j-1]) merge(j,j-1);
				if (j+1<r&&mp[x][j+1])merge(j,j+1);
			}
		int co=0;
		for (int j=0;j<=r;j++) {
			if (j!=r&&!mp[x][j])continue;
			if (j==r&&x==0) continue;
			if (F(j)==j) co++;
		}
		ok=co==1;
		if (ok) dfs(x+1,left-c);
		for (int j=0;j<=r;j++)mp[x][j]=0;
	}
}

int main()  {
	scanf("%d", &tst);
	for (int t = 1; t <= tst; t ++)  {
		scanf("%d%d%d", &cnt, &n, &m);
		r = cnt;
		if (cnt >= 7)  {
			printf("Case #%d: RICHARD\n",t);
			continue;
		}
		if (n > m)swap(n,m);
		if (n * m % cnt != 0 || n + n + 1 <= cnt)  {
			printf("Case #%d: RICHARD\n",t);
			continue;
		}
		check = false;
		memset(mp, 0, sizeof mp);
		dfs(0, cnt);
		printf("Case #%d: %s\n", t, check ? "RICHARD" : "GABRIEL");
	}
	return 0;
}