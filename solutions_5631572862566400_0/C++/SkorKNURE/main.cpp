#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void solveCase() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
    p[i] = i;
  }
  int answer = 0;
  do {
    for (int N = 3; N <= n; N++) {
      bool good = true;
      for (int i = 0; i < N; i++) {
        int l = i - 1;
        if (l < 0) l = N - 1;
        int r = i + 1;
        if (r == N) r = 0;

        int A = p[l];
        int B = p[i];
        int C = p[r];
        if (v[B] != A && v[B] != C) {
          good = false;
          break;
        }
      }
      if (good) {
        answer = max(answer, N);
      }
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << answer;
  cerr << answer;
}

//#define NAME "C-large"
#define NAME "C-small-attempt0"
//#define NAME "test"

int main() {
  freopen(NAME ".in", "rt", stdin);
  freopen(NAME ".out", "wt", stdout);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    cerr << "Case #" << i << ": ";
    solveCase();
    cout << endl;
    cerr << endl;
  }
  return 0;
}
