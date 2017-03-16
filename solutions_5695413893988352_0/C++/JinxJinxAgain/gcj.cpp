#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

bool match(int x, string p) {
  int digit = 1;
  for(int i = 0; i < p.size(); i++) {
    int mod = x % 10;
    if (mod == p[p.size() - digit] - '0' || p[p.size() - digit] == '?') digit ++;
    else return false;
    x /= 10;
  }
  return true;
}

int main() {
  int T, cas = 1;
  cin >> T;
  // cout << match(19, "1?") << endl;  
  while(T--) {
    string code, jam;
    cin >> code >> jam;
    int coder, jammer;
    int len = code.size();
    int n = 1;
    while(len--) {
      n *= 10;
    }
    //cout << n << endl;
    int ans = 100000;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) { 
        if (abs(i - j) < ans && match(i, code) && match(j, jam)) {
          ans = abs(i - j);
          coder = i, jammer = j;
        }
      }
    }

    cout << "Case #" << cas++ << ": " << setw(code.size()) << setfill('0') << coder << " " << setw(code.size()) << setfill('0') << jammer << endl;
  }
  return 0;
}