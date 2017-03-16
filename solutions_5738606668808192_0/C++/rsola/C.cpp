#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100000000;
bitset < N + 5 > isprime;
void getPrime() {
  isprime.set(); isprime[0] = isprime[1] = false;
  for (ll i = 2; i <= N; i++) {
    if (isprime[i]) {
      for (ll j = (ll)i * i; j <= N; j += i) { isprime[j] = false; }
    }
  }
}

const int Times = 7;
ll mulMod(ll a, ll b, ll m) {
  ll r = 0;
  for (a %= m, b %= m; b; b >>= 1) { if (b & 1) { r = (r + a) % m; } a = (a << 1) % m; }
  return r;
}
ll powMod(ll a, ll b, ll m) {
  ll r = 1;
  for (a %= m; b; b >>= 1) { if (b & 1) { r = mulMod(r, a, m); } a = mulMod(a, a, m); }
  return r;
}
bool Miller_Rabin(ll n) {
  if (n == 2) { return true; }
  if (n < 2 || (n & 1) == 0) { return false; }
  ll m = n - 1; int k = 0;
  while ((m & 1) == 0) { k++; m >>= 1; }
  for (int i = 0; i < Times; i++) {
    ll a = rand() % (n - 1) + 1, x = powMod(a, m, n), y = 0;
    for (int j = 0; j < k; j++) {
      y = mulMod(x, x, n);
      if (y == 1 && x != 1 && x != n - 1) { return false; }
      x = y;
    }
    if (y != 1) { return false; }
  }
  return true;
}

int n, j;
struct Node {
  string num;
  vector<ll> fac;
};
vector<Node> ans;

ll convert(const char *s, int base) {
  ll ret = 0;
  for (int i = 0; i < n; i++) {
    ret = ret * base + s[i] - '0';
  }
  return ret;
}

int main() {
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C.out", "w", stdout);

  getPrime();
  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    ans.clear();
    scanf("%d%d", &n, &j);
    for (ll i = (1LL << (n - 1)) + 1; i < 1LL << n; i += 2) {
      char s[n + 1];
      for (ll k = 0, t = i; t; k++, t >>= 1) { s[k] = (t & 1) + '0'; }
      reverse(s, s + n); s[n] = 0;
      bool ok = true;
      vector<ll> fac;
      for (int base = 2; base <= 10; base++) {
        ll num = convert(s, base);
        if ((num < N && isprime[num]) || (num >= N && Miller_Rabin(num))) { ok = false; break; }
        for (ll k = 2;; k++) {
          if (num % k == 0) { fac.push_back(k); break; }
        }
      }
      if (ok) {

        //printf("%s\n", s);
        //for (int k = 0; k < 9; k++) { printf("base(%d)=%d fac=%d\n", k + 2, convert(s, k + 2), fac[k]); }

        ans.push_back({s, fac});
        if ((int)ans.size() == j) { break; }
      }
    }
    printf("Case #%d:\n", C);
    for (int i = 0; i < j; i++) {
      printf("%s", ans[i].num.c_str());
      for (int k = 0; k < 9; k++) { printf(" %I64d", ans[i].fac[k]); }
      puts("");
    }
  }
}
