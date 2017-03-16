#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

int N;
Vi bff;
Mi inv;

int cycle(int x) {
  int y = bff[x];
  for (int i = 1; i <= N; ++i) {
    if (x == y) {
      return i;
    }
    y = bff[y];
  }
  return -1;
}

int longest(int x, int p) {
  int res = 1;
  for (int i = 0; i < int(inv[x].size()); ++i) {
    int y = inv[x][i];
    if (y != p) {
      res = max(res, 1 + longest(y, x));
    }
  }
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cin >> N;
    bff = Vi(N);
    inv = Mi(N);
    for (int i = 0; i < N; ++i) {
      cin >> bff[i];
      --bff[i];
      inv[bff[i]].push_back(i);
    }
    int largest_cycle = 0;
    int sum_chains = 0;
    for (int i = 0; i < N; ++i) {
      int c = cycle(i);
      if (c != -1) {
        largest_cycle = max(largest_cycle, c);
      }
      if (c == 2 and i < bff[i]) {
        sum_chains += longest(i, bff[i]) + longest(bff[i], i);
      }
    }
    int res = max(largest_cycle, sum_chains);
    cout << "Case #" << cas << ": " << res << endl;
  }
}
