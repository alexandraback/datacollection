#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    int n, t;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      v.push_back(t);
    }
    int ret = 1000000;
    for (int x = 1; x <= 1000; ++x) {
      int tot = 0;
      for (int i = 0; i < v.size(); ++i)
	tot += (v[i]+x-1)/x - 1;
      ret = min(ret, x + tot);
    }
    printf("Case #%d: %d\n", rr, ret);
  }
  return 0;
}
