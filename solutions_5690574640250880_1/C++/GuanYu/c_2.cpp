#include <cstdio>
#include <cstring>
#define MAXN 52
using namespace std;

// Grid
int R,C,M;
char grid[MAXN][MAXN];

// Mark
int mark[MAXN][MAXN];
bool vis[MAXN][MAXN];

// Next list
int nl[2][2502];

// Directions
int dir[8][2]={{-1,0,},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

// Output
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
	int tc,cs,i,j,row,col,empty,nc[2],mod,id,r,c,cnt,gap;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		scanf("%d%d%d",&R,&C,&M);
		empty=R*C-M;

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
		else if(empty==1)
		{
			for(row=0;row<R;row++)
				for(col=0;col<C;col++)
					grid[row][col]='*';
			grid[0][0]='c';
			op(R,C);
		}

		// Try
		else
		{
			// 1xC
			if(R==1)
			{
				for(col=0;col<empty;col++)
					grid[0][col]='.';
				for(;col<C;col++)
					grid[0][col]='*';
				grid[0][0]='c';
				op(R,C);
			}

			// Rx1
			else if(C==1)
			{
				for(row=0;row<empty;row++)
					grid[row][0]='.';
				for(;row<R;row++)
					grid[row][0]='*';
				grid[0][0]='c';
				op(R,C);
			}

			// 2x2 or more
			else
			{
				// Empty = 2, 3
				if(empty<4) puts("Impossible");
				else
				{
					// From left upper corner
					mod=0;
					memset(vis,false,sizeof(vis));
					mark[0][0]=0;
					mark[0][1]=mark[1][0]=mark[1][1]=1;
					vis[0][0]=vis[0][1]=vis[1][0]=vis[1][1]=true;
					nl[0][0]=1,nl[0][1]=C,nl[0][2]=C+1,nc[0]=3;
					empty-=4;
					while(empty)
					{
						// Choose best
						gap=(int)1e9;
						for(i=0;i<nc[mod%2];i++)
						{
							cnt=0;
							row=nl[mod%2][i]/C;
							col=nl[mod%2][i]%C;
							for(j=0;j<8;j++)
							{
								r=row+dir[j][1];
								c=col+dir[j][0];
								if(r<0||c<0||r>=R||c>=C||vis[r][c]) continue;
								cnt++;
							}
							if(cnt&&cnt<=empty&&!((empty-cnt)%2)&&empty-cnt<gap)
							{
								gap=empty-cnt;
								id=i;
							}
						}

						// No fit
						if(gap==(int)1e9) break;

						// Copy
						nc[(mod+1)%2]=0;
						for(i=0;i<id;i++)
							nl[(mod+1)%2][nc[(mod+1)%2]++]=nl[mod%2][i];

						// Update
						cnt=0;
						row=nl[mod%2][id]/C,col=nl[mod%2][id]%C;
						mark[row][col]=0;
						for(j=0;j<8;j++)
						{
							r=row+dir[j][1];
							c=col+dir[j][0];
							if(r<0||c<0||r>=R||c>=C||vis[r][c]) continue;
							mark[r][c]=1;
							vis[r][c]=true;
							nl[(mod+1)%2][nc[(mod+1)%2]++]=r*C+c;
							cnt++;
						}
						empty-=cnt;

						// Copy
						for(i=id+1;i<nc[mod%2];i++)
							nl[(mod+1)%2][nc[(mod+1)%2]++]=nl[mod%2][i];
						mod++;
					}

					// Impossible
					if(empty) puts("Impossible");
					else
					{
						for(row=0;row<R;row++)
						{
							for(col=0;col<C;col++)
							{
								if(!vis[row][col]) grid[row][col]='*';
								else grid[row][col]='.';
							}
						}
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
		}
	}
	return 0;
}