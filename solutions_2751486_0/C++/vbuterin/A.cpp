#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define loop(a,b,c) for (int a = b; a < c; a++) 

using namespace std;

bool vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  int cases; cin >> cases;
  loop (cs,0,cases) {
    string inp;
    cin >> inp;
    long long n = 0, rl = 0, mpos = 0, tot = 0;
    cin >> n;
    loop (i,0,inp.size()) {
      rl++;
      if (vowel(inp[i])) rl = 0;
      if (rl >= n) {
        mpos = i-n+2;
      }
      tot += mpos;
    }
    cout << "Case #" << (cs+1) << ": " << tot << "\n";
  }
}
