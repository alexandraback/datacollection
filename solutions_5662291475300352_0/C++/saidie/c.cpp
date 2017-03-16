#include <iostream>
#include <cmath>
#include <cassert>
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

int n;
int d[1000];
int h[1000];
int m[1000];

// small 1
ll p[2];
ll s[2];

int main(void){
  int t;
  cin >> t;
  for(int k = 0; k < t; ++k){
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
      cin >> d[i] >> h[i] >> m[i];

      // small 1
      if(h[i] == 2) {
        p[0] = p[1] = d[i];
        s[0] = m[i];
        s[1] = m[i]+1;
        cnt += 2;
      }
      else {
        assert(h[i] == 1);
        p[cnt] = d[i];
        s[cnt] = m[i];
        ++cnt;
      }
    }
    assert(cnt == 1 || cnt == 2);

    if(cnt == 2 && s[0] > s[1]){
      swap(p[0], p[1]);
      swap(s[0], s[1]);
    }

    cout << "Case #" << k+1 << ": ";
    if(cnt == 1) {
      cout << 0 << endl;
    }
    else {
      if ( (360 - p[1]) * s[1] < (720 - p[0]) * s[0] )
        cout << 0 << endl;
      else
        cout << 1 << endl;
    }
  }
  return 0;
}
