#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <set>
using namespace std;

char map[32][32];

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int cases;
  scanf("%i", &cases);
  for (int ncase = 1; ncase <= cases; ++ncase) {
    int ly, lx, d;
    scanf("%i%i%i", &ly, &lx, &d);

    int x, y;
    for (int i = 0; i < ly; ++i)
      for (int j = 0; j < lx; ++j) {
        scanf(" %c", &map[i][j]);
        if (map[i][j] == 'X') {
          y = i;
          x = j;
        }
      }
    typedef pair<int, int> pii;
    deque<pii> q;
    q.push_back(pii(0, 0));
    set<pii> queued;
    queued.insert(pii(0, 0));

    lx -= 2; ly -= 2;
    --x; --y;
    set<pii> sv;
    while (!q.empty()) {
      pii p = q.front(); q.pop_front();
      int i = p.first, j = p.second, a, b;

      if (!(i & 1)) a = y; else a = ly - 1 - y;
      if (!(j & 1)) b = x; else b = lx - 1 - x;
      a += i * ly;
      b += j * lx;

      if (i != 0 || j != 0) {
        int dify = a - y, difx = b - x;
        if (dify * dify + difx * difx <= d * d) {
       //   printf("%3i %3i  %3i %3i    %3i %3i\n", i, j, a, b, y, x);
          sv.insert(pii(dify, difx));
        }
      }

      for (int ii = -1; ii <= 1; ++ii)
        for (int jj = -1; jj <= 1; ++jj) {
          int newi = i + ii, newj = j + jj;
          if (abs(newi) <= d + 1 && abs(newj) <= d + 1) {
            if (queued.find(pii(newi, newj)) == queued.end()) {
              queued.insert(pii(newi, newj));
              q.push_back(pii(newi, newj));
            }
          }
        }
    }

    int cnt = 0;
    for (set<pii>::iterator it = sv.begin(); it != sv.end(); ++it) {
      int dy = it->first, dx = it->second,
          g = gcd(abs(dy), abs(dx));
      bool valid = true;
      for (int j = 1; valid && j < g; ++j) {
        int y = dy / g * j, x = dx / g * j;
        if (sv.find(pii(y, x)) != sv.end()) valid = false;
      }
      if (valid) ++cnt;
    }
    printf("Case #%i: %i\n", ncase, cnt);
  }
  return 0;
}
