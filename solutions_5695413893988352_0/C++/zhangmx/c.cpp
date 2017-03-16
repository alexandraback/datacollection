#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

int n, m;
char stra[1000], strb[1000];

bool match(int x, char *str) {
  int len = strlen(str);
  for (int i = len - 1; i >= 0; --i, x /= 10) {
    if (str[i] == '?') continue;
    if (str[i] - '0' != x%10) return false;
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int I = 1; I <= T; ++I) {
    scanf("%s%s", stra, strb);
    int len = strlen(stra);
    printf("Case #%d: ", I);
    int mdiff = 111000;
    int ansa = -1, ansb = -1;
    if (len == 1) {
      for (int a = 0; a < 10; ++a) {
        if (!match(a, stra)) continue;
        for (int b = 0; b < 10; ++b) {
          if (!match(b, strb)) continue;
          if (abs(a-b) < mdiff) {
            mdiff = abs(a-b);
            ansa = a;
            ansb = b;
          }
        }
      }
      printf("%d %d", ansa, ansb);
    } else if (len == 2) {
      for (int a = 0; a < 100; ++a) {
        if (!match(a, stra)) continue;
        for (int b = 0; b < 100; ++b) {
          if (!match(b, strb)) continue;
          if (abs(a-b) < mdiff) {
            mdiff = abs(a-b);
            ansa = a;
            ansb = b;
          }
        }
      }
      printf("%d%d %d%d", ansa/10, ansa%10, ansb/10, ansb%10);
    } else if (len == 3) {
      for (int a = 0; a < 1000; ++a) {
        if (!match(a, stra)) continue;
        for (int b = 0; b < 1000; ++b) {
          if (!match(b, strb)) continue;
          if (abs(a-b) < mdiff) {
            mdiff = abs(a-b);
            ansa = a;
            ansb = b;
          }
        }
      }
      printf("%d%d%d %d%d%d", ansa/100, (ansa%100)/10, ansa%10, ansb/100, (ansb%100)/10, ansb%10);
    }
    printf("\n");
  }
}
