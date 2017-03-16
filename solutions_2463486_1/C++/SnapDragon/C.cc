#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define PRECOMPUTE 0

struct SimpleBigInt {
  bool neg;
  string dig;
  SimpleBigInt() : dig("0"), neg(false) {}
  SimpleBigInt(int x)
    {if ((neg=x<0)) x=-x; do {dig.push_back(x%10+'0'); x /= 10;} while (x); reverse(dig.begin(), dig.end());}
  SimpleBigInt(long long x)
    {if ((neg=x<0)) x=-x; do {dig.push_back(x%10+'0'); x /= 10;} while (x); reverse(dig.begin(), dig.end());}
  SimpleBigInt(const string& s) {if ((neg=(s[0]=='-'))) dig = s.substr(1); else dig = s;}
  SimpleBigInt(const string& dig, bool neg) : dig(dig), neg(neg) {}
  static bool LessThan(const string& a, bool an, const string& b, bool bn, bool count_eq) {
    if (an != bn) return an;
    if (a.size() != b.size()) return (a.size() < b.size()) ^ an;
    for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) return (a[i] < b[i]) ^ an;
    return count_eq;
  }
  static SimpleBigInt AddOrSubtract(const string& a, bool an, const string& b, bool bn) {
    SimpleBigInt ret("", an);
    if (an == bn) {
      for (int i = 0, c = 0; i < a.size() || i < b.size() || c; i++) {
        if (i < a.size()) c += a[a.size()-1-i]-'0';
        if (i < b.size()) c += b[b.size()-1-i]-'0';
        ret.dig += c%10 + '0'; c /= 10;
      }
    } else {
      bool swp = LessThan(a, false, b, false, an);
      if (swp) ret.neg = bn;
      const string& s1 = (swp ? b : a), s2 = (swp ? a : b);
      for (int i = 0, c = 0; i < s1.size(); i++) {
        c += 10 + s1[s1.size()-1-i]-'0';
        if (i < s2.size()) c -= s2[s2.size()-1-i]-'0';
        ret.dig += c%10 + '0'; c = c/10-1;
      }
      for (int i = ret.dig.size()-1; i >= 0; i--)
        if (i==0 || ret.dig[i]!='0') {ret.dig = ret.dig.substr(0, i+1); break;}
    }
    reverse(ret.dig.begin(), ret.dig.end());
    return ret;
  }
  SimpleBigInt operator+(const SimpleBigInt& b) const {return AddOrSubtract(dig, neg, b.dig, b.neg);}
  SimpleBigInt& operator+=(const SimpleBigInt& b) {*this = AddOrSubtract(dig, neg, b.dig, b.neg); return *this;}
  SimpleBigInt operator-(const SimpleBigInt& b) const {return AddOrSubtract(dig, neg, b.dig, !b.neg);}
  SimpleBigInt& operator-=(const SimpleBigInt& b) {*this = AddOrSubtract(dig, neg, b.dig, !b.neg); return *this;}
  SimpleBigInt operator-() const {return SimpleBigInt(dig, !(neg || dig=="0"));}
  SimpleBigInt operator*(int x) const {  // NOTE: x*10 should not overflow int.
    if (x == 0) return SimpleBigInt();
    SimpleBigInt ret("", neg);
    if (x < 0) {x = -x; ret.neg = !neg && dig != "0";}
    for (int i = 0, c = 0; i < dig.size() || c; i++) {
      if (i < dig.size()) c += x * (dig[dig.size()-1-i]-'0');
      ret.dig += c%10 + '0'; c /= 10;
    }
    reverse(ret.dig.begin(), ret.dig.end());
    return ret;
  }
  SimpleBigInt& operator*=(int x) {return *this = *this * x;}
  SimpleBigInt operator*(const SimpleBigInt& b) const {
    if (b == 0 || *this == 0) return SimpleBigInt();
    SimpleBigInt ret;
    for (int i = 0; i < b.dig.size(); i++) {
      char ch = b.dig[b.dig.size()-1-i];
      if (ch == '0') continue;
      SimpleBigInt v = *this * (int)(ch-'0');
      for (int j = 0; j < i; j++) v.dig += '0';
      ret += v;
    }
    if (b.neg) ret.neg = !ret.neg;
    return ret;
  }
  SimpleBigInt& operator*=(const SimpleBigInt& b) {return *this = *this * b;}
  SimpleBigInt operator/(SimpleBigInt b) const {
    if (b == 0 || *this == 0) return SimpleBigInt();
    SimpleBigInt ret("", neg ^ b.neg), rem(dig, false);
    b.neg = false;
    int d = 0;
    while (b <= rem) {b.dig += '0'; d++;}
    if (d == 0) return SimpleBigInt();
    ret.dig = string(d, '0');
    for (d--; d >= 0; d--) {
      b.dig.resize(b.dig.size()-1);
      while (b <= rem) {rem -= b; ret.dig[ret.dig.size()-1-d]++;}
    }
    return ret;
  }
  SimpleBigInt& operator/=(const SimpleBigInt& b) {return *this = *this / b;}
  SimpleBigInt operator%(const SimpleBigInt& b) const {return *this - b * (*this / b);}
  SimpleBigInt& operator%=(const SimpleBigInt& b) {return *this -= b * (*this / b);}
  bool operator<(const SimpleBigInt& b) const {return LessThan(dig, neg, b.dig, b.neg, false);}
  bool operator<=(const SimpleBigInt& b) const {return LessThan(dig, neg, b.dig, b.neg, true);}
  bool operator>(const SimpleBigInt& b) const {return !LessThan(dig, neg, b.dig, b.neg, true);}
  bool operator>=(const SimpleBigInt& b) const {return !LessThan(dig, neg, b.dig, b.neg, false);}
  bool operator==(const SimpleBigInt& b) const {return neg == b.neg && dig == b.dig;}
  bool operator!=(const SimpleBigInt& b) const {return neg != b.neg || dig != b.dig;}
  string tostring() const {return (neg ? "-" : "") + dig;}
  friend SimpleBigInt abs(const SimpleBigInt& b) {return SimpleBigInt(b.dig, false);}
  friend istream& operator>>(istream& in, SimpleBigInt& b) {string s; in >> s; b = SimpleBigInt(s); return in;}
  friend ostream& operator<<(ostream& out, const SimpleBigInt& b) {if (b.neg) out << '-'; out << b.dig; return out;}
};

int doit(const SimpleBigInt& xlb, const SimpleBigInt& xub,
         const SimpleBigInt& ylb, const SimpleBigInt& yub, int d,
         ostream& out) {
  if (yub < ylb) return 0;
  if (xlb * xlb > yub) return 0;
  if (xub * xub < ylb) return 0;
  if (d+d >= xlb.dig.size()) {
    assert(xlb == xub);
    SimpleBigInt sqr = xlb * xlb;
    string s = sqr.dig;
    reverse(s.begin(), s.end());
    if (s == sqr.dig) out << xlb << ' ' << sqr << endl;
    return (s == sqr.dig);
  }

  int xnd = xlb.dig.size(), ynd = ylb.dig.size(), ret = 0;
  for (char ch = xlb.dig[d]; ch <= xub.dig[d]; ch++) {
    SimpleBigInt xlb2 = xlb, xub2 = xub, ylb2 = ylb, yub2 = yub;
    xlb2.dig[d] = xub2.dig[d] = ch;
    xlb2.dig[xnd-1-d] = xub2.dig[xnd-1-d] = ch;
    SimpleBigInt sqr = xlb2 * xlb2;
    if (sqr > yub) break;
    ylb2.dig[d] = yub2.dig[d] = sqr.dig[sqr.dig.size()-1-d];
    ylb2.dig[ynd-1-d] = yub2.dig[ynd-1-d] = sqr.dig[sqr.dig.size()-1-d];
    ret += doit(xlb2, xub2, ylb2, yub2, d+1, out);
  }
  return ret;
}

#if PRECOMPUTE
main() {
  ofstream out("C.txt");
  for (int ynd = 1; ynd <= 100; ynd++) {
    SimpleBigInt ylb('1'+string(ynd-1, '0'));
    SimpleBigInt yub(string(ynd, '9'));
    int xnd = (ynd+1)/2;
    SimpleBigInt xlb('1'+string(xnd-1, '0'));
    SimpleBigInt xub(string(xnd, '9'));
    doit(xlb, xub, ylb, yub, 0, out);
  }
  cout << "0 0" << endl;
}
#else
main() {
  vector<SimpleBigInt> v;
  ifstream in("C.txt");
  for (;;) {
    SimpleBigInt x, y;
    in >> x >> y;
if (y.dig.size() > 20) break;
    if (y.dig == "0") break;
    v.push_back(y);
  }

  int T, prob=1;
  SimpleBigInt A, B;
  for (cin >> T; T--;) {
    cin >> A >> B;
    int ret = 0;
    for (int i = 0; i < v.size(); i++) {
      ret += (v[i] >= A && v[i] <= B);
    }
    cout << "Case #" << prob++ << ": " << ret << endl;
  }
}
#endif
