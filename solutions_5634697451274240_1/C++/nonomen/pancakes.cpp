#include <iostream>
#include <deque>
#include <bitset>
#include <cstring>

using namespace std;

bitset<200> v;
int dp[200][200][2];
int go(int l, int r, bool b){
  int r1=r;
  if(l<0 || r <0 || l>r)
    return 0;
  if(dp[l][r][b] != -1)
    return dp[l][r][b];
  if(v[r]!=b)
    return go(l,r,!b)+1;
  while(l<=r && b==v[r])
      r--;
  return dp[l][r1][b] = min(go(l,r,b),1+go(l,r,!b));
}

int main(){
  int t;
  cin >> t;
  for(int i = 0;i<t;i++){
    string s;
    cin >> s;
    v.reset();
    memset(dp,-1,sizeof(dp));
    bool b = true;
    deque<bool> d;
    for(int j =0;j<s.size();j++)
      v[j] = (s[j]=='+');
    cout << "Case #" << i+1 << ": "<< go(0,s.size()-1,true) << endl;
  }
  return 0;
}
