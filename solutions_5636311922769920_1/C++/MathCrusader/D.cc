#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 100030;    // Change as necessary
const ll  MODD = 1000000009; //

void do_case(){
  ll K,C,S;
  cin >> K >> C >> S;
  
  vector<ll> ans;
  int ctr = 0;
  for(int i=0;i<K;i+=C){
    ll val = 0;
    for(int j=0;j<C;j++){
      val = val*K + ctr++;
      ctr %= K;
    }
    ans.push_back(val+1);
  }
  
  if(ans.size() > S){ cout << " IMPOSSIBLE" << endl; return; }
  
  for(int i=0;i<ans.size();i++)
    cout << " " << ans[i];
  cout << endl;
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int T,C=1; cin >> T;
  
  while(T--){
    cout << "Case #" << C++ << ":";
    do_case();
  }
  
  return 0;
}
