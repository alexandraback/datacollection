#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  int t;
  cin >> t;
  int tc =1;
  while(t--){
    int n;
    cin >> n;
    int ans = 0;
    if( n == 1 ){
      int d1,h1,m1;
      cin >> d1 >> h1 >> m1;
    }else if( n == 2 ){
      int d1,d2,h1,h2,m1,m2;
      cin >> d1 >> h1 >> m1;
      cin >> d2 >> h2 >> m2;
      if( d1 < d2 ){
        swap(d1,d2);
        swap(h1,h2);
        swap(m1,m2);
      }
      long double speed1 = m1/360.0;
      long double left1 = (360-d1)*speed1;
      long double speed2 = m2/360.0;
      long double left2 = (360-d2)*speed2;
      
      if( fabs(left1-left2) < 1e-9 ){
        ans = 0;
      }else if( left1 < left2 ){
        if( left1 + m1 <= left2 ){
          ans = 1;
        }else{
          ans = 0;
        }
      }else{
        if( left2 + m2 <= left1 ){
          ans = 1;
        }else{
          ans = 0;
        }
      }
    }
    cout << "Case #" << tc++ << ": " << ans << endl;
  }

}
