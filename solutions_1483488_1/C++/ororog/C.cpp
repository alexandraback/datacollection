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



long long solve(long long a, long long b) {
  set<pair<int, int> > st;
  int res = 0;
  if (b / a >= 10) return 0;
  long long n = 0, v;
  v = a;
  long long largebase = 1;
  while (v) n++, v/=10;
  REP(i, n) largebase *= 10;
  for (long long i = a; i <= b; i++) {
    long long base = 10;
    long long rbase = largebase / 10;
    REP(j, n-1) {
      long long recycled = (i * base) % largebase + i / rbase;
      if (a <= recycled && i < recycled && recycled <= b) res++,
                                                            st.insert(make_pair(i, recycled));
      base *= 10;
      rbase /= 10;
    }
  }
  return st.size();;
}

int main() {
  int TESTCASE = nextInt();
  REP(tt, TESTCASE) {
    int a = nextInt(), b = nextInt();
    printf("Case #%d: %d\n", tt+1, solve(a, b));
  }
}
