#include <iostream>
#include <string>
#include <vector>

int GetBlackRingsCount(long long r, long long t) {
  long long cur_paint = 0;
  int result = 0;

  r++;
  while(1) {
    cur_paint += r * r - (r - 1) * (r - 1);
    if (cur_paint <= t) {
      result++;
    } else {
      break;
    }

    r += 2;
  }

  return result;
}

void Solve() {
  int T;
  scanf("%d\n", &T);
  for (int test_number = 1; test_number <= T; ++test_number) {
    long long r, t;
    std::cin >> r >> t;
    printf("Case #%d: %d\n", test_number, GetBlackRingsCount(r, t));
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  Solve();
  return 0;
}