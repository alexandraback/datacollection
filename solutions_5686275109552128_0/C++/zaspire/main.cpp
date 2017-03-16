#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int kDMax = 1001;

int Solve(const map<int, int> &r, int D) {
  int tr = D;
  for (const auto &p1: r) {
    if (p1.first <= D)
      continue;
    tr += p1.second * (p1.first / D + (p1.first % D ? 1 : 0) - 1);
  }
  return tr;
}

int Solve(const map<int, int> &r) {
  int res = r.rbegin()->first;
  for (int i = 1; i < kDMax; i++) {
    res = min(Solve(r, i), res);
  }
  return res;
}

int main(void) {
  int T;
  cin >> T;
  for (int TT = 0; TT < T; TT++) {
    int D;
    cin >> D;
    map<int, int> r;
    while (D--) {
      int t;
      cin >> t;
      r[t]++;
    }
    cout << "Case #" << TT + 1 << ": " << Solve(r) <<  endl;
  }
  return 0;
}
