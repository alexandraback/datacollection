#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

void docase(int icase) {
  int x1 = 0, y1 = 0, x2, y2;
  scanf("%d %d", &x2, &y2);

  printf("Case #%d: ", icase);

  int n = 1;

  while (x1 != x2) {
    if (x1 < x2) {
      if (x1 + n <= x2) {
        x1 += n;
        printf("E");
        n++;
      } else {
        x1++;
        printf("WE");
        n += 2;
      }
    } else {
      if (x1 - n >= x2) {
        x1 -= n;
        printf("W");
        n++;
      } else {
        x1--;
        printf("EW");
        n += 2;
      }
    }
  }

  while (y1 != y2) {
    if (y1 < y2) {
      if (y1 + n <= y2) {
        y1 += n;
        printf("N");
        n++;
      } else {
        y1++;
        printf("SN");
        n += 2;
      }
    } else {
      if (y1 - n >= y2) {
        y1 -= n;
        printf("S");
        n++;
      } else {
        y1--;
        printf("NS");
        n += 2;
      }
    }
  }
  
  puts("");
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++)
    docase(i + 1);

  return 0;
}
