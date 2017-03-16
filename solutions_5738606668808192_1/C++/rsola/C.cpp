#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int BASE = 1000000000;
const int BASE_DIGITS = 9;
struct BigInt {
  vector<int> s; char sign;
  BigInt(): s(), sign(1) {}
  BigInt(const ll &v): s(), sign(v < 0 ? -1 : 1) {
    for (ll t = v < 0 ? -v : v; t; t /= BASE) { s.push_back(t % BASE); }
  }
  BigInt(const string &v): s(), sign(1) {
    int beg = 0;
    for (; beg < (int)v.size() && (v[beg] == '-' || v[beg] == '+'); beg++) {
      if (v[beg] == '-') { sign = -1; }
    }
    for (int i = v.size() - 1; i >= beg; i -= BASE_DIGITS) {
      int x = 0;
      for (int j = max(beg, i - BASE_DIGITS + 1); j <= i; x = x * 10 + v[j++] - '0');
      s.push_back(x);
    }
    trim();
  }
  BigInt &operator=(const BigInt &v) { sign = v.sign; s = v.s; return *this; }
  BigInt &operator+=(const BigInt &v) {
    if (sign == v.sign) {
      for (int i = 0, is = 0, len = max(s.size(), v.s.size()); i < len || is; i++) {
        if (i == (int)s.size()) { s.push_back(0); }
        s[i] += is + (i < (int)v.s.size() ? v.s[i] : 0);
        if ((is = s[i] >= BASE)) { s[i] -= BASE; }
      }
      return *this;
    } else { return *this -= -v; }
  }
  BigInt &operator-=(const BigInt &v) {
    if (sign == v.sign) {
      if (cmp(v, 0) != -1) {
        for (int i = 0, is = 0; i < (int)v.s.size() || is; i++) {
          s[i] -= is + (i < (int)v.s.size() ? v.s[i] : 0);
          if ((is = s[i] < 0)) { s[i] += BASE; }
        }
        trim(); return *this;
      } else { return *this = -(BigInt(v) -= *this); }
    } else { return *this += -v; }
  }
  BigInt &operator*=(const BigInt &v) {
    vector<ll> num(s.size() + v.s.size());
    for (int i = 0; i < (int)s.size(); i++) {
      for (int j = 0; j < (int)v.s.size(); j++) {
        num[i + j] += (ll)s[i] * v.s[j];
        if (num[i + j] >= BASE) {
          num[i + j + 1] += num[i + j] / BASE; num[i + j] %= BASE;
        }
      }
    }
    sign *= v.sign; s.resize(num.size());
    for (int i = 0; i < (int)num.size(); i++) { s[i] = num[i]; }
    trim(); return *this;
  }
  friend pair<BigInt, BigInt> divmod(const BigInt &a, const BigInt &b) {
    int norm = BASE / (b.s.back() + 1);
    BigInt x = a.abs() * norm, y = b.abs() * norm, q, r; q.s.resize(x.s.size());
    for (int i = x.s.size() - 1; i >= 0; i--) {
      r *= BASE; r += x.s[i];
      int s1 = r.s.size() <= y.s.size() ? 0 : r.s[y.s.size()];
      int s2 = r.s.size() <= y.s.size() - 1 ? 0 : r.s[y.s.size() - 1];
      int d = ((ll)BASE * s1 + s2) / y.s.back();
      r -= y * d;
      while (r.cmp(0, 1) == -1) { r += y; --d; }
      q.s[i] = d;
    }
    q.sign = a.sign * b.sign; q.trim(); r.sign = a.sign; r.trim();
    return make_pair(q, r / norm);
  }
  BigInt &operator/=(const BigInt &v) { return *this = divmod(*this, v).first; }
  BigInt &operator%=(const BigInt &v) { return *this = divmod(*this, v).second; }
  BigInt operator-()const { BigInt ret(*this); ret.sign = -sign; return ret; }
  BigInt operator+(const BigInt &v)const { return BigInt(*this) += v; }
  BigInt operator-(const BigInt &v)const { return BigInt(*this) -= v; }
  BigInt operator*(const BigInt &v)const { return BigInt(*this) *= v; }
  BigInt operator*(int v)const { return BigInt(*this) *= v; }
  BigInt operator/(const BigInt &v)const { return divmod(*this, v).first; }
  BigInt operator/(int v)const { return BigInt(*this) /= v; }
  BigInt operator%(const BigInt &v)const { return divmod(*this, v).second; }
  BigInt &operator*=(int v) {
    if (v < 0) { sign = -sign, v = -v; }
    for (int i = 0, is = 0; i < (int)s.size() || is; i++) {
      if (i == (int)s.size()) { s.push_back(0); }
      ll a = s[i] * (ll)v + is; is = a / BASE; s[i] = a % BASE;
    }
    trim(); return *this;
  }
  BigInt &operator/=(int v) {
    if (v < 0) { sign = -sign, v = -v; }
    for (int i = s.size() - 1, rem = 0; i >= 0; i--) {
      ll a = s[i] + rem * (ll)BASE; s[i] = a / v; rem = a % v;
    }
    trim(); return *this;
  }
  int operator%(int v)const {
    if (v < 0) { v = -v; }
    int m = 0;
    for (int i = s.size() - 1; i >= 0; i--) { m = (s[i] + m * (ll)BASE) % v; }
    return m * sign;
  }
  BigInt operator^(const int &v)const {
    BigInt ret(1), t(*this);
    for (int b = v; b; b >>= 1) { if (b & 1) { ret *= t; } t *= t; }
    return ret;
  }
  bool operator<(const BigInt &v)const { return cmp(v) < 0; }
  bool operator>(const BigInt &v)const { return cmp(v) > 0; }
  bool operator<=(const BigInt &v)const { return cmp(v) <= 0; }
  bool operator>=(const BigInt &v)const { return cmp(v) >= 0; }
  bool operator==(const BigInt &v)const { return !cmp(v); }
  bool operator!=(const BigInt &v)const { return cmp(v) != 0; }
  int cmp(const BigInt &v, bool is = 1)const {
    if (is) { if (sign > v.sign) { return 1; } if (sign < v.sign) { return -1; } }
    int d = sign > 0 || !is ? 1 : -1;
    if (s.size() > v.s.size()) { return d; }
    if (s.size() < v.s.size()) { return -d; }
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] > v.s[i]) { return d; } if (s[i] < v.s[i]) { return -d; }
    }
    return 0;
  }
  BigInt abs()const { BigInt ret(*this); ret.sign *= ret.sign; return ret; }
  void trim() {
    while (!s.empty() && !s.back()) { s.pop_back(); }
    if (s.empty()) { sign = 1; }
  }
  void print()const {
    if (sign == -1) { putchar('-'); }
    printf("%d", s.empty() ? 0 : s.back());
    for (int i = (int)s.size() - 2; i >= 0; i--) { printf("%09d", s[i]); }
  }
  friend istream &operator>>(istream &in, BigInt &v) { string s; in >> s; v = s; return in; }
  friend ostream &operator<<(ostream &out, const BigInt &v) {
    if (v.sign == -1) { out << '-'; }
    out << setfill('0') << (v.s.empty() ? 0 : v.s.back());
    for (int i = (int)v.s.size() - 2; i >= 0; i--) { out << setw(BASE_DIGITS) << v.s[i]; }
    return out << setfill(' ');
  }
  string toString()const {
    if (s.empty()) { return "0"; }
    string ret, x;
    if (sign == -1) { ret += '-'; }
    for (int o = s[s.size() - 1]; o; o /= 10) { x += o % 10 + '0'; }
    for (int i = x.size() - 1; i >= 0; i--) { ret += x[i]; }
    for (int i = s.size() - 2; i >= 0; i--) {
      x.clear();
      for (int j = 0, p = s[i]; j < BASE_DIGITS; j++, p /= 10) { x += p % 10 + '0'; }
      for (int j = BASE_DIGITS - 1; j >= 0; j--) { ret += x[j]; }
    }
    return ret;
  }
  operator bool()const { return s.size() && !(s.size() == 1 && !s[0]); }
  operator string()const { return this->toString(); }
};

int n, j;
struct Node {
  string num;
  vector<ll> fac;
};
vector<Node> ans;

BigInt convert(const char *s, int base) {
  BigInt ret = 0;
  for (int i = 0; i < n; i++) {
    ret = ret * base + BigInt(s[i] - '0');
  }
  return ret;
}

int main() {
  freopen("C-large.in", "r", stdin);
  freopen("C.out", "w", stdout);

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
        BigInt num = convert(s, base);
        bool get = false;
        for (ll k = 2; k < 10000; k++) {
          if (num % BigInt(k) == BigInt(0)) { fac.push_back(k); get = true; break; }
        }
        if (!get) { ok = false; break; }
      }
      if (ok) {
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
