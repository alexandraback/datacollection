#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  long double r,t;
  long double delta, x;
  unsigned long long int n,m;
  long double dn;
  cin >> T;
  for(int i=1; i<=T; i++) {
    cin >> r >> t;
    delta = (2*r-1)*(2*r-1)+8*t;
    n = floor((1-2*r+sqrt(delta))/4);
    dn = n;
    while(dn*dn*2 + dn*(2*r-1)-t > 0) {
      --n;
      dn = n;
    }
    dn = n+1;
    while(dn*dn*2 + dn*(2*r-1)-t <= 0) {
      n++;
      dn = n+1;
    }

    cout << "Case #" << i <<": "<< n << endl;
  }

  return 0;
}
