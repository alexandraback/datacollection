#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 10;

int v[N];
int e, r, n;

int go(int idx, int curr) {
  if (idx == n) return 0;
  int best = 0;
  for (int i = 0; i <= curr; i++) {
    int gain = i * v[idx] + go(idx+1, min(e, curr - i + r));
    best = max(best, gain);
  }
  return best;
}

int main() {
  int cases; cin >> cases;
  for (int caseNo = 1; caseNo <= cases; caseNo++) {
    cin >> e >> r >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << "Case #" << caseNo << ": " << go(0, e) << endl;
  }
  return 0;
}