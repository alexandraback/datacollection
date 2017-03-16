#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(void){
  ll n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    ll t,r;
    cin >> r >> t;
    ll R=r,j;
    for(j = 0;; j++){
      ll wb=0;
      wb -=R*R;
      R++;
      wb += R*R;
      R++;
      if(wb > t) break;
      t -= wb;
      //cout << wb << " " << t << endl;
    }
    cout << "Case #" << i << ": " << j << endl;
  }
}
