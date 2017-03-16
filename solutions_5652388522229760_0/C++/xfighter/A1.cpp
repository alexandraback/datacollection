#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void Add(int64_t N, unordered_set<int>* seen) {
  while (N > 0) {
    seen->insert(N % 10);
    N /= 10;
  }
}

int main() {
  int T;
  cin >> T;
  unordered_set<int> seen;
  for (int t = 0; t < T; ++t) {
    int64_t N;
    cin >> N;
    if (N == 0) {
      cout << "Case#" << t + 1 << ": " << "INSOMNIA" << endl;
      continue;
    }
    seen.clear();
    int64_t M = 0;
    while (seen.size() != 10) {
      M += N;
      Add(M, &seen);
    }
    cout << "Case #" << t + 1 << ": " << M << endl;
  }
}
