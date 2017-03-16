#include <bits/stdc++.h>
using namespace std;

#define int long long
int convert(vector<int> x, int K) {
  int pos = 0;
  int f = 1;
  for (int i = 0; i < x.size(); ++i) {
    pos += x[x.size()-1-i] * f;
    f *= K;
  }
  return pos;
}

#undef int
int main() {
#define int long long
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int K, C, S;
    cin >> K >> C >> S;
    printf("Case #%d:", i+1);
    if (K > C * S) {
      printf(" IMPOSSIBLE\n");
      continue;
    }
    set<int> used;
    for (int j = 0; j < ceil((double) K / C); ++j) {
      vector<int> chosen(C, 0);
      iota(chosen.begin(), chosen.end(), j*C);
      for (auto &x : chosen) {
        x = min(K-1, x);
      }
      int v = convert(chosen, K)+1;
      assert(!used.count(v));
      used.insert(v);
      printf(" %lld", v);
    }
    printf("\n");
  }
}