#include <bits/stdc++.h>
using namespace std;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FORR(x,arr) for(auto&& x:arr)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define BIT(n) (1LL<<(n))
#define SZ(x) ((int)(x).size())
typedef unsigned long long ll;
// -------------------------------------

const int N = 32;
__int128 B[11][32];

ll is_prime(const __int128 &n) {
  for (ll i = 2; i <= BIT(16); i++) {
    if (n % i == 0) return i;
  }
  return 0;
}

bool check(int x) {
  int y = x;
  __int128 t[11];
  memset(t, 0, sizeof(t));
  REP(i, N) {
    if (x % 2) {
      FOR(b, 2, 11) {
        t[b] += B[b][i];
      }
    }
    x >>= 1;
  }

  ll d[11];
  FOR(b, 2, 11) {
    ll res = is_prime(t[b]);
    if (res == 0) return false;
    d[b] = res;
  }

  cout << static_cast<std::bitset<32> >(y);
  FOR(b, 2, 11) {
    _P(" %lld", d[b]);
  }
  puts("");

  return true;
}

int main() {
  int c = 0;

  FOR(i, 2, 11) {
    B[i][0] = 1;
    FOR(j, 1, N) {
      B[i][j] = B[i][j-1] * i;
    }
  }

  random_device rnd;
  puts("Case #1:");
  ll HB = BIT(N-1);
  while (c < 500) {
    unsigned int x = rnd();
    if (x & HB && x % 2 == 1) {
      bool cond = check(x);
      if (cond) {
        c++;
      }
    }
  }

  return 0;
}
