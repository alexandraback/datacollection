#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> origins, int depth,map<vector<int>, int>& memo){
  sort(origins.begin(), origins.end(), greater<int>());
  if(memo.count(origins) != 0){
    return memo[origins];
  }
  if(origins[0] == 1){
    return depth+1;
  }
  int ret = origins[0]+depth;
  for(int i = 1; i < origins[0]; i++){
    vector<int> work;
    copy(origins.begin(), origins.end(), back_inserter(work));
    work[0] -= i;
    work.push_back(i);
    ret = min(ret, dfs(work, depth+1, memo));
  }
  memo[origins] = ret;
  return ret;
}


void solve(int CASE){
  int m;
  map<vector<int>, int>memo;
  vector<int> origins;
  cin >> m;
  for(int i = 0; i < m; i++){
    int tmp;
    cin >> tmp;
    origins.push_back(tmp);
  }
  cout << "Case #"<<CASE << ": " << dfs(origins, 0, memo) << endl;
}


int main(){
  int N;
  cin >> N;
  for(int i = 0;i < N; i++){
    solve(i+1);
  }

}

