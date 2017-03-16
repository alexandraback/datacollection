#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;


int N; 
vector<vector<int> > G;
vector<bool> VIS;	//Father
vector<bool> vis;

bool bfs(int start)
{
  fill(vis.begin(), vis.end(), false);
  queue<int> Q;
  Q.push(start);
  vis[start] = VIS[start] = true;
  
  while(!Q.empty()){
    int v = Q.front(); Q.pop();
    for(int i =0; i < G[v].size(); ++i){
      if(vis[G[v][i]] == false){
	vis[G[v][i]] = VIS[G[v][i]] = true;
	Q.push(G[v][i]);
      }
      else
	return true;
    }
  }
  
  return false;
}

int main(void)
{
  int T; cin >> T;
  
 
  
  for(int t=0; t < T; ++t){
    cin >> N;
    G.clear();
    G = vector<vector<int> >(N, vector<int>());
    for(int j=0; j < N; ++j){
      int m; cin >> m;
      for(int i=0; i < m; ++i){
	int v; cin >> v;
	G[j].push_back(v-1);
      }
    }
    VIS.clear();
    vis.clear();
    VIS = vector<bool>(N, false);
    vis = vector<bool>(N, false);
    bool flag = false;
    
    for(int v=0; v < N; ++v){
      if(VIS[v] == false){
	if(bfs(v)){
	  flag = true;
	  break;
	}
      }
    }
    if(flag)
      printf("Case #%d: Yes\n", t+1);
    else
      printf("Case #%d: No\n", t+1);
   
    
  }
      
  
  return 0;
}

