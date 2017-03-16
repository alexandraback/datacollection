#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 100030;    // Change as necessary
const ll  MODD = 1000000009; //

void do_case(){
  string s;
  cin >> s;
  reverse(s.begin(),s.end());
  
  int ctr = 0;
  for(int i=0;i<s.length();i++)
    ctr += ("+-"[ctr%2] != s[i]);
  cout << ctr << endl;
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
