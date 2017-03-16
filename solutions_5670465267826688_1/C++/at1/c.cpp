#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()

using namespace std;
typedef long long ll;

int mul[8][8] = {
  {0,1,2,3,4,5,6,7},
  {1,4,3,6,5,0,7,2},
  {2,7,4,1,6,3,0,5},
  {3,2,5,4,7,6,1,0},
  {4,5,6,7,0,1,2,3},
  {5,0,7,2,1,4,3,6},
  {6,3,0,5,2,7,4,1},
  {7,6,1,0,3,2,5,4},
};

int get(char c) {
  assert('i' <= c && c <= 'k');
  return c - 'i' + 1;
}

int fast_pow(int a, long long y) {
  int r = 0;
  for (; y; y >>= 1) {
    if (y & 1) {
      r = mul[r][a];
    }
    a = mul[a][a];
  }
  return r;
}

const int max_iter = (int)1e7;
bool testCase() {
  long long L, x;
  cin >> L >> x;

  string s;
  cin >> s;

  int p = 0;
  for (auto c : s) {
    p = mul[p][get(c)];
  }
  if (fast_pow(p, x) != 4) {
    return false;
  }

  int i = 0;
  auto pos = s.begin();
  p = 0;
  for (; i < x * sz(s) && p != 1; i++) {
    p = mul[p][get(*pos)];
    if (++pos == s.end()) {
      pos = s.begin();
    }

    if (i > max_iter) {
      return false;
    }
  }
  if (p != 1) {
    return false;
  }
//  cerr << i << endl;

  p = 0;
  for (; i < x * sz(s) && p != 2; i++) {
    p = mul[p][get(*pos)];
    if (++pos == s.end()) {
      pos = s.begin();
    }

    if (i > 2 * max_iter) {
      return false;
    }
  }
  if (p != 2) {
    return false;
  }
//  cerr << i << endl;

  return true;
/*
  p = 0;
  for (; i < x * sz(s); i++) {
    p = mul[p][get(s[i])];
  }
  return p == get('k');
 */
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int T;
//  cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    cerr << "Case #" << t << endl;
    cout << "Case #" << t << ": ";
    cout << (testCase() ? "YES" : "NO") << endl;
  }
  return 0;
}
