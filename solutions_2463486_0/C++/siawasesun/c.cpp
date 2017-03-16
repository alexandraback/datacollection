#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <inttypes.h>

// Macro
#define foreach(c, i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define mp make_pair
#define ALL(a) (a).begin(), (a).end()
#define OSS ostringstream
#define ISS istringstream
#define CAST(x,type)  *({OSS oss; oss << (x); ISS iss(oss.str()); static type _r; iss >> _r; &_r; })
#define ARRAY_SIZE(x) (sizeof(x) / sizeof( (x)[0]) )

using namespace std;

void CommonInit() {
}

struct Problem {
  int A, B;
  void Input() {
    scanf("%d %d", &A, &B);
  }

  bool IsPalindrome(int n) {
    string s = CAST(n, string);
    int l = s.length();
    for (int i = 0; i < l / 2; ++i) {
      if (s[i] != s[l - 1 - i]) return false;
    }
    return true;
  }

  int Solve() {
    int res = 0;
    for (int i = ceil(sqrt(A)); i * i <= B; i++) {
      if (!IsPalindrome(i)) continue;

      if (IsPalindrome(i * i)) {
        ++res;
      }
    }
    return res;
  }
};

int main() {
  int T;
  scanf("%d", &T);
  CommonInit();
  for (int testCase = 1; testCase <= T; ++testCase) {
    printf("Case #%d: ", testCase);
    Problem p;
    p.Input();
    printf("%d\n", p.Solve());
  }

  return 0;
}
