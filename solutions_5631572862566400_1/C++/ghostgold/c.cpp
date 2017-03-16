#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int like[2000];
int parent[2000];
int visited[2000];
int tail[2000];
int res;
int n;
void dfs(int x){
  visited[x] = visited[parent[x]] +1;
  if(visited[like[x]]){
    if (parent[x] == like[x]){
      int u = like[x];
      if (tail[u] < visited[u])
	tail[u] = visited[u];
    }
    else {
      if (res < visited[x] - visited[like[x]]+1)
	res = visited[x] - visited[like[x]] +1;
    }
  }
  else{
    parent[like[x]] = x;
    dfs(like[x]);
  }
}
void work()
{
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d",&like[i]);
    like[i]--;
  }
  memset(tail,0,sizeof(tail));
  res = 0;
  for(int i =0; i < n;i++){
    memset(visited,0,sizeof(visited));
    visited[i] =1 ;
    parent[i] = -1;
    dfs(i);
  }
  int t = 0;
  for(int i = 0; i < n;i++){
    if (like[like[i]] == i) {
      t += tail[i];
    }
  }
  if (t > res)
    res = t;
  printf("%d\n",res);
}
int main()
{
  int T;
  scanf("%d",&T);
  for(int i =1; i <=T; i++){
    printf("Case #%d: ", i);
    work();
  }
}
