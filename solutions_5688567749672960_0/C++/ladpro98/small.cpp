#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, a, b) for(int i = (a); i <=(b); ++i)
#define REPD(i, a, b) for(int i = (a); i >=(b); --i)
#define TR(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define RESET(a, v) memset(a, (v), sizeof(a))
#define SZ(a) (int(a.size()))
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
#define VII vector<II>
#define endl '\n'

using namespace std;

queue<int> Q;

const int N = 1000006;

bool was[N];
int d[N];
int n, nTest;

void push(int v, int dv) {
  if (v >= N) return;
  if (was[v]) return;
  was[v] = 1;
  d[v] = dv;
  Q.push(v);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  cin >> nTest;
  Q.push(1); was[1] = 1;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    int du = d[u];
    push(u + 1, du + 1);
    int v = 0;
    while (u > 0) {
      v = v * 10 + u % 10;
      u /= 10;
    }
    push(v, du + 1);
  }
  REP(test, 1, nTest) {
    cin >> n;
    cout << "Case #" << test << ": " << d[n] + 1 << endl;
  }
  return 0;
}
