#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

int const max_b = 2000111;

vector<int> rots[max_b];

namespace {

int p10[8];

void fill()
{
  p10[0] = 1;
  for (int i = 1; i < 8; i++) p10[i] = 10 * p10[i-1];
  int n = 1;
  int p = 10;
  for (int i = 1; i < max_b; i++) {
    if (i >= p) {
      n++;
      p *= 10;
    }
    int cur = i;
    for (int r = 0; r < n; r++) {
      int d = cur % 10;
      cur /= 10;
      cur += p10[n-1] * d;
      rots[i].push_back(cur);
    }
    assert(cur == i);
    sort(rots[i].begin(), rots[i].end());
    rots[i].erase(unique(rots[i].begin(), rots[i].end()), rots[i].end());
  }
}

int solve(int a, int b)
{
  int res = 0;
  for (int i = a; i <= b; i++) {
    for (int x: rots[i]) {
      if (x > i && x <= b) res++;
    }
  }
  return res;
}

}

int main()
{
  fill();
  int t;
  cin >> t;
  for (int casenr = 1; casenr <= t; casenr++) {
    int a, b;
    cin >> a >> b;
    cout << "Case #" << casenr << ": " << solve(a, b) << endl;
  }
  return 0;
}
