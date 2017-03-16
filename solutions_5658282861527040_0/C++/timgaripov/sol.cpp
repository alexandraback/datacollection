#include <cstdio>
#include <cassert>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


unsigned int a, b, k;

int main() {
  
  int tests;
  assert(scanf("%d", &tests) == 1);
  for (int test = 0; test < tests; test++) {
    printf("Case #%d: ", test + 1);
    assert(scanf("%u %u %u", &a, &b, &k) == 3);
    int ans = 0;
    for (unsigned int i = 0; i < a; i++)
      for (unsigned int j = 0; j < b; j++)
        if ((j & i) < (unsigned int)(k))
          ans++;
    printf("%d\n", ans);
  }
  
  return 0;
}