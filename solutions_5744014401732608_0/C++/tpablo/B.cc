#include <bits/stdc++.h>

using namespace std;


void test() {
  static int c;
  cout << "Case #" << ++c << ": ";
  
  int b;
  int64_t m;
  cin >> b >> m;
  
  int64_t max = int64_t(1) << (b - 2);
  
  if(m > max) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  
  cout << "POSSIBLE\n";
  
  vector<int> lc(b, 0);
  
  if(m == max) {
    for(int i = 0; i < b - 1; ++i) lc[i] = 1;
  } else {
    for(int i = 1; i < b - 1; ++i) {
      if(m & 1) lc[i] = 1;
      m >>= 1;
    }
  }
  
  for(int i = 0; i < b; ++i) {
    for(int j = 0; j < b - 1; ++j) {
      cout << char('0' + (j > i));
    }
    cout << lc[i] << '\n';
  }
}


int main() {
  int t;
  cin >> t;
  
  while(t --> 0) test();
  
  return 0;
}
