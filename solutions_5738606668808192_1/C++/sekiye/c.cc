#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define DEBUG(x) cout << #x << ": " << x << endl

int NumberOfSetBits(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

vector<int> prime = {2, 3, 5, 7};

int N;
int J;

int get_divisor(ll x) {
  REP(i, prime.size()) {
    if (x % prime[i] == 0) {
      return prime[i];
    }
  }
  return 0;
}

ll convert(ll x, int i) {
  ll y = 1;
  ll sum = 0;
  REP(j, N) {
    if (x & 1) {
      sum += y;
    }
    y *= i;
    x >>= 1;
  }
  return sum;
}

void check(ll x) {
  vector<int> v;
  FOR(i, 2, 11) {
    int d = get_divisor(convert(x, i));
    if (d == 0) {
      return;
    }
    v.push_back(d);
  }
  string s;
  REP(i, N) {
    s += to_string(x & 1);
    x >>= 1;
  }
  reverse(ALL(s));
  std::cout << s;
  REP(i, v.size()) {
    std::cout << " " << v[i];
  }
  std::cout << std::endl;
  J--;
}

int solve() {
  cin >> N >> J;
  REP(i, 1 << (N - 2)) {
    if (J == 0) {
      break;
    }
    if (NumberOfSetBits(i) % 2 != 0) {
      continue;
    }
    ll x = (1LL << (N - 1)) | (i << 1) | 1;
    check(x);
  }
  return 0;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    std::cout << "Case #" << i + 1 << ":" << std::endl;
    solve();
  }
  return 0;
}
