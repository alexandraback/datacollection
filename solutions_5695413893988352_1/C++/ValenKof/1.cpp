#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define debug(x) std::cerr << "DEBUG: " << #x << " = " << (x) << std::endl
#define mp make_pair
#define pb push_back
#define PATH "C:\\Users\\Valentin\\Desktop\\"

template<class T> inline int sz(const T& x)
{ return (int) x.size(); }

template<class X, class Y> inline void mx(X& x, Y&& y)
{ if (x < y) x = std::forward<Y>(y); }

template<class X, class Y> inline void mn(X& x, Y&& y)
{ if (y < x) x = std::forward<Y>(y); }

// SOLUTION BEGINS HERE

string str_a, str_b;
int n;

int64_t best_a;
int64_t best_b;
int64_t best_difference;

int sign(int64_t x) {
  if (x > 0) return +1;
  if (x < 0) return -1;
  return 0;
}

inline void solve(int d, int64_t a, int64_t b) {
  if (d == n) {
    int64_t difference = std::abs(a - b);
    if ((difference < best_difference) || 
        (difference == best_difference && a < best_a) ||
        (difference == best_difference && a == best_a && b < best_b)) {
      best_difference = difference;
      best_a = a;
      best_b = b;
    }
    return;
  }
  int64_t next_a = a * 10 + (str_a[d] - '0');
  int64_t next_b = b * 10 + (str_b[d] - '0');
  if (str_a[d] != '?' && str_b[d] != '?') {
    solve(d + 1, next_a, next_b);
    return;
  }
  if (str_a[d] == '?' && str_b[d] == '?') {
    if (a > b) {
      solve(d + 1, a * 10 + 0, b * 10 + 9);
    } else if (a < b) {
      solve(d + 1, a * 10 + 9, b * 10 + 0);
    } else {
      solve(d + 1, a * 10 + 0, b * 10 + 0);
      solve(d + 1, a * 10 + 0, b * 10 + 1);
      solve(d + 1, a * 10 + 1, b * 10 + 0);
    }
    return;
  }
  if (a > b) {
    if (str_a[d] == '?') {
      solve(d + 1, a * 10 + 0, next_b);
    } else {
      solve(d + 1, next_a, b * 10 + 9);
    }
  } else if (a < b) {
    if (str_a[d] == '?') {
      solve(d + 1, a * 10 + 9, next_b);
    } else {
      solve(d + 1, next_a, b * 10 + 0);
    }
  } else {
    int mid = (str_a[d] != '?' ? str_a[d] : str_b[d]) - '0';
    for (int place = max(0, mid - 1); place <= min(9, mid + 1); ++place) {
      if (str_a[d] == '?') {
        solve(d + 1, a * 10 + place, next_b);
      } else {
        solve(d + 1, next_a, b * 10 + place);
      }
    }
  }
}

void solve() {
  cin >> str_a >> str_b;
  n = str_a.size();
  best_difference = numeric_limits<int64_t>::max();
  solve(0, 0, 0);
  cout << setw(n) << setfill('0') << best_a << ' ' << setw(n) << setfill('0') << best_b << endl;
}

void run() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int nTests;
  cin >> nTests;
  for (int iTest = 0; iTest < nTests; ++iTest) {
    cout << "Case #" << (iTest + 1) << ": ";
    solve();
  } 
}

// SOLUTION ENDS HERE

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  run();
  std::cout.flush();
  return 0;
}