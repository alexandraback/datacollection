#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <iostream>

#define inf 0x3f3f3f3f

using namespace std;
vector<char> sol;
int xt, yt;

bool visit[1000][1000];
bool dfs(int x, int y, int i, int max){
  if(i > max) return false;
  if(!visit[x+500][y+500]){
    visit[x+500][y+500] = true;
  }else{
    return false;
  }
  if(x == xt && y == yt){
    return true;
  }
  if(dfs(x, y+i, i+1, max)){
    sol.push_back('N');
    return true;
  }
  if(dfs(x, y-i, i+1, max)){
    sol.push_back('S');
    return true;
  }
  if(dfs(x+i, y, i+1, max)){
    sol.push_back('E');
    return true;
  }
  if(dfs(x-i, y, i+1, max)){
    sol.push_back('W');
    return true;
  }
  return false;
}

bool iterative(){
  for(int i = 0; i < 600; i++){
    memset(visit, 0, sizeof(visit));
    
    if(dfs(0,0,1,i)){
      return true;
    }
  }
  return false;
}

int main(){
  int T;
  scanf("%d\n", &T);
  for(int t = 0; t < T; t++){
    
    sol.clear();
    scanf("%d %d\n", &xt, &yt);
    
    iterative();
    
    printf("Case #%d: ", t+1);
    reverse(sol.begin(), sol.end());
    for(int i = 0; i < sol.size(); i++){
      cout << sol[i];
    }
    cout << endl;
    
  }
}
