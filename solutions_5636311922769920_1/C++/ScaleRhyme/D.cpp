#ifndef FLLD
#ifdef WIN32
#define FLLD "%I64d"
#else
#define FLLD "%lld"
#endif
#endif

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <ctime>
#include <tuple>
#include <random>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define NOKEY(x,y) ((x).find(y) == (x).end())
#define EXISTKEY(x,y) ((x).find(y) != (x).end())
#define INCMAP(x, y) ((x)[y] = MAPINTV(x, y) + 1)
#define MAPINTV(x, y) (EXISTKEY(x, y) ? (x)[y] : 0)
typedef long long ll;

using namespace std;

int main() {
  freopen("D-large.in", "r", stdin);
  freopen("D-large.ans", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc ++) {
    int k, c, s;
    scanf("%d%d%d", &k, &c, &s);
    if (s * c >= k) {
      printf("Case #%d:", tc);
      for (int i = 0; i < k; i += c) {
        long long res = 0;
        for (int j = 0; j < c; j ++) {
          res = res * k;
          if (i + j < k)
            res += (i + j);
        }
        res ++;
        printf(" " FLLD, res);
      }
      printf("\n");
    }
    else
    {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    }
  }
  return 0;
}
