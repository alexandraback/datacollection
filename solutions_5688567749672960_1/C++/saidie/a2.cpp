#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

int rev(ll x){
  string s;
  s += to_string(x);
  reverse(s.begin(), s.end());
  return atoi(s.c_str());
}

ll modulo(ll x){
  int cnt = 0;
  while(x > 0){
    ++cnt;
    x /= 10;
  }
  cnt /= 2;
  x = 1;
  while(--cnt >= 0)
    x *= 10;
  return x;
}

int main(void){
  int t;
  cin >> t;
  for(int k = 0; k < t; ++k){
    ll n;
    cin >> n;

    int res = 0;
    while(n > 1) {
      if(n % modulo(n) == 1){
        if(rev(n) < n)
          n = rev(n);
        else
          --n;
      }
      else
        --n;
      ++res;
    }

    cout << "Case #" << k+1 << ": " << res+1 << endl;
  }
  return 0;
}
