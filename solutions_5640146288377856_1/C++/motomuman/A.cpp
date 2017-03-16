#include<bits/stdc++.h>
using namespace std;

void solve(int CASE){
  int R, C, W;
  int ans;
  cin >> R >> C >> W;
  ans = R*(C/W) + (C%W!=0) + (W-1);
  cout << "Case #" << CASE <<": " << ans << endl;
}


int main(){
  long T;
  cin >> T;
  for(int i = 0; i < T; i++){
    solve(i+1);
  }
}

