#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int T;
int N;
string s[111];

int bit_count(long long bit){
  int c = 0;
  for(; bit; bit>>=1){
    c += bit&1;
  }
  return c;
}

int dp[1<<11][11][2];
int solve(int bit,int a,int b){
  if(bit+1 == 1<<N && b) return 1;
  if(dp[bit][a][b] >= 0) return dp[bit][a][b];

  int ret = 0;
  for(int i = 0; i < N; i++){
    if(bit & (1<<i)) continue;
    if(a == N || b){
      ret += solve(bit | (1<<i),i,0);
      ret %= 1000000007;
    }
    if(a != N && s[a][s[a].size()-1] == s[i][0]){
      ret += solve(bit | (1<<i),i,1);
      ret %= 1000000007;
    }
  }
  return dp[bit][a][b] = ret;
}

int main(void){
  cin >> T;
  for(int t = 1; t <= T; t++){
    cin >> N;
    for(int i = 0; i < N; i++)
      cin >> s[i];
    memset(dp,-1,sizeof(dp));
    cout << "Case #" << t << ": " << solve(0,N,0) << endl;
  }
}
