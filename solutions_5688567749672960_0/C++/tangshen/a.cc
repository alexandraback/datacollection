#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
int f(int x){
  if(x<10)return x;
  int ans = 0;
  while(x){
    ans *= 10;
    ans += x%10;
    x /= 10;
  }
  return ans;
}
int main(){
  int T;cin >> T;int idx = 0;
  int max = 1000001;
  vector<int> V(1000001,-1);
  V[0]=0;V[1] = 1;
  for(int i=2;i<V.size();++i){
    if(V[i] < 0)
      V[i] = V[i-1] + 1;
    else V[i] = min(V[i],V[i-1]+1);
    int rev = f(i);
    if(V[rev] < 0)V[rev] = V[i]+1;
    else V[rev] = min(V[rev],V[i]+1);
//   if(i<20)cout << V[i] << endl;
  }
  while(T--){++idx;
    int x; cin >> x;
    cout << "Case #" << idx << ": " << V[x] << endl;
  }
  return 0;
}
