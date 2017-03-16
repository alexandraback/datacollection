#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long lli;
double r,t;

lli solve(){
  double a = (r+1)*(r+1) - r*r, b = (r+3)*(r+3) - (r+2)*(r+2);
  if(a + b > t){
    if(a > t) return 0;
    else return 1;
  } else {
    double c = a + b;
    lli cnt = 2;
    for(double i=4;;i+=2,cnt++){
      c += (r+i+1)*(r+i+1) - (r+i)*(r+i);
      if(c > t) return cnt;
    }

  }
}

int main(){
  int T;
  cin >> T;
  for(int test=1;test<=T;test++){
    cin >> r >> t;
    lli ans = solve();
    cout << "Case #" << test << ": " << ans << endl;
  }
}
