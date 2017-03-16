#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace {

int Solve(vector<int> F) {
  int N = F.size();
  for (int i = 0; i < N; ++i) --F[i];
  int res = 2;
  vector<int> perm;
  for (int i = 0; i < N; ++i) perm.push_back(i);
  do {
    if (F[perm[0]] != perm[1]) continue;
    for (int i = 1; i < N; ++i) {
      if (F[perm[i]] == perm[i - 1] || F[perm[i]] == perm[0]) {
        res = max(res, i + 1);
      }
      if (F[perm[i]] == perm[i - 1] ||
          (i < N - 1 && F[perm[i]] == perm[i + 1])) continue;
      break;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  return res;
}

}

int main(void) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N;
    cin >> N;
    vector<int> F(N);
    for (int j = 0; j < N; ++j) cin >> F[j];
    cout << "Case #" << i << ": " << Solve(F) << endl;
  }

  return 0;
}
