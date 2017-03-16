#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1000000;

int bfs[N+1];
long long n;

inline long long rev(long long x) {
  long long r = 0;
  while (x) {
    r = r * 10 + x % 10;
    x /= 10;
  }
  return r;
}

int main() {
  memset(bfs, 0xff, sizeof(bfs));
  bfs[0] = 0; bfs[1] = 1;
  static long long q[N+1];
  int get = 0, put = 0;
  q[put++] = 1;
  while (get < put) {
    long long curr = q[get++];
    long long next = curr + 1;
    if (next <= N && bfs[next] < 0) bfs[next] = bfs[curr]+1, q[put++] = next;
    next = rev(curr);
    if (next <= N && bfs[next] < 0) bfs[next] = bfs[curr]+1, q[put++] = next;
  }

  int tests; cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    cin >> n;
    cout << "Case #" << tc << ": " << bfs[n] << endl;
  }

  return 0;
}

