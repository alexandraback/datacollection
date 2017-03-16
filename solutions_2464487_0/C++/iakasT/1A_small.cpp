#include<iostream>
#include<cmath>
using namespace std;
const double pi = acos(-1);
int main(){
  int tc = 0,te = 0;
  cin>>te;
  while(te--){
    long long r,tmp;
    cout <<"Case #" << ++tc << ": ";
    cin>>r>>tmp;
    double t = tmp;
    int ans = 0;
    while(t > 0){
      double area = pi * (r+1) * (r+1) - pi * r * r;
      double need = area / pi;
      if (need  > t + 1e-10)break;
      t -= need;
      r += 2;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

