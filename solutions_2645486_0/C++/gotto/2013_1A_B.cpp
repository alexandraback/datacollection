#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int e,r,n,m;
int v[1111];
int solve(int a,int b){
  if(b==n) return 0;
  int ret = 0;
  for(int i = 0; i <= a; i++){
    ret = max(ret,v[b]*i+solve(min(e,a-i+r),b+1));
  }
  return ret;
}
int main(void){
  cin >> m;
  for(int k = 1; k <= m; k++){
    cin >> e >> r >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << "Case #" << k << ": " << solve(e,0) << endl;
  }
}
