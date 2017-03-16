#include <iostream>

using namespace std;

int main(void){
  int t0,t,n, i0, i, j;
  int num[20], b[20];
  int table[1024 * 1024];
  int f;

  for(i = 0; i < 1024 * 1024; ++i)
    table[i] = 0;
  cin >> t0;
  t = t0;
  
  while(t--){
    for(i = 0; i < 1024 * 1024; ++i)
      table[i] = 0;
    cin >> n;
    for(i = 0; i < n; ++i)
      cin >> num[i];
    for(i = 0; i < 1024 * 1024; ++i){
      f = 0;
      i0 = i;
      for(j = 0; j < 20; ++j){
        b[j] = i0 & 1;
        i0 = i0 >> 1;
      }
      for(j = 0; j < 20; ++j)
        table[i] += b[j]*num[j];
      for(j = 0; j < i; ++j){
        if(table[i] == table[j]){
          f = 1;
          break;
        }
      }
      if(f)
        break;
    }
    cout << "Case #" << t0 - t << ":" << endl;
    if(f){
      //iに対応する集合の出力
      for(int k = 0; k < 20; ++k){
        if(i & 1)
          cout << num[k] << ' ';
        i = i >> 1;
      }
      cout << endl;
      //jに対応する集合の出力
      for(int k = 0; k < 20; ++k){
        if(j & 1)
          cout << num[k] << ' ';
        j = j >> 1;
      }
      cout << endl;
    }
    else
      cout << "Impossible" << endl;
  }
  return 0;
}
