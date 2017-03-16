#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long lli;

lli p,q;

void solve(){
  bool f = false;
  lli gcd = __gcd(p,q);
  p /= gcd;
  q /= gcd;

  for(int i=1;i<63;i++){
    lli a = 1LL << i;
    //cout << a << " >= " << q << "  " << a << " % " << q << " == " << a%q << endl;
    if(a >= q && a % q == 0){
      p *= a / q;
      q *= a / q;
      f = true;
    }
  }
  
  if(f){
    lli num = q;
    for(int i=0;num>0;i++){
      if(num <= p) {
        cout << i << endl;
        return;
      }
      num /= 2;      
    }
  }
  cout << "impossible" << endl;
}

int main(){
  int T;
  char ch;
  cin >> T;
  for(int t=1;t<=T;t++){
    //scanf("%lld\%lld",&p,&q);
    cin >> p >> ch >> q;
    cout << "Case #" << t << ": " << flush;
    solve();
  }
}
