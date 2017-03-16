#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int o[111];
int solve(int i,int s){
  if(i == n) return 0;
  if(o[i] < s) return solve(i+1,s+o[i]);
  int ret = solve(i+1,s)+1;
  if(s > 1){
    int j;
    for(j=0; s <= o[i]; s = (s<<1)-1,j++);
    ret = min(ret,solve(i+1,s+o[i])+j);
  }
  return ret;
}
int main(void){
  int T;
  cin >> T;
  for(int k = 1; k <= T; k++){
    int a;
    cin >> a >> n;
    for(int i = 0; i < n; i++){
      cin >> o[i];
    }
    sort(o,o+n);
    cout << "Case #" << k << ": " << solve(0,a) << endl;
  }
}
