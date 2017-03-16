#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> bff, vector<bool> used, vector<int> perm, int best)
{
  if (perm.size() == bff.size()) {
    int ans = 0;
    for (int i = best + 1; i <= bff.size(); i++) {
      bool valid = true;
      if (bff[perm[0]] != perm[1] && bff[perm[0]] != perm[i - 1]) {
        valid = false;
      }
      for (int j = 1; j < i - 1; j++) {
        if (bff[perm[j]] != perm[j - 1] && bff[perm[j]] != perm[j + 1]) {
          valid = false;
          break;
        }
      }
      if (bff[perm[i - 1]] != perm[0] && bff[perm[i - 1]] != perm[i - 2]) {
        valid = false;
      }
      if (valid) {
        ans = i;
      }
    }
    return ans;
  }

  int ans = 0;
  for (int i = 0; i < used.size(); i++) {
    if (!used[i]) {
      vector<int> test = perm;
      test.push_back(i);
      used[i] = true;
      ans = max(ans, solve(bff, used, test, ans));
      used[i] = false;
    }
  }
  return ans;
}

int solve(vector<int> bff)
{
  vector<bool> used;
  for (int i = 0; i < bff.size(); i++) {
    used.push_back(false);
  }
  vector<int> perm;
  return solve(bff, used, perm, 0);
}

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> bff;
    for (int i = 0; i < N; i++) {
      int b;
      cin >> b;
      bff.push_back(b - 1);
    }
    cout << "Case #" << t << ": " << solve(bff) << "\n";
  }
  return 0;
}

