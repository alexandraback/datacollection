#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<long long>::const_iterator iter;

long long GetMaxJoules(long long E, long long R, long long max_E, iter begin, iter end) {
  if (begin == end) {
    return 0;
  }

  long long result = 0;
  long long e = 0;
  while (e <= E) {
    result = max(result, (*begin) * e + GetMaxJoules(min(E - e + R, max_E), R, max_E, begin + 1, end));
    e++;
  }

  return result;
}

void Solve() {
  int T;
  scanf("%d\n", &T);
  for (int test_number = 1; test_number <= T; ++test_number) {
    long long E, R, N;
    cin >> E >> R >> N;
    vector<long long> v;
    v.reserve(N);
    for (int i = 0; i < N; ++i) {
      long long val;
      cin >> val;
      v.push_back(val);
    }
    printf("Case #%d: %lld\n", test_number, GetMaxJoules(E, R, E, v.begin(), v.end()));
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  Solve();
  return 0;
}