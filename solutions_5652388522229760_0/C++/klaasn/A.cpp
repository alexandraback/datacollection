/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

// how to detect digits
int digits(int n) {
  int mask = 0;
  if (n == 0) return 1;
  while (n > 0) {
    int d = n % 10;
    mask |= 1 << d;
    n = n / 10;
  }
  return mask;
}

int f(int n) {
  int mask = 0;
  for(int i=1;i<2100;i++) {
    int m = n * i;
    mask |= digits(m);
    if (mask == (1 << 10) - 1) {
      return m;
    }
  }
  return 0;
}

int main()
{
  assert(digits(0) == 1);
  assert(digits(1) == 2);
  assert(digits(8) == 256);
  assert(digits(9) == 512);
  assert(digits(11) == 2);
  assert(digits(99) == 512);
  assert(digits(18) == 258);

  assert(f(0) == 0);
  assert(f(1) == 10);
  assert(f(2) == 90);
  assert(f(11) == 110);
  assert(f(1692) == 5076);

  int N, M;
  cin >> N;

  for(int i = 1; i<= N ; i++) {
    cin >> M;
    int res = f(M);
    if (res == 0) {
      printf("Case #%d: INSOMNIA\n", i);
    } else {
      printf("Case #%d: %d\n", i, res);
    }
  }
}
