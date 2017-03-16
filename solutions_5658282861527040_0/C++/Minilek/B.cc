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
    int a, b, k;
    cin >> a >> b >> k;
    int ret = 0;
    for (int i = 0; i < a; ++i)
      for (int j = 0; j < b; ++j)
	if ((i&j) < k) 
	  ++ret;
    printf("Case #%d: %d\n", rr, ret);
  }
  return 0;
}
