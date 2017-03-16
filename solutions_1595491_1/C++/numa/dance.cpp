#include <iostream>

using namespace std;

int main(void){
  int t, t0, n, s, p, a, count;
  count = 0;
  cin >> t;
  t0 = t;
  while(t--){
    cin >> n >> s >> p;
    for(int i = 0; i < n; ++i){
      cin >> a;
      if(p > 1){
        if(a >= 3*p - 2)
          count++;
        else{
          if(a >= 3 * p - 4 && s > 0){
            count++;
            s = s - 1;
          }
        }
      }
      else{
        if(p == 0){
          count = n;
        }
        if(p == 1){
          if(a > 0)
            count++;
        }
      }
    }
    cout << "Case #" << t0 - t << ": " << count << endl;
    count = 0;
  }
  return 0;
}
