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

int main() {
  int TESTCASE = 0;
  cin >> TESTCASE;
  REP(i, TESTCASE) {
    int N, S, P;
    cin >> N >> S >> P;
    vector<int> g;
    REP(i, N) {
      g.push_back(nextInt());
    }
    int res = 0;
    REP(i, N) {
      if (g[i] >= P*3 - 2)
        res++;
      else if (P*3-4 >= 0 && g[i] >= P*3-4 && S > 0)
        res++, S--;
    }
    printf("Case #%d: %d\n", i+1, res);
  }
}
