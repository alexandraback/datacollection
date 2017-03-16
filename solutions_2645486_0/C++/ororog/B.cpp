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

int E, R, N;
int v[11111];

int dps[22][22];

int small() {
  memset(dps, -1, sizeof(dps));
  dps[0][E] = 0;
  for (int day = 0; day < N; day++) {
    for (int e = 0; e <= E; e++) {
      if (dps[day][e] == -1) continue;
      for (int i = 0; i <= e; i++) {
        dps[day+1][min(e-i+R, E)] = max(dps[day+1][min(e-i+R, E)], dps[day][e] + i * v[day]);
      }
    }
  }
  int res = -1;
  REP(i, N+1){
    REP(j, E+1) {
      res = max(dps[i][j], res);
    }
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  REP(testcase, T) {
    cin >> E >> R >> N;
    REP(i, N) v[i] = nextInt();
    printf("Case #%d: %d\n", testcase + 1, small());
  }
}
