#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int N, vector<int> &a, vector<int> &b) {
  vector<bool> done1(N);
  vector<bool> done2(N);
  int stars = 0;
  int res = 0;
  bool found;
  while (stars < 2*N) {
    found = false;
    for (int i = 0; i < N; i++) {
      if (!done1[i] && !done2[i] && b[i] <= stars) {
        done2[i] = true;
        done1[i] = true;
        stars += 2;
        found = true;
        break;
      }
    }
    if (found) {
      res++;
      continue;
    }
    for (int i = 0; i < N; i++) {
      if (!done2[i] && b[i] <= stars) {
        done2[i] = true;
        stars++;
        found = true;
        break;
      }
    }
    if (found) {
      res++;
      continue;
    }
    int maxb = -1;
    int maxi = -1;
    for (int i = 0; i < N; i++) {
      if (!done1[i] && a[i] <= stars && b[i] > maxb) {
        maxb = b[i];
        maxi = i;
        found = true;
      }
    }
    if (found) {
      done1[maxi] = true;
      stars++;
      res++;
      continue;
    }
    return -1;
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int testcase = 0; testcase < T; testcase++) {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      cin >> b[i];
    }
    int res = solve(N, a, b);
    if (res == -1)
      cout << "Case #" << testcase + 1 << ": " << "Too Bad" << endl;
    else
      cout << "Case #" << testcase + 1 << ": " << res << endl;
  }
  return 0;
}
