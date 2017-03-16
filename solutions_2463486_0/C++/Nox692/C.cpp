#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;

typedef unsigned long long ull; 

bool isPalindrome(string s){
  for(int i = 0, j = s.size()-1 ; i < j ; i++, j--){
    if(s[i] != s[j]) return false;
  }
  return true;
}

int main(){
  int dp[1010];
  memset(dp, 0, sizeof(dp));
  int i = 1;
  while(i*i <= 1000){
    string s1, s2;
    ostringstream oss1, oss2;
    oss1 << i*i;
    s1 = oss1.str();
    oss2 << i;
    s2 = oss2.str();
    
    if(isPalindrome(s1) && isPalindrome(s2)){
      dp[i*i] = 1;
    }
    i++;
  } 
  /*
  for(int i = 1 ; i <= 1000 ; i++){
    dp[i] += dp[i-1];
  }
  */
  int T;
  cin >> T;
  int A, B;
  for(int cs = 1 ; cs <= T ; cs++){
    cin >> A >> B;
    int ans = 0;
    for(int i = A ; i <= B ; i++){
      if(dp[i]) ans++;
    }
    cout << "Case #" << cs << ": " << ans << endl;
  }
}
