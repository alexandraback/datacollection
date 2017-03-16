#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int OUTSIDE = -1;
const int EMPTY = 0;
const int STONE = 1;
typedef pair<int,int> pii;

#define x first
#define y second

int K,N,M;
int dx[] ={0,1,1,1,0,-1,-1,-1};
int dy[] ={1,1,0,-1,-1,-1,0,1};


//const int STONE = 1;

int grid[25][25];

int g[25][25];
int startx,starty;
vector<pii> points;

int cnt(int x,int y)
{
  if(x<0 || y<0 || x>M || y>N || g[y][x])
    return 0;
  if(grid[y][x]==STONE)
    return 0;
  g[y][x]=1;
  int ret=1;
  for(int m=0;m<4;m++)
    ret+=cnt(x+dx[m*2],y+dy[m*2]);
  return ret;
}

int check()
{
  memset(g,0,sizeof(g));
  M++;N++;
  int ret = (N+1)*(M+1) - cnt(0,0);
  M--;N--;
  return ret>=K;
}

int f(int x, int y, int st,int lastmove)
{

  if(st==0 && x==startx && y==starty)
    {
      return check();
    }
  else if(st==0 || grid[y][x]!=EMPTY)
    return 0;

  //if(abs(x-startx)*abs(x-startx)+(y-starty)*(y-starty)>st*st+1)
  // return 0;

  grid[y][x]=STONE;
  points.push_back(make_pair(x,y));
  for(int m=lastmove;m<min(8,lastmove+4);m++)
    {
      if(f(x+dx[m],y+dy[m],st-1,m))
	return 1;
    }
  points.pop_back();
  grid[y][x]=EMPTY;
  return 0;
}

int main()
{
  int T;
  cin>>T;

for(int t=1;t<=T;t++)
    {
      cin>>N>>M>>K;
      int res=0;
      if(K<=3 || N==1 || M==1)
	res=K;
      else
	{
	  memset(grid,-1,sizeof(grid));
	  for(int x=1;x<=M;x++)
	    for(int y=1;y<=N;y++)
	      grid[y][x]=EMPTY;

	  for(int st=1;st<=K && res==0;st++)
	    for(int y=1;y<=N && res==0;y++)
	      {
		startx=1;
		starty=y;
		if(f(1,y,st,0))
		  res=st;
	      }
	}
	
      printf("Case #%d: %d\n",t,res);
    }
  return 0;
}
