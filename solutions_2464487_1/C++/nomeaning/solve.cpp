#include <iostream>
using namespace std;
int T;
typedef __int128 lli;
int main(){
  cin>>T;
  for(int tc=1;tc<=T;tc++){
    lli r,t;
    long long rr, tt;
    cin>>rr>>tt;
    //(r + 1) * (r + 1) -  r * r = r + r + 1
    long res = 0;
    r = rr;
    t = tt;
    while(t > 0){
      // 100進める
      lli tmp = 1000 * (r + r + 1) + 4 * (0 + 999) * 1000 / 2;
      if(t > tmp){
        t -= tmp;
        r += 2000;
        res += 1000;
      }
      t -= r + r + 1;
      r += 2;
      if(t < 0)break;
      res++;
    }
    cout << "Case #" << tc << ": " << res << endl;
  }
}
