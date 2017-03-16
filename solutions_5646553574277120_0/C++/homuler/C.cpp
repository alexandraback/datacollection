#include <iostream>
#include <vector>

using namespace std;

int small(int c, int v, int d, vector<int> ds){
  auto dp = vector<int>(v+1,0);
  dp[0] = c + 1;
  for(int i = 0; i < d; ++i){
    for(int j = 0; j < v+1; ++j){
      if(dp[j] > 1 && j+ds[i] <= v){
        dp[j+ds[i]] = max(dp[j+ds[i]], dp[j]-1);
      }
    }
    for(int j = 0; j < v+1; ++j){
      if(dp[j]){
        dp[j] = c + 1;
      }
    }
  }
  /**
  for(int i = 0; i <= v; ++i){
    cout << dp[i] << " ";
  }
  cout << endl;*/
  int cnt = 0;
  for(int i = 0; i <= v; ++i){
    if(!dp[i]){
      ++cnt;
      for(int j = 0; j <= v; ++j){
        if(dp[j] > 1 && j+i <= v){
          dp[j+i] = max(dp[j+i], dp[j]-1);
        }
      }
      for(int j = 0; j <= v; ++j){
        if(dp[j]){
          dp[j] = 2;
        }
      }
    }
  }
  return cnt;
}

int main(){
  int t;
  cin >> t;
  int c, d, v;
  for(int i = 0; i < t; ++i){
    cin >> c >> d >> v;
    auto xs = vector<int>(d);
    for(int j = 0; j < d; ++j){
      cin >> xs[j];
    }
    cout << "Case #" << (i+1) << ": " << small(c, v, d, xs) << endl;
  }
}
