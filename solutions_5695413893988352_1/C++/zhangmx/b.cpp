#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

int n, m;
char stra[1000], strb[1000];

int64_t S64(const char *s) {
  int64_t ans = 0;
  for (int i = 0; s[i]; ++i) {
    ans = ans * 10 + (s[i] - '0');
  }
  return ans; 
}

int main() {
  int T;
  scanf("%d", &T);
  for (int I = 1; I <= T; ++I) {
    scanf("%s%s", stra, strb);
    string a = stra;
    string b = strb;
    int len = strlen(stra);

    int64_t diff = 1ll<<63;
    int64_t ansa, ansb;

    int state = 0;
    for (int i = 0; i < len; ++i) {
      if (state == 0) {
        if (stra[i] == '?' && strb[i] == '?') {
          stra[i] = strb[i] = '0';
        } else if (stra[i] == '?' && strb[i] != '?') {
          stra[i] = strb[i];
        } else if (stra[i] != '?' && strb[i] == '?') {
          strb[i] = stra[i];
        } else {
          if (stra[i] > strb[i]) state = 1;
          else if (stra[i] < strb[i]) state = 2;
        }
      } else if (state == 1) {
        if (stra[i] == '?') stra[i] = '0';
        if (strb[i] == '?') strb[i] = '9';
      } else {
        if (stra[i] == '?') stra[i] = '9';
        if (strb[i] == '?') strb[i] = '0';
      }
    }
    ansa = S64(stra);
    ansb = S64(strb);
    diff = ansa - ansb; if (diff < 0) diff = -diff;
    for (int i = 0; i < len; ++i) {
      stra[i] = a[i];
      strb[i] = b[i];
    }
    // printf("==%lld %lld %lld\n", ansa, ansb, diff);
    for (int i = 0; i < len; ++i) {
      if (stra[i] == '?' && strb[i] == '?') {
        // a > b
        stra[i] = '1'; strb[i] = '0';
        for (int j = i + 1; j < len; ++j) {
          if (stra[j] == '?') stra[j] = '0';
          if (strb[j] == '?') strb[j] = '9';
        }
        int64_t xa = S64(stra);
        int64_t xb = S64(strb);
        int64_t dd = xa - xb; if (dd < 0) dd = -dd;
        if (dd < diff) {
          diff = dd;
          ansa = xa;
          ansb = xb;
        } else if (dd == diff && ansa > xa) {
          diff = dd;
          ansa = xa;
          ansb = xb;
        } else if (dd == diff && ansa == xa && ansb > xb) {
          diff = dd;
          ansa = xa;
          ansb = xb;
        }
        for (int j = i; j < len; ++j) {
          stra[j] = a[j];
          strb[j] = b[j];
        }
        // b > a
        stra[i] = '0'; strb[i] = '1';
        for (int j = i + 1; j < len; ++j) {
          if (stra[j] == '?') stra[j] = '9';
          if (strb[j] == '?') strb[j] = '0';
        }
         xa = S64(stra);
         xb = S64(strb);
         dd = xa - xb; if (dd < 0) dd = -dd;
        if (dd < diff) {
          diff = dd;
          ansa = xa;
          ansb = xb;
        } else if (dd == diff && ansa > xa) {
          diff = dd;
          ansa = xa;
          ansb = xb;
        } else if (dd == diff && ansa == xa && ansb > xb) {
          diff = dd;
          ansa = xa;
          ansb = xb;
        }
        for (int j = i; j < len; ++j) {
          stra[j] = a[j];
          strb[j] = b[j];
        }
        // a == b
        stra[i] = strb[i] = '0';
      } else if (stra[i] == '?' && strb[i] != '?') {
        // a > b
        if (strb[i] != '9') {
          stra[i] = strb[i] + 1;
          for (int j = i + 1; j < len; ++j) {
            if (stra[j] == '?') stra[j] = '0';
            if (strb[j] == '?') strb[j] = '9';
          }
          int64_t xa = S64(stra);
          int64_t xb = S64(strb);
          int64_t dd = xa - xb; if (dd < 0) dd = -dd;
          if (dd < diff) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          } else if (dd == diff && ansa > xa) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          } else if (dd == diff && ansa == xa && ansb > xb) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          }
          for (int j = i; j < len; ++j) {
            stra[j] = a[j];
            strb[j] = b[j];
          }
        }
        // b > a
        if (strb[i] != '0') {
          stra[i] = strb[i] - 1;
          // printf("HERE %d %c %s %s\n", i, stra[i], stra, strb);
          for (int j = i + 1; j < len; ++j) {
            if (stra[j] == '?') stra[j] = '9';
            if (strb[j] == '?') strb[j] = '0';
          }
          int64_t xa = S64(stra);
          int64_t xb = S64(strb);
          int64_t dd = xa - xb; if (dd < 0) dd = -dd;
          // printf("HERE %lld %lld %s %s\n", xa, xb, stra, strb);
          if (dd < diff) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          } else if (dd == diff && ansa > xa) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          } else if (dd == diff && ansa == xa && ansb > xb) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          }
          for (int j = i; j < len; ++j) {
            stra[j] = a[j];
            strb[j] = b[j];
          }
        }
        // a == b
        stra[i] = strb[i];
      } else if (stra[i] != '?' && strb[i] == '?') {
        // a > b
        if (stra[i] != '0') {
          strb[i] = stra[i] - 1;
          for (int j = i + 1; j < len; ++j) {
            if (stra[j] == '?') stra[j] = '0';
            if (strb[j] == '?') strb[j] = '9';
          }
          int64_t xa = S64(stra);
          int64_t xb = S64(strb);
          int64_t dd = xa - xb; if (dd < 0) dd = -dd;
          if (dd < diff) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          } else if (dd == diff && ansa > xa) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          } else if (dd == diff && ansa == xa && ansb > xb) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          }
          for (int j = i; j < len; ++j) {
            stra[j] = a[j];
            strb[j] = b[j];
          }
        }
        // b > a
        if (stra[i] != '9') {
          strb[i] = stra[i] + 1;
          for (int j = i + 1; j < len; ++j) {
            if (stra[j] == '?') stra[j] = '9';
            if (strb[j] == '?') strb[j] = '0';
          }
          int64_t xa = S64(stra);
          int64_t xb = S64(strb);
          int64_t dd = xa - xb; if (dd < 0) dd = -dd;
          if (dd < diff) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          } else if (dd == diff && ansa > xa) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          } else if (dd == diff && ansa == xa && ansb > xb) {
            diff = dd;
            ansa = xa;
            ansb = xb;
          }
          for (int j = i; j < len; ++j) {
            stra[j] = a[j];
            strb[j] = b[j];
          }
        }
        // a == b
        strb[i] = stra[i];
      } else {
        if (stra[i] != strb[i]) break;
      }
      // printf("== %d %lld %lld %lld\n", i, ansa, ansb, diff);
    }
    

    printf("Case #%d: ", I);
    for (int i = len - 1; i >= 0; --i) {
      stra[i] = '0' + ansa%10; ansa/=10;
      strb[i] = '0' + ansb%10; ansb/=10;
    }
    printf("%s %s", stra, strb);
    printf("\n");
  }
}
