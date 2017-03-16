#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 2000000;
int steps[MAXN];

int rev(int i) {
  int o = 0;
  while (i) {
    o *= 10;
    o += i % 10;
    i /= 10;
  }
  return o;
}

int solve(int N) {
  queue<int> q;
  q.push(1);
  steps[1] = 1;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    int s = steps[k];
    if (k == N) return s;
    if (steps[k + 1] == -1) {
      steps[k + 1] = s + 1;
      q.push(k + 1);
    }
    int kr = rev(k);
    if (steps[kr] == -1) {
      steps[kr] = s + 1;
      q.push(kr);
    }
  }
  return -1;
}

int main() {
  int T;
  scanf("%d", &T);
  REP(t,T) {
    int N;
    scanf("%d", &N);
    REP(i,N+1) steps[i] = -1;
    printf("Case #%d: %d\n", t+1, solve(N));
  }
  return 0;
}
