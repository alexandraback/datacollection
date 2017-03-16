#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stdio.h>
#include <set>
#include <assert.h>
using namespace std;
vector<int> mv(int a, int b, int c) { vector<int> v = vector<int>(3); v[0] = a, v[1] = b, v[2] = c; return v; }
int main() {
  int nocases;
  cin >> nocases;
  for (int rr = 1; rr <= nocases; ++rr) {
    int n, ret = 0;
    vector< vector<int> > b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      b.push_back(mv(y, x, i));
    }
    sort(b.begin(), b.end());
    int s = 0, taken[n];
    memset(taken, 0, sizeof(taken));
    for (int i = 0; i < n; ++i) {
      while (s < b[i][0]) {
	int at = n - 1;
	while (at>=i && (b[at][1]>s || taken[b[at][2]])) --at;
	if (at<i) {
	  printf("Case #%d: Too Bad\n", rr);
	  goto done;
	} else {
	  taken[b[at][2]] = 1;
	  ++s, ++ret;
	}
      }
      s++;
      if (!taken[b[i][2]]) ++s;
      taken[b[i][2]] = 1;
    }
    printf("Case #%d: %d\n", rr, ret+n);
  done:
    ;
  }
  return 0;
}
