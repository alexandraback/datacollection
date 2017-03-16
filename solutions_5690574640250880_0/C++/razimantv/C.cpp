# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>
# include <map>

using namespace std;

int neigh[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool work(char *board,int R,int C,int M,int x,int y)
{
  char seen[R*C];
  memset(seen,0,sizeof seen);
  queue<int> bfsq;
  seen[x*C+y]=1;
  bfsq.push(x*C+y);

  int cnt=0;
  while(!bfsq.empty())
  {
    cnt++;

    int u=bfsq.front();
    bfsq.pop();
    x=u/C,y=u-x*C;

    bool flag=true;
    for(int n=0;n<8;n++)
    {
      int xx=x+neigh[n][0],yy=y+neigh[n][1];
      int v=xx*C+yy;
      if(xx<0 or xx>=R or yy<0 or yy>=C or seen[v])continue;
      if(board[v])
      {
        flag=false;
        break;
      }
    }

    if(!flag)continue;
    for(int n=0;n<8;n++)
    {
      int xx=x+neigh[n][0],yy=y+neigh[n][1];
      int v=xx*C+yy;
      if(xx<0 or xx>=R or yy<0 or yy>=C or seen[v])continue;
      seen[v]=true;
      bfsq.push(v);
    }
  }

  return cnt==R*C-M;
}

int main()
{
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    int R,C,M;
    scanf("%d%d%d",&R,&C,&M);
    char board[R][C];
    memset(board,1,sizeof board);
    for(int i=0;i<R*C-M;i++)
    {
      board[i/C][i%C]=0;
    }

    int r=-1,c=-1;
    do
    {
      for(int i=0;i<1;i++)
      {
        for(int j=0;j<1;j++)
        {
          if(board[i][j])continue;
          if(work(&board[0][0],R,C,M,i,j))
          {
            r=i;
            c=j;
            goto BPP;
          }
        }
      }
    }while(next_permutation(&board[0][0],(&board[0][0])+R*C));
BPP:
    printf("Case #%d:\n",t);
    if(r==-1)printf("Impossible\n");
    else
    {
      for(int i=0;i<R;i++)
      {
        for(int j=0;j<C;j++)
        {
          if(i==r and j==c)printf("c");
          else if(board[i][j])printf("*");
          else printf(".");
        }
        printf("\n");
      }
    }
  }
  return 0;
}

