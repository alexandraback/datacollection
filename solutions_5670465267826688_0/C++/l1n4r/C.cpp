
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;

enum { e_1, e_i, e_j, e_k, e_m_1, e_m_i, e_m_j, e_m_k };

int mlt[4][4] = {{e_1, e_i, e_j, e_k},
                 {e_i, e_m_1, e_k, e_m_j},
                 {e_j, e_m_k, e_m_1, e_i},
                 {e_k, e_j, e_m_i, e_m_1}};

int ch2el(const char c) { return e_i + c - 'i'; }

bool isneg(const int a) { return a >= e_m_1; }

int mns(const int a) { return (isneg(a)) ? a - 4 : a + 4; }

int pos(const int a) { return (isneg(a)) ? mns(a) : a; }

int mult(const int a, const int b) {
  const bool neg = isneg(a) ^ isneg(b);
  const int p = mlt[pos(a)][pos(b)];
  return (neg) ? mns(p) : p;
}

char s[10004];
int r[10004];

int main() {
  int test_cases;
  scanf("%d", &test_cases);

  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int l, x;
    scanf("%d %d", &l, &x);
    scanf("%s", s);

    const int n = l * x;
    for (int i = 1; i < x; i++) {
      for (int j = 0; j < l; j++) {
        s[l * i + j] = s[j];
      }
    }
    s[n] = '\0';

    r[n - 1] = ch2el(s[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
      r[i] = mult(ch2el(s[i]), r[i + 1]);
    }

    bool yes = false;
    int p1 = e_1;
    for (int i = 0; i < n; i++) {
      p1 = mult(p1, ch2el(s[i]));
      if (p1 == e_i) {
        int p2 = e_1;
        for (int j = i + 1; j + 1 < n; j++) {
          p2 = mult(p2, ch2el(s[j]));
          if (p2 == e_j && r[j + 1] == e_k) {
            yes = true;
            break;
          }
        }
        if (yes) {
          break;
        }
      }
    }

    printf("Case #%d: %s\n", test_case, (yes) ? "YES" : "NO");
  }

  return 0;
}