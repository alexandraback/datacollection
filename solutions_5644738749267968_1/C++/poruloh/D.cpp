#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

int deceit(vector <double> a, vector <double> b) {
  int ans = 0;
  while (!a.empty()) {
    if (a[0] > b[0]) {
      ans++;
      a.erase(a.begin());
      b.erase(b.begin());
    }
    else {
      a.erase(a.begin());
      b.erase(--b.end());
    }
  }
  return ans;
}

int main(void) {
  
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector <double> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int y = deceit(a, b);
    int z = 0;
    int at = 0;
    for (int i = 0; i < N; i++) {
      while (at < N && a[i] > b[at])
	at++;
      if (at == N) {
	z = N-i;
	break;
      }
      at++;
    }
    printf("Case #%d: %d %d\n", t, y, z);
  }
}
