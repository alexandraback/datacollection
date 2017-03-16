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
int main() {
  int nocases;
  cin >> nocases;
  for (int rr = 1; rr <= nocases; ++rr) {
    int n, s, p;
    cin >> n >> s >> p;
    int a[n];
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      if (p == 0)
	++ret;
      else if (p == 1 && a[i] >= 1)
	++ret;
      else if (p > 1)
	if (a[i] >= 2*(p-1) + p)
	  ++ret;
	else if (s && a[i] >= 2*(p-2) + p)
	  ++ret, --s;
    }
    printf("Case #%d: %d\n", rr, ret);
  }
  return 0;
}
