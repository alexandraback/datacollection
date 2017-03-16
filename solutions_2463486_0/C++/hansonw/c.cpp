#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int dig[21];
bool palin(long long x)
{
  int nd = 0;
  while (x) {
    dig[nd++] = x % 10;
    x /= 10;
  }
  for (int j = 0; j+j < nd; j++) {
    if (dig[j] != dig[nd-1-j]) {
      return false;
    }
  }
  return true;
}

int main()
{
  vector<long long> pals;
  for (int i = 1; i < 1e7; i++) {
    if (!palin(i)) continue;
    long long sqr = (long long)i * i;
    if (palin(sqr)) {
      pals.push_back(sqr);
    }
  }
  
  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    int A, B; cin >> A >> B;
    int x = lower_bound(pals.begin(), pals.end(), A) - pals.begin();
    int y = lower_bound(pals.begin(), pals.end(), B) - pals.begin();
    if (y == pals.size() || pals[y] > B) {
      y--;
    }
    
    printf("Case #%d: %d\n", tt, y-x+1 < 0 ? 0 : y-x+1);
  }
}