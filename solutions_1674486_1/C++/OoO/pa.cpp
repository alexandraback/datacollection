#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#define MAX 1005
using namespace std;
vector<int >adj[MAX];
bool isSource[MAX],used[MAX],success;
void DFS(int index)
{
  int x;
  used[index]=true;
  for(int i=0;i<adj[index].size();i++)
  {
    x=adj[index][i];
    if(!used[x])
    {
      DFS(x);
      if(success)
        return ;
    }
    else
    {
      success=true;
      return ;
    }
  }
}
int main()
{
  freopen("A-large.in","r",stdin);
  freopen("a.txt","w",stdout);
  int T,cases,i,j,N,M,K;
  scanf("%d",&T);
  for(cases=1;cases<=T;cases++)
  {
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
      isSource[i]=true;
      adj[i].clear();
    }
    for(i=1;i<=N;i++)
    {
      scanf("%d",&M);
      while(M--)
      {
        scanf("%d",&K);
        adj[i].push_back(K);
        isSource[K]=false;
      }
    }
    success=false;
    for(i=1;i<=N;i++)
    {
      if(isSource[i])
      {
        memset(used,0,sizeof(used));
        DFS(i);
        if(success)
          break;
      }
    }
    if(success)
      printf("Case #%d: Yes\n",cases);
    else
      printf("Case #%d: No\n",cases);
  }
  return 0;
}
