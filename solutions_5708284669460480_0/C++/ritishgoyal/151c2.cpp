#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

#define rep(i, n) for(int i=0;i<n;i++)

int main() {
  int test; cin>> test;
  rep(z, test) {
    int k, l, s;
    double rep = 0.0, max = 0.0, ans = 1.0, pre = 1.0, w = 1.0;
    char temp;
    bool x = 1;
    cin>>k>>l>>s;
    char str[l];
    double p[26];
    rep(i, 26) {
      p[i] = 0.0;
    }
    rep(i, k) {
      cin>>temp;
      p[(temp - 'A')] += 1;
    }
    rep(i, 26) {
      p[i] /= k;
    }
    rep(i, l) {
      cin>>str[i];
    }
    for(int i = 1; i<l; i++) {
      for(int j=0; j<(l-i) ; i++) {
	x = x && (str[i] == str[j]);
      }
      if(x) {
	rep += i;
	break;
      }
    }
    rep(i, l) {
      w *= p[str[i] - 'A'];
      ans = w;
    }
    if(ans != 0.0) {
      if(rep == 0) {
	max += s/l;
      }
      else
      max = 1.0 + ((s-l)/rep);
      for(int i = rep; i <l; i++) {
	pre *= p[str[i] - 'A'];
      }
      for(int i = max; i >1; i--) {
	ans += max*(max-1)*pre*w;
      }
      if(w == 1.0) {
	ans = 0.0;
      }
      else ans = max - ans;
    }
    printf("Case #%d: %.6lf\n", z+1, ans);
  }
}
      
