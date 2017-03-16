#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetMovesCount() {
  int A, N;
  std::cin >> A >> N;
  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> v[i];
  }

  std::sort(v.begin(), v.end());

  int best = 1000000000;
  for (int k = 0; k <= N; ++k) {
    int cnt = 0;
    long long x = A;
    int j = 0;

    while (v[j] < x && j < N - k) {
      x += v[j];
      ++j;
    }

    if (x == 1) {
      best = N;
      break;
    }

    for (; j < N - k; ++j) {
      while (v[j] >= x) {
        x += x - 1;
        ++cnt;
      }
      x += v[j];
    }
    best = min(best, cnt + k);
  }

  return best;
}

void Solve() {
  int T;
  scanf("%d\n", &T);
  for (int test_number = 1; test_number <= T; ++test_number) {
    printf("Case #%d: %d\n", test_number, GetMovesCount());
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  Solve();
  return 0;
}