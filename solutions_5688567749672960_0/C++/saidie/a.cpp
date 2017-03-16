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

int tbl[1000000];

int rev(int x){
  string s;
  s += to_string(x);
  reverse(s.begin(), s.end());
  return atoi(s.c_str());
}

int main(void){
  int t;
  cin >> t;
  for(int k = 0; k < t; ++k){
    int n;
    cin >> n;
    fill_n(tbl, n+1, INT_MAX);
    tbl[1] = 1;
    for(int i = 1; i < n; ++i){
      int f = rev(i);
      // cout << i << " => " << f << endl;
      if(f <= n)
        tbl[f] = min(tbl[f], tbl[i]+1);
      tbl[i+1] = min(tbl[i+1], tbl[i]+1);
    }
    cout << "Case #" << k+1 << ": " << tbl[n] << endl;
  }
  return 0;
}
