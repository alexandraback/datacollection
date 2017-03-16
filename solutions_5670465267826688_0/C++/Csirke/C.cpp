#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

// 1 == 1,
// 2 == i,
// 3 == j,
// 4 == k
const int mult_table[4][4] = {
  {1,  2,  3,  4},
  {2, -1,  4, -3},
  {3, -4, -1,  2},
  {4,  3, -2, -1}
};

int mult(int a, int b) {
  int sign = 0;
  if(a < 0) {
    sign =  1 - sign;
    a = -a;
  }
  if(b < 0) {
    sign = 1 - sign;
    b = -b;
  }
  int res = mult_table[a-1][b-1];
  if(sign) res = -res;
  return res;
}

int main()
{
  int T;
  scanf("%d", &T);
  char line[10002];
  int vals[10000];

  for(int t = 0; t < T; ++t) {
    printf("Case #%d: ", t+1);

    int L, K;
    scanf("%d%d%s", &L, &K, line);
    for(int i = 0; i < L; ++i) {
      vals[i] = line[i] - 'i' + 2;
    }

    int i = 0;
    int rounds = 0;
    int prod = 1;
    while(rounds < 6 && rounds < K && prod != 2) {
      prod = mult(prod, vals[i]);
      ++i;
      if(i == L) {
        i = 0;
        ++rounds;
      }
    }
    if(prod != 2) {
      printf("NO\n");
      continue;
    }
    prod = 1;
    while(rounds < 12 && rounds < K && prod != 3) {
      prod = mult(prod, vals[i]);
      ++i;
      if(i == L) {
        i = 0;
        ++rounds;
      }
    }
    if(prod != 3 || rounds == K) {
      printf("NO\n");
      continue;
    }
    prod = 1;
    while(i < L) {
      prod = mult(prod, vals[i]);
      ++i;
    }
    i = 0;
    ++rounds;
    int left = (K - rounds) % 4;
    for(int lefti = 0; lefti < left; ++lefti) {
      for(int i = 0; i < L; ++i) {
        prod = mult(prod, vals[i]);
      }
    }
    if(prod == 4) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
