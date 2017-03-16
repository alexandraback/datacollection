#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <sstream>
#include <utility>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cassert>

using namespace std;

const int N = 1000100;
int f[N];

int rev(int x) {
  int ret = 0;
  while(x) {
    ret = ret * 10 + (x % 10);
    x /= 10;
  }
  return ret;
}

int nextS(int at) {
  int ff = at + 1;
  int ss = rev(at);
  int tt = rev(ss);
  int dd = rev(tt);
  return min(ff, max(ss, max(tt, dd)));
}

int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < N; i++) f[i] = 99999999; 
  f[1] = 1;
  for (int i = 1; i <= 1000010; i++) {
    int r = rev(i);
    if (r <= N)
      f[r] = min(f[r], f[i] + 1);
    f[i + 1] = min(f[i] + 1, f[i + 1]);
  }
  int tt;
  cin >> tt;
  for (int id = 1; id <= tt; id++) {
    int n;
    cin >> n;
    cout << "Case #" << id << ": " << f[n] << endl;
  }
  return 0;
}