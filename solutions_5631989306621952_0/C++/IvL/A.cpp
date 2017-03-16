#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void Solve(){
  string s;
  cin >> s;
  string out;
  for (auto c : s){
    string out1 = string(1, c)+out;
    string out2 = out+string(1, c);
    if (out1 < out2) out = out2;
    else out = out1;
  } cout << out << endl;
}

int main(){
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  REP(i,t) cout << "Case #" << i+1 << ": ", Solve();
  
  return 0;
}
