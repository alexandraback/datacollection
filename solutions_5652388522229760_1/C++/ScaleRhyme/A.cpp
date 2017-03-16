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
  freopen("A-large.in", "r", stdin);
  freopen("a-large.ans", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc ++) {
    int s[10];
    int flag = 0;
    int N;
    scanf("%d", &N);
    memset(s, 0, sizeof(s));
    int result = 0;
    for (int i = 1; i <= 100; i ++) {
      result = i * N;
      for (int k = result; k > 0; k /= 10)
        s[k % 10] ++;
      flag = 1;
      for (int j = 0; j < 10; j ++)
        flag = flag & (s[j] > 0);
      if (flag == 1)
        break;
    }
    if (flag == 0)
      printf("Case #%d: INSOMNIA\n", tc);
    else
      printf("Case #%d: %d\n", tc, result);
  }
  return 0;
}
