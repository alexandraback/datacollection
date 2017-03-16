#define NDEBUG
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

template <typename T> inline T set_bit(const T &x, int index) {
  return x | ((T)1 << index);
}
template <typename T> inline T kill_bit(const T &x, int index) {
  return x & ~((T)1 << index);
}
typedef long long int64;
template <typename T> inline int get_bit(const T &x, int index) {
  return int((x >> index) & 1);
}

struct Range {
  int64 start, end;

  int64 size() const {
    return max(0LL, end - start + 1);
  }

  Range force_zero(int index) const {
    Range result = *this;
    result.force_zero_impl(index);
    // fprintf(stderr, "force_zero(A=%lld, B=%lld, index=%d) = (A=%lld, B=%lld)\n",
    //         start, end, index, result.start, result.end);
    return result;
  }

  Range force_one(int index) const {
    Range result = *this;
    result.force_one_impl(index);
    // fprintf(stderr, "force_one(A=%lld, B=%lld, index=%d) = (A=%lld, B=%lld)\n",
    //         start, end, index, result.start, result.end);
    return result;
  }

private:
  void force_zero_impl(int index) {
    if (get_bit(start, index)) {
      start = 0;
      end = -1;
      return;
    }
    if (get_bit(end, index)) {
      end = kill_bit(end, index);
      end |= (1LL << index) - 1;
    }
  }

  void force_one_impl(int index) {
    if (!get_bit(end, index)) {
      start = 0;
      end = -1;
      return;
    }
    if (!get_bit(start, index)) {
      start &= ~((1LL << index) - 1);
      start = set_bit(start, index);
    }
  }
};

struct State {
  Range A;
  Range B;
  int bits_left;

  friend bool operator<(const State &s1, const State &s2) {
#define CMP(field) if (s1.field != s2.field) return s1.field < s2.field;
    CMP(A.start);
    CMP(A.end);
    CMP(B.start);
    CMP(B.end);
    CMP(bits_left);
#undef CMP
    return false;
  }
};

map<State, int64> memo;
int64 solve_target(Range A, Range B, int64 target, int shift, int bits_left) {
  if (A.size() == 0 || B.size() == 0) {
    return 0;
  }
  if (shift == bits_left) {
    return A.size() * B.size();
  }

  int64 mask = (1LL<<bits_left) - 1;
  A.start &= mask;
  A.end &= mask;
  B.start &= mask;
  B.end &= mask;

  // fprintf(stderr, "solve_target(A=(%lld, %lld), B=(%lld, %lld), target=%lld, shift=%d, bits_left=%d\n",
  //         A.start, A.end, B.start, B.end, target, shift, bits_left);
  State state = {A, B, bits_left};
  auto insert_result = memo.insert(make_pair(state, 0));
  int64 &ret = insert_result.first->second;
  if (!insert_result.second) {
    return ret;
  }

  ret = 0;

  int pos = bits_left - 1;
  if (get_bit(target, pos)) {
    ret = solve_target(A.force_one(pos), B.force_one(pos), target, shift, bits_left - 1);
  } else {
    ret =
      solve_target(A.force_zero(pos), B.force_zero(pos), target, shift, bits_left - 1) +
      solve_target(A.force_zero(pos), B.force_one(pos), target, shift, bits_left - 1) +
      solve_target(A.force_one(pos), B.force_zero(pos), target, shift, bits_left - 1);
  }

  // brute:
  // int64 ans = 0;
  // for (int a=A.start; a<=A.end; ++a) {
  //   for (int b=B.start; b<=B.end; ++b) {
  //     ans += ((a & b) >> shift) == (target >> shift);
  //   }
  // }
  // assert(ret == ans);

  return ret;
}

void solve1() {
  int64 A_in, B_in, K;
  cin >> A_in >> B_in >> K;

  Range A = {0, A_in-1};
  Range B = {0, B_in-1};

  int64 ans = 0;
  for (int i=60; i>=0; --i) {
    if (get_bit(K, i)) {
      memo.clear();
      ans += solve_target(A, B, kill_bit(K, i), i, 60);
      // debug(i);
      // debug(memo.size());
    }
  }
  printf("%lld\n", ans);
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    printf("Case #%d: ", tt);
    solve1();
    fflush(stdout);
  }
}
