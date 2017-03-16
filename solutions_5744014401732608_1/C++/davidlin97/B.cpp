#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;

long long b, m;

void read(){
  cin >> b >> m;
}

void solve(){
  if(m > pow(2, b-2)) cout << "IMPOSSIBLE" << '\n';
  else if(m==pow(2, b-2)){
    cout << "POSSIBLE" << '\n';
    for(int i=0; i<b; i++){
      for(int j=0; j<b; j++){
        cout << (i<j);
      }
      cout << '\n';
    }
  }
  else{
    long long k=0;
    cout << "POSSIBLE" << '\n';
    for(long long i=0; i<b; i++){
      if(i==1) k=1;
      for(long long j=0; j<b-1; j++){
        cout << (i<j);
      }
      cout << bool(k&m);
      // cout << k << ' ' << b;
      k<<=1;
      cout << '\n';
    }
  }
}

int main(){
  int T;
  cin >> T;
  for(int i=1; i<=T; i++){
    read();
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}