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

int k, l, s;
string keys, target;
int f[256];
double p[256];
string d;
int hh[128][256];
bool known[128][128];
double dp[128][128];

bool ok(int b, int a) {
  if (b >= a+target.size()) return true;
  string suffix = target.substr(b-a);
  for (int i = 0; i < suffix.size(); i++) if (target[i] != suffix[i]) return false;
  return true;
}

int getMin() {
  int lo = 1, lastPos = 0;
  for (int i = 1; i+target.size() <= s; i++) {
    if (ok(i, lastPos))
      lo++, lastPos = i;
  }
  return lo;
}

int nextHit(int hits, char next) {
  if (hh[hits][next] >= 0) return hh[hits][next];

  string s = target.substr(0, hits);
  s += next;

  if (target[hits] == next) {
    if (hits+1 == target.size()) {
      s = s.substr(1);
      while (s.size() > 0) {
        if (target.substr(0, s.size()) == s) break;
        s = s.substr(1);
      }
      return hh[hits][next] = s.size();
    }
    return hh[hits][next] = hits+1;
  }

  s = s.substr(1);
  while (s.size() > 0) {
    if (target.substr(0, s.size()) == s) break;
    s = s.substr(1);
  }
  return hh[hits][next] = s.size();
}

double go(int i, int hits) {
  if (known[i][hits]) return dp[i][hits];
  known[i][hits] = true;
  if (i+hits == s) return dp[i][hits] = 0;

  double res = 0;
  for (int j = 0; j < d.size(); j++) {
    double pp = p[d[j]];

    if (target[hits] == d[j]) {
      if (hits+1 == target.size()) {
        // complete hit
        int h = nextHit(hits, d[j]);
        res += (1 + go(i+target.size()-h, h)) * pp;
      } else {
        int h = hits+1;
        res += go(i, h) * pp;
      }
    } else {
      int h = nextHit(hits, d[j]);
      res += go(i+hits+1-h, h) * pp;
    }
  }
  return dp[i][hits] = res;
}

double go() {
  memset(known, 0, sizeof(known));
  memset(hh, 0xff, sizeof(hh));
  memset(f, 0, sizeof(f));
  d = "";
  for (int i = 0; i < keys.size(); i++) if (f[keys[i]]++ == 0) d += keys[i];
  for (int i = 0; i < d.size(); i++) p[d[i]] = double(f[d[i]]) / k;

  bool valid = true;
  for (int i = 0; i < target.size(); i++) if (f[target[i]] == 0) valid = false;
  if (!valid) return 0;

  int lo = getMin();
  return lo-go(0, 0);
}

int main() {
  int tests; cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    cin >> k >> l >> s;
    cin >> keys >> target;
    printf("Case #%d: %.7f\n", tc, go());
  }
  return 0;
}

