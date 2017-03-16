#include <iostream>
#include <algorithm>

const int kMaxN = 10000;

int solve() {
  int A, N;
  long long mote_size[kMaxN];
  std::cin >> A >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> mote_size[i];
  }

  if (A == 1) return N;
  std::sort(mote_size, mote_size + N);
  int ans = N, res = 0;
  for (int i = 0; i < N; ++i) {
    if (res + (N - i) < ans) {
      ans = res + (N - i);
    }
    while (A <= mote_size[i]) {
      res++;
      A = 2 * A - 1;
    }
    A += mote_size[i];
  }
  ans = std::min(res, ans);
  return ans;
}

int main(int argc, char *argv[]) {
  int T;
  std::cin >> T;
  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": " << solve() << std::endl;
  }
  return 0;
}
