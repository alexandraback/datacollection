#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int t0, t = 0;
  int n, s[200], x, safety, ss;
  double y[200], m;
  bool flg;

  cin >> t0;
  t = t0;
  while(t--){
    for(int i = 0; i < 200; ++i){
      s[i] = 0;
      y[i] = 0;
    }
    x = 0; safety = 0; ss = 0;flg = false;
    cin >> n;
    for(int i = 0; i < n; ++i){
      cin >> s[i];
      x += s[i];
    }
    int safety0 = 1;
    while(safety0 != safety){
      m = (double)(2*x - ss)/(n - safety);
      safety0 = safety;
      for(int i = 0; i < n; ++i){
        if(s[i] >= m && y[i] != -1){
          y[i] = -1;
          safety++;
          ss += s[i];
        }
      }
    }
    for(int i = 0; i < n; ++i){
      if(y[i] == -1)
        y[i] = 0;
      else
        y[i] = (double)(m - s[i])*100/x;
    }    
    cout << "Case #" << t0 - t << ": ";

    for(int i = 0; i < n; ++i){
      if(y[i] < 0)
        y[i] = 0;
      printf("%lf ", y[i]);
    }
    cout << endl;
  }
  return 0;
}

