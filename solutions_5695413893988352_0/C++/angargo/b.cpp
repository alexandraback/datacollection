#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using T = tuple<ll, ll, ll>;
#define D(t) get<0>(t)
#define C(t) get<1>(t)
#define J(t) get<2>(t)
using VT = vector<T>;
using VVT = vector<VT>;

const ll INF = (1LL << 63) - 1;

VT d;
string sc, sj;
int l;

ll absll(ll a) { return max(a, -a); }

T din(int i) {
  T &r = d[i];
  if (D(r) != -1) return r;
  if (i == l) return r = T(0, 0, 0);

  r = T(INF, INF, INF);

  T n = din(i + 1);
  for (char c = '0'; c <= '9'; ++c) {
    if (sc[l - i - 1] != '?' and sc[l - i - 1] != c) continue;
    for (char j = '0'; j <= '9'; ++j) {
      if (sj[l - i - 1] != '?' and sj[l - i - 1] != j) continue;
      ll nc = (c - '0') + 10LL * C(n);
      ll nj = (j - '0') + 10LL * J(n);
      r = min(r, make_tuple(absll(nc - nj), nc, nj));
    }
  }
  return r;
}

bool ok(const string &s, int i) {
  for (int j = l - 1; j >= 0; --j) {
    if (s[j] != '?' and (s[j] - '0') != i % 10) return false;
    i /= 10;
  }
  return true;
}

void solve(int cas) {
  cout << "Case #" << cas << ":";
  cin >> sc >> sj;
  l = sc.size();
  ll p = 1;
  for (int i = 0; i < l; ++i) p *= 10LL;
  T res(INF, INF, INF);
  for (ll c = 0; c < p; ++c) {
    for (ll j = 0; j < p; ++j) {
      if (ok(sc, c) and ok(sj, j)) {
        res = min(res, make_tuple(absll(c - j), c, j));
      }
    }
  }
  //d = VT(l + 1, make_tuple(-1, -1, -1));
  //auto res = din(0);
  cout << " " << setw(l) << setfill('0') << C(res);
  cout << " " << setw(l) << setfill('0') << J(res);
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve(i + 1);
}
