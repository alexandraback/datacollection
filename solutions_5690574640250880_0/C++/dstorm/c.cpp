// Author : dstorm
// Problem C : Minesweeper Master
// Compiler : Mingw (G++)
#include<cstdio>
#include<cstring>
#define N 51
#define makeSafe(p,q) if(grid[p][q]=='*'){safe--;grid[p][q]='.';}
char grid[N][N];
int visited[N][N];
int row,col,mines,safe;
void nextSafe(int oi,int oj,int &ni,int &nj)
{	int i,j;
	for(i=oi;i<row;i++)
	{	for(j=0;j<col;j++)
		{	if(!visited[i][j] && grid[i][j]=='.')
			{	ni=i;
				nj=j;
				return;
			}
		}
	}
}
bool solve()
{	int i=0,j=0,oi=-1,oj=-1;
	safe = row*col-mines;
	grid[i][j]='c';
	visited[i][j]=1;
	safe--;
	//printf("\ns:%d\n",safe);
	while(safe>0)
	{	oi=i;
		oj=j;
		//printf("i=%d j=%d\n",i,j);
		if(i>0 && safe>0)	// TOP
		{	makeSafe(i-1,j)
		}
		if(j>0 && safe>0) // LEFT
		{	makeSafe(i,j-1)
		}
		if(i>0 && j>0 && safe>0) // TOP-LEFT
		{	makeSafe(i-1,j-1)
		}
		if(i<row-1 && safe>0) // BOTTOM
		{	makeSafe(i+1,j)
		}
		if(j<col-1 && safe>0) // RIGHT
		{	makeSafe(i,j+1)
		}
		if(i<row-1 && j<col-1 && safe>0) // BOTTOM-RIGHT
		{	makeSafe(i+1,j+1)
		}
		if(i>0 && j<col-1 && safe>0) // TOP-RIGHT
		{	makeSafe(i-1,j+1)
		}
		if(i<row-1 && j>0 && safe>0) // BOTTOM-LEFT
		{	makeSafe(i+1,j-1)
		}
		visited[i][j]=1;
		nextSafe(i,j,i,j);
	}
	int flag=1;
	if(oj==0 && oi<row-1 && col>1 && grid[oi+1][1]=='*' && grid[oi][col-1]=='.')
	{	for(i=oi,j=1;i>=0&&j<col-1;i--,j++)
		{	if(j==col-2 && i==1)
				break;
			grid[i][col-1]='*';
			grid[oi+1][j]='.';
		}
		if(grid[oi+1][1]=='*')
			flag=0;
	}
	else if(row>1)
	{	for(j=col-1;j>0;j--)
		{	if(grid[0][j]=='.' && grid[1][j]=='*')
			{	flag=0;
				break;
			}
		}
		if(!flag && j>3 && row>2 && grid[2][0]=='*' && grid[2][1]=='*' && grid[2][2]=='*')
		{	grid[2][0]=grid[2][1]=grid[2][2]='.';
			grid[0][j]=grid[0][j-1]=grid[1][j-1]='*';
			flag=1;
		}
	}
	if(mines<(row*col-1) && ((col>1 && grid[0][1]!='.') || (row>1 && grid[1][0]!='.') || (row>1 && col>1 && grid[1][1]!='.')))
		flag=0;
	if(flag)
		for(i=0;i<row;i++)
		{	for(j=0;j<col;j++)
			{	printf("%c",grid[i][j]);
			}
			printf("\n");
		}
	else
		printf("Impossible\n");
	
}

int main()
{	int t,i,j,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{	scanf("%d %d %d",&row,&col,&mines);
		memset(grid,'*',sizeof(grid));
		memset(visited,0,sizeof(visited));
		printf("Case #%d:\n",i);
		solve();
	}
	return 0;
}