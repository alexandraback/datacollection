#include<iostream>
#include<cmath>
using namespace std;

void solve(){
   int r,t;
   cin >> r >> t;
   int cnt = 0;
   for( ; ; cnt++){
      int now = 4*cnt + 1 + 2*r;
      if(t - now < 0)break;
      t -= now;
   }
   cout << cnt << endl;
}

int main(){
   int tc;
   cin >> tc;
   for(int i = 1 ; i <= tc ; i++){
      cout << "Case #" << i << ": ";
      solve();
   }
   return 0;
}
