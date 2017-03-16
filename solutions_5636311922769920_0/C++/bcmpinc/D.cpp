#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cassert>

using namespace std;

typedef long long int ll;

void dostep() {
  int k,c,s;
  cin >> k >> c >> s;
  if (k > c*s) {
    cout << " IMPOSSIBLE" << endl;
    return;
  }
  ll mk = 1;
  for (int bit=0; bit<c; bit++) mk *= k;
  
  int i = 0;
  int j = 0;
  while(i<k) {
    ll pos=0;
    for (int bit=0; bit<c; bit++) {
      pos *= k;
      pos += i%k;
      i++;
    }
    assert(pos < mk);
    cout << " " << pos+1;
    j++;
  }
  fflush(stdout);
  assert(j <= s);
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ":";
    dostep();
  }
  return 0;
}
 
