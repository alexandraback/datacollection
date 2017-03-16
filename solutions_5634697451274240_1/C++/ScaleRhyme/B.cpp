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
    freopen("B-large.in", "r", stdin);
    freopen("b-large.ans", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc ++) {
      int result = 0;
      char s[200];
      scanf("%s", &s);
      int len = strlen(s) - 1;
      for (; len >= 0; len --) {
        //printf("%d\n", len);
        if (s[len] == '-') {
          if (s[0] == '-') {
            result ++;
            for (int i = 0; len - i >= i; i ++)
            {
              char tmp = s[i];
              s[i] = '+' + '-' - s[len - i];
              if (len - i > i)
                s[len - i] = '+' + '-' - tmp;
            }
          }
          else
          {
            result += 2;
            int k = 0;
            for (; s[k] == '+'; k ++)
              s[k] = '-';
            for (int i = 0; len - i >= i; i ++)
            {
              char tmp = s[i];
              s[i] = '+' + '-' - s[len - i];
              if (len - i > i)
                s[len - i] = '+' + '-' - tmp;
            }
          }
          //printf("%d\t%s\n", result, s);
        }
      }
      printf("Case #%d: %d\n", tc, result);
    }
  return 0;
}
