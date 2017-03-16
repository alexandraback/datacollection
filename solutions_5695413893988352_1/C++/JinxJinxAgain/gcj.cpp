#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <set>
#define maxn 22
#define X first
#define Y second

using namespace std;

long long myabs(long long x) {
  return x > 0 ? x : -x;
}

int main() {
  int T, cas = 1;
  cin >> T;
  while(T--) {
    string coder, jammer;
    cin >> coder >> jammer;
    
    int n = coder.size();

    long long ans = -1;
    string ac, aj;
    int start = 0;
    for(; start < n; start ++) if (coder[start] == '?' || jammer[start] == '?') break;
    for(int f = 0; f <= 9; f++) {
      for(int s = 0; s <= 9; s++) {
        int equal = 0;
        string code = coder, jam = jammer;
        if (code[start] == '?') code[start] = f + '0';
        if (jam[start] == '?') jam[start] = s + '0';

        for(int i = 0; i < n; i++) {
          if (equal == 0) {
            if (code[i] == '?' && jam[i] == '?') code[i] = jam[i] = '0';
            else if (code[i] == '?') code[i] = jam[i];
            else if (jam[i] == '?') jam[i] = code[i];
            else {
              
              if (code[i] > jam[i]) equal = 1;
              else if (code[i] < jam[i]) equal = -1;
            }
          } else if (equal == -1) {
            // cout << "<" << endl;
            if (code[i] == '?' && jam[i] == '?') code[i] = '9', jam[i] = '0';
            else if (code[i] == '?') code[i] = '9';
            else if (jam[i] == '?') jam[i] = '0';
          } else if (equal == 1) {
            // cout << ">" << endl;
            if (code[i] == '?' && jam[i] == '?') code[i] = '0', jam[i] = '9';
            else if (code[i] == '?') code[i] = '0';
            else if (jam[i] == '?') jam[i] = '9';
          }
        }

        long long c = 0, j = 0;
        for(int i = 0; i < n; i++) {
          c = c * 10 + code[i] - '0';
          j = j * 10 + jam[i] - '0';
        }
        // cout << "ans = " << ans << endl;
        if (ans == -1) {
          ans = myabs(c - j);
          ac = code;
          aj = jam;
        } else if (myabs(c - j) < ans){
          ans = myabs(c - j);

          ac = code;
          aj = jam;
        }
      }
    }
    cout << "Case #" << cas++ << ": " << ac << " " << aj << endl;
  }
  return 0;
}