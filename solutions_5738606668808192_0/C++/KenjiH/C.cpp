#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

int n, m;

long long powll(long long x, int p) {
  long long ret = 1;
  for (int i = 0; i < p; i++) ret *= x;
  return ret;
}

string b2s(long long x) {
  string ret;
  while (x) {
    ret += (x%2 + '0');
    x >>= 1;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

void solve() {
  cin >> n >> m;
  long long x = (1LL << n) - 1;
  int n2 = n/2;
  for (int i = 0; m; i++, m--) {
    long long mask = i << 1 | 1 | 1 << (n2-1);
    mask = mask | mask << n2;
    cout << b2s(x & mask);
    for (int j = 2; j <= 10; j++)
      cout << " " << powll(j, n2) + 1;
    cout << endl;
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cerr << "Case #" << i+1 << ":" << endl;
        cout << "Case #" << i+1 << ":" << endl;
        solve();
    }
    return 0;
}
