#include <iostream>
#include <string>
#include <vector>

long long f(long long r, long long k) {
  return ((2 * r + 1) + 2 * (k - 1)) * k;
}

long long GetBlackRingsCount(long long r, long long t) {
  long long left = 0;
  long long right = 1;
  while (f(r, right) <= t) {
    right *= 2;
  }

  while (left < right) {
    long long mid = (left + right) / 2;
    if (f(r, mid) <= t) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return (left + right) / 2 - 1;
}

void Solve() {
  int T;
  scanf("%d\n", &T);
  for (int test_number = 1; test_number <= T; ++test_number) {
    long long r, t;
    std::cin >> r >> t;
    printf("Case #%d: %lld\n", test_number, GetBlackRingsCount(r, t));
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  Solve();
  return 0;
}