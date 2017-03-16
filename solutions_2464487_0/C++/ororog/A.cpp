#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <cmath>

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define MP(a, b) make_pair(a, b)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int nextInt() {
  char c;
  int res = 0;
  while (!isdigit(c = getchar())){};
  do {
    res = res * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return res;
}

int sq(int r) {return r * r;};
int r,t;
int small(){
  long long s = 0;
  for (int i = 0;; i++) {
    s += sq(r + 1) - sq (r);
    //cout << s << endl;
    if (s > t) return i;
    r += 2;
  }
};

int main() {
  int T;
  cin >> T;
  REP(testcase, T) {
    cin >> r >> t;
    printf("Case #%d: %d\n", testcase + 1, small());
  }
}
