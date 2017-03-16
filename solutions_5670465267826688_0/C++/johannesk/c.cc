#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

struct uquat {
  bool sign;
  int base;
  friend uquat operator*(uquat a, uquat b) {
    bool sign = !(a.sign ^ b.sign);
    if (a.base == 1) return {sign, b.base};
    if (b.base == 1) return {sign, a.base};
    if (a.base == b.base) return {!sign, 1};
    int x=a.base, y=b.base;
    if (x < y) {
      std::swap(x, y);
      sign ^= 1;
    }
    switch (x) {
    case 3:
      assert(y == 2);
      return {!sign, 4};
    case 4:
      switch (y) {
      case 2:
        return {sign, 3};
      case 3:
        return {!sign, 2};
      default:
        assert(false);
      }
    }
    std::cerr << x << ' ' << y << std::endl;
    assert(false);
  }
  uquat& operator *=(uquat b) { return *this = *this*b; }
  friend bool operator==(uquat a, uquat b) { return a.sign == b.sign && a.base == b.base; }
  friend bool operator!=(uquat a, uquat b) { return !(a == b); }

  friend std::ostream& operator<<(std::ostream& os, uquat q) {
    assert(1 <= q.base && q.base <= 4);
    return os << (q.sign ? "+" : "-") << "1ijk"[q.base - 1];
  }
};

template <typename Iter, typename BinOp>
int first(Iter first, Iter last, uquat q, BinOp op) {
  uquat p{true,1};
  for (int i=1; first != last; ++i, ++first) {
    p = op(p, *first);
    if (p == q)
      return i;
  }
  return -1;
}
bool calculate(long long l, long long x, std::string const& s) {
  std::vector<uquat> q;
  q.reserve(s.size()*8);
  for (int i=0; i<8; ++i) {
    for (char c : s) {
      switch (c) {
      case 'i': q.push_back({true, 2}); break;
      case 'j': q.push_back({true, 3}); break;
      case 'k': q.push_back({true, 4}); break;
      default: assert(false);
      }
    }
  }
  uquat tot = std::accumulate(q.cbegin(), q.cbegin()+l*(4+x%4),
                              uquat{true, 1}, std::multiplies<>());
  if (tot != uquat{false, 1})
    return false;
  int pre = first(q.cbegin(), q.cend(), {true, 2}, std::multiplies<>());
  if (pre < 0)
    return false;
  int post = first(q.crbegin(), q.crend(), {true, 4},
		   [](auto a, auto b){return b*a;});
  if (post < 0)
    return false;
  assert(post<4*l);
  assert(pre<4*l);
  return (pre + post < l*x);
}
int main() {
  int tc_tot; std::cin >> tc_tot;
  for (int tc=1; tc<=tc_tot; ++tc) {
    long long l, x; std::cin >> l >> x;
    std::string s; std::cin >> s;
    std::cout << "Case #" << tc << ": " << (calculate(l, x, s) ? "YES" : "NO") << '\n';
  }
}
