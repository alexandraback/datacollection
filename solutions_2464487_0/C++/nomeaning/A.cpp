#include <iostream>
using namespace std;
int T;
typedef long long lli;
int main(){
  cin>>T;
  for(int tc=1;tc<=T;tc++){
    lli r,t;
    cin>>r>>t;
    //(r + 1) * (r + 1) -  r * r = r + r + 1
    long res = 0;

    while(t > 0){
      t -= r + r + 1;
      r += 2;
      if(t < 0)break;
      res++;
    }
    cout << "Case #" << tc << ": " << res << endl;
  }
}
