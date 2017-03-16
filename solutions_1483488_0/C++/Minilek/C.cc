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
long long A, B;
int main() {
  int nocases;
  int t[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
  char buf[50];
  cin >> nocases;
  for (int rr = 1; rr <= nocases; ++rr) {
    int ret = 0;
    cin >> A >> B;
    for (int i = A; i <= B; ++i) {
      int ndigs = 0, x = i;
      while (x)
	ndigs++, x /= 10;
      int head = 0, fac = 1, tens = t[ndigs - 1];
      x = i;
      set<int> S;
      for (int j = 0; j < ndigs-1; ++j) {
	int z = x%10;
	head = fac*z + head;
	fac *= 10;
	x /= 10;
	int q = head*tens + x;
	if (z && q>i && q<=B && S.find(q) == S.end())
	  ++ret, S.insert(q);
	tens /= 10;
      }
    }
    printf("Case #%d: %d\n", rr, ret);
  }
  return 0;
}
