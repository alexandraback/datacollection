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

using namespace std;

#define OSS ostringstream
#define ISS istringstream
#define CAST(x,type)  *({OSS oss; oss << (x); ISS iss(oss.str()); static type _r; iss >> _r; &_r; })

struct Problem {
  int64_t N, M;

  void Input() {
    scanf("%lld %lld", &N, &M);
  }

  void Solve() {
    int64_t res = 0;
    for (int64_t x = N; x <= M; x++) {
      string X = CAST(x, string);
      set<int64_t> s;
      for (int i = 1; i < X.length(); i++) {
        string Y = X.substr(i) + X.substr(0, i);
        int64_t z = CAST(Y, int64_t);
        string Z = CAST(z, string);
        if (X.length() == Z.length() && s.count(z) == 0 && x < z && z <= M) {
          s.insert(z);
          res++;
        }
      }
    }
    printf("%lld", res);
  }

}; // struct Problem


int main() {
  int T;
  scanf("%d", &T);
  for (int testCase = 1; testCase <= T; ++testCase) {
    printf("Case #%d: ", testCase);
    Problem p;
    p.Input();
    p.Solve();
    printf("\n");
  }

  return 0;
}
