#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <memory.h>
using namespace std;

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

int ri() {
  static int res;
  scanf("%d", &res);
  return res;
}

template <typename T>
int numbits(T n) {
  return n ? 1 + numbits(n & (n - 1)) : 0;
}

class timer {
public:
  timer() : t_(clock()) {}
  void restart() { t_ = clock(); }
  float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
  clock_t t_;
};

void run();

int main() {
#ifdef LOCAL_HOST
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  timer t;
#endif
  run();
#ifdef LOCAL_HOST
  //printf("\nElapsed time: %.9f\n", t.elapsed());
#endif
  return 0;
}

int digits(ll n) {
  int res = 0;
  while (n > 0) {
    ++res;
    n /= 10;
  }
  return res;
}

ll nines(int n) {
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res = 9 * res + 9;
  }
  return res;
}

ll calc(ll n, int d, int last) {
  ll res = 0;
  ll md = 1;
  for (int i = 0; i < last; ++i) {
    md *= 10;
  }
  ll left = n % md;
  if (left == 0) {
    n--;
    res++;
    left = n % md;
  }
  res += left;
  n /= md;
  ll m = 0;
  while (n) {
    m = m * 10 + (n % 10);
    n /= 10;
  }
  res += m;
  return res;
}

ll dp[1000001];
int p[1000001];
ll reverse(ll n) {
  ll res = 0;
  while (n) {
    res = res * 10 + (n % 10);
    n /= 10;
  }
  return res;
}

void run() {

  memset(dp, 0, sizeof(dp));
  dp[1] = 1;
  p[1] = -1;
  for (int i = 2; i <= 1000000; ++i) {
    dp[i] = dp[i - 1] + 1;
    p[i] = i - 1;
    if (i % 10) {
      ll j = reverse(i);
      if (j < i && dp[i] > dp[j] + 1) {
        dp[i] = dp[j] + 1;
        p[i] = j;
      }
    }
  }

  int nn; cin >> nn;
  for (int cs = 0; cs < nn; ++cs) {
    ll n; cin >> n;

    // int d = digits(n);

    // if (d == 1) {
    //   cout << "Case #" << cs + 1 << ": " << n << endl;
    //   continue;
    // }

    // ll res = 10;
    // ll cur = 10;
    // for (int i = 2; i < d; ++i) {
    //   int tmp1 = i / 2;
    //   int tmp2 = i - tmp1;
    //   res += nines(tmp1) + nines(tmp2) + 1LL;
    //   cur *= 10;
    // }

    // ll answer = res + n - cur;
    // for (int i = 1; i < d; ++i) {
    //   ll check = calc(n, d, i);
    //   answer = min(answer, check + res);
    // }

    cout << "Case #" << cs + 1 << ": " << dp[n] << endl;
  }
}
