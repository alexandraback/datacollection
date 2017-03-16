#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 100030;    // Change as necessary
const ll  MODD = 1000000009; //

void do_case(){
  int n;
  ll M;
  cin >> n >> M;
  
  if((1ll << (n-2)) < M){ cout << "IMPOSSIBLE" << endl; return; }
  
  cout << "POSSIBLE" << endl;
  if((1ll << (n-2)) == M){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        cout << (i < j);
      cout << endl;
    }
    return;
  }
  
  string top = "0";
  for(int j=0;j<n-1;j++)
    top += char('0'+((M >> j) & 1ll));
  reverse(top.begin(),top.end());
  cout << top << endl;
  for(int i=1;i<n;i++){
    for(int j=0;j<n;j++)
      cout << (i < j);
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int T,C=1; cin >> T;
  
  while(T--){
    cout << "Case #" << C++ << ": ";
    do_case();
  }
  
  return 0;
}
