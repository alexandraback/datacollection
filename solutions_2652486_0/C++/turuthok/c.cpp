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

const int N = 12;

int p[N];
map<int, set<int> > all;
vector<int> numbers;

void go(int idx, int n, int m) {
  if (idx == n) {
    int value = 0;
    for (int i = 0; i < n; i++) value = value * 10 + p[i];
    numbers.push_back(value);

    for (int mask = 0; mask < (1 << n); mask++) {
      int mult = 1;
      for (int i = 0, mm = 1; i < n; i++, mm <<= 1) {
        if (mask & mm) {
          mult *= p[i];
        }
      }
      all[mult].insert(value);
    }
    return;
  }

  for (int i = (idx == 0 ? 2 : p[idx-1]); i <= m; i++) {
    p[idx] = i;
    go(idx+1, n, m);
  }
}

int main() {
  int cases; cin >> cases;
  for (int caseNo = 1; caseNo <= cases; caseNo++) {
    int r, n, m, k; cin >> r >> n >> m >> k;
    go(0, n, m);

    cout << "Case #" << caseNo << ":" << endl;
    for (int i = 0; i < r; i++) {
      vector<bool> valid(numbers.size(), true);
      vector<int> hits(numbers.size(), 0);

      for (int j = 0; j < k; j++) {
        int prod; cin >> prod;
        set<int>& ss = all[prod];
        for (int x = 0; x < numbers.size(); x++) if (valid[x]) {
          if (ss.find(numbers[x]) == ss.end()) {
            valid[x] = false;
          } else {
            hits[x]++;
          }
        }
      }

      int pick = -1;
      for (int j = 0; j < numbers.size(); j++) if (valid[j]) {
        if (pick < 0 || hits[j] > hits[pick]) pick = j;
      }
      cout << numbers[pick] << endl;
    }
  }
  return 0;
}