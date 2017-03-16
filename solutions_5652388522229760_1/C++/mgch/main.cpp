#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <set>
#include <map>
#include <complex>
#include <iostream>
#include <time.h>
#include <stack>
#include <stdlib.h>
#include <memory.h>
#include <bitset>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int MaxN = 1e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;

set < int > st;

void f(long long x) {
  while (x > 0) {
    st.insert(x % 10);
    x /= 10;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int it = 1; it <= t; ++it) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: ", it);
    if (n == 0) {
      printf("INSOMNIA\n");
    } else {
      st.clear();
      int val = 0;
      while (true) {
        val += n;
        f(val);
        if (st.size() == 10) {
          break;
        }
      }
      printf("%d\n", val);
    }
  }
  return 0;
}

