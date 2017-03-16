#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const ll LIM = 1000000;

int modulo(ll bin, ll base, ll mod) {
  ll res = 0;
  ll pw = 1;
  while (bin != 0) {
    res = (res + pw*(bin&1))%mod;
    pw = (pw*base)%mod;
    bin = bin>>1;
  }
  return res;
}

int convert(ll bin, ll base) {
  ll res = 0;
  ll pw = 1;
  while (bin != 0) {
    res = min(LIM, res + pw*(bin&1));
    pw = min(LIM, pw*base);
    bin = bin>>1;
  }
  return res;
}

vector<ll> jamcoin(ll bin) {
  vector<ll> res(11, 0);
  for (ll base = 2; base <= 10; ++base) {
    ll lim = convert(bin, base);
    for (ll i = 2; i*i <= lim; ++i) {
      if (modulo(bin, base, i) == 0) {
        res[base] = i;
        break;
      }
    }
    if (res[base] == 0) {
      return vector<ll>();
    }
  }
  return res;
}

vector<vector<ll> > generate(ll sz, ll ct) {
  vector<vector<ll> > res;
  for (ll i = 0; i < (1LL<<(sz - 2)); ++i) {
    ll bin = (1LL<<(sz - 1)) | (i<<1) | 1;
    vector<ll> jc = jamcoin(bin);
    if (!jc.empty()) {
      jc[0] = bin;
      res.push_back(jc);
      if (int(res.size()) >= ct) {
        break;
      }
    }
  }
  return res;
}

string tostring(ll bin) {
  string s;
  while (bin != 0) {
    s += (bin&1) ? '1' : '0';
    bin >>= 1;
  }
  reverse(s.begin(), s.end());
  return s;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    ll sz, ct;
    cin >> sz >> ct;
    vector<vector<ll> > jcs = generate(sz, ct);
    assert(int(jcs.size()) >= ct);
    cout << "Case #" << cas << ":" << endl;
    for (int i = 0; i < ct; ++i) {
      cout << tostring(jcs[i][0]);
      for (int j = 2; j <= 10; ++j) {
        cout << " " << jcs[i][j];
      }
      cout << endl;
    }
  }
}
