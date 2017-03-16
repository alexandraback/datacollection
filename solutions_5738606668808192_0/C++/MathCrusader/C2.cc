#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX_N = 100030;    // Change as necessary
const ll  MODD = 1000000009; //

vector<ll> primes;

set<string> anss;

bool valid(const string& s){
  
  vector<int> ans;
  for(int b=2;b<=10;b++){
    for(int k=0;k<primes.size();k++){
      ll mod = primes[k];
      ll val = 0;
      for(int i=0;i<s.length();i++)
        val = (val*b + (s[i]-'0')) % mod;
      if(val == 0) { ans.push_back(mod); break; }
    }
    if(ans.size() != b-1) return false;
  }
  
  cout << s;
  for(int i=0;i<ans.size();i++)
    cout << " " << ans[i];
  cout << endl;
  return true;
}

void do_case(){
  cout << endl;
  ll N,J,ctr=0;
  cin >> N >> J;
  
  while(ctr < J){
    string s = "1";
    for(int i=0;i<N-2;i++)
      s += "01"[rand()%2];
    s += "1";
    if(valid(s)) ctr++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  for(ll i=2;i<10000;i++){
    bool pr = true;
    for(ll j=2;j*j<=i;j++)
      if(i % j == 0) { pr = false; break; }
    if(pr) primes.push_back(i);
  }
  
  ll T,C=1; cin >> T;
  
  while(T--){
    cout << "Case #" << C++ << ": ";
    do_case();
  }
  
  return 0;
}
