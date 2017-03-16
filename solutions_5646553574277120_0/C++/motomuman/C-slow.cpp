#include<bits/stdc++.h>
using namespace std;


int dfs(int add, set<int>coins, bool dp[33], int V, int depth){
  coins.insert(add);
  bool nextdp[33];
  for(int k = 0; k < 33; k++){
    nextdp[k] = dp[k];
  }
  for(int i = 0; i <= V - add; i++){
    if(dp[i]){
      nextdp[i+add] = true;
    }
  }
  for(int k = 0; k < 33; k++){
    dp[k] = nextdp[k];
  }
  bool flag = true;
  for(int i = 1; i <= V; i++){
    if(!dp[i]){
      flag = false;
    }
  }
  int ret = INT_MAX;
  if(flag){
    return depth;
  }else{
    for(int k = 1; k <= V; k++){
      if(coins.count(k) != 0){
        continue;
      }
      ret = min(ret, dfs(k,coins,dp,V, depth+1));
    }
  }
  return ret;
}


void solve(int CASE){
  int C, D, V;
  cin >> C >> D >> V;
  bool dp[33];
  for(int i = 0; i < 33; i++){
    dp[i] = false;
  }
  dp[0] = true;
  set<int> coins;
  for(int i = 0; i < D; i++){
    bool nextdp[33];
    for(int k = 0; k < 33; k++){
      nextdp[k] = dp[k];
    }
    int tmp;
    cin >> tmp;
    coins.insert(tmp);
    for(int j = 0; j <=V - tmp; j++){
      if(dp[j]){
        nextdp[j+tmp] = true;
      }
    }
    for(int k = 0; k < 33; k++){
      dp[k] = nextdp[k];
    }
  }

  bool flag = true;
  for(int i = 1; i <= V; i++){
    if(!dp[i]){
      flag = false;
    }
  }
  int ret = INT_MAX;
  if(flag){
    cout << "Case #" << CASE <<": " << 0 << endl;
  }else{
    for(int i = 1; i <= V; i++){
      if(coins.count(i) != 0){
        continue;
      }
      ret = min(ret, dfs(i,coins,dp,V, 1));
    }
    cout << "Case #" << CASE <<": " << ret << endl;
  }
}


int main(){
  long T;
  cin >> T;
  for(int i = 0; i < T; i++){
    solve(i+1);
  }
}

