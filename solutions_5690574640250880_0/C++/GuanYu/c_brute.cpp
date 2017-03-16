#include <cstdio>
#include <cstring>
#define MAXN 5
using namespace std;

// Grid
int R,C,M;
char grid[MAXN][MAXN];

// Direcions
int dir[8][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

// DFS
int mark[MAXN][MAXN];
bool vis[MAXN][MAXN];
void dfs(int row,int col)
{
	int i,cnt,r,c;
	vis[row][col]=true;
	if(!mark[row][col])
	{
		for(i=0;i<8;i++)
		{
			r=row+dir[i][1];
			c=col+dir[i][0];
			if(r<0||c<0||r>=R||c>=C||vis[r][c]) continue;
			if(grid[r][c]=='.') dfs(r,c);
		}
	}
}

// Backtracking
bool ok;
int lis[25];
void backtrack(int now,int cnt)
{
	int i,row,col,r,c;

	// try
	if(cnt==M)
	{
		// Recover
		for(row=0;row<R;row++)
			for(col=0;col<C;col++)
				grid[row][col]='.';
		for(i=0;i<M;i++)
			grid[lis[i]/C][lis[i]%C]='*';

		// Mark
		for(row=0;row<R;row++)
		{
			for(col=0;col<C;col++)
			{
				cnt=0;
				for(i=0;i<8;i++)
				{
					r=row+dir[i][1];
					c=col+dir[i][0];
					if(r<0||c<0||r>=R||c>=C) continue;
					if(grid[r][c]=='*') cnt++;
				}
				mark[row][col]=cnt;
			}
		}

		// DFS
		cnt=0;
		memset(vis,false,sizeof(vis));
		for(row=0;row<R;row++)
		{
			for(col=0;col<C;col++)
			{
				if(grid[row][col]=='.'&&!mark[row][col]&&!vis[row][col])
				{
					if(cnt) return;
					dfs(row,col);
					cnt++;
				}
			}
		}
		if(!cnt) return;
		for(row=0;row<R;row++)
		{
			for(col=0;col<C;col++)
				if(grid[row][col]=='.'&&!vis[row][col])
					return;
		}
		ok=true;
		return;
	}

	// Prune
	if(R*C-now+cnt<M) return;

	// Row, Col
	row=now/C;
	col=now%C;

	// Put
	lis[cnt]=now;
	backtrack(now+1,cnt+1);
	if(ok) return;

	// Not put
	backtrack(now+1,cnt);
	if(ok) return;
}

// Output - normal
void op(int R,int C)
{
	int row,col;
	for(row=0;row<R;row++)
	{
		for(col=0;col<C;col++)
			putchar(grid[row][col]);
		putchar('\n');
	}
}

// Main
int main(void)
{
	int tc,cs,row,col;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		scanf("%d%d%d",&R,&C,&M);

		// Output
		printf("Case #%d:\n",cs);

		// No mine
		if(!M)
		{
			for(row=0;row<R;row++)
				for(col=0;col<C;col++)
					grid[row][col]='.';
			grid[0][0]='c';
			op(R,C);
		}

		// 1 space
		else if(R*C-M==1)
		{
			for(row=0;row<R;row++)
				for(col=0;col<C;col++)
					grid[row][col]='*';
			grid[0][0]='c';
			op(R,C);
		}

		// Backtracking
		else
		{
			ok=false;
			backtrack(0,0);
			if(!ok) puts("Impossible");
			else
			{
				for(row=0;row<R;row++)
				{
					for(col=0;col<C;col++)
					{
						if(grid[row][col]=='.'&&!mark[row][col])
						{
							grid[row][col]='c';
							break;
						}
					}
					if(col<C) break;
				}
				op(R,C);
			}
		}
	}
	return 0;
}