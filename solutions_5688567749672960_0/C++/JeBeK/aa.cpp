#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int dis[2000000];
queue<int>q;


void BFS()
{
  memset(dis,127,sizeof dis);
  dis[0]=0;
  q.push(0);
  while(q.size())
    {
      int v=q.front();
      int v1=v;
      q.pop();
      if(v+1<=1000000 && dis[v+1]>dis[v]+1)
	{
	  dis[v+1]=dis[v]+1;
	  q.push(v+1);
	}
      int x=0;
      while(v)
	{
	  x=x*10+v%10;
	  v/=10;
	}
      if(dis[x]>dis[v1]+1)
	{
	  dis[x]=dis[v1]+1;
	  q.push(x);
	}
    }
}

int main()
{
  BFS();
  int qw;
  cin>>qw;
  for(int i=1;i<=qw;i++)
    {
      int n;
      cin>>n;
      cout<<"Case #"<<i<<": "<<dis[n]<<endl;
    }
}
