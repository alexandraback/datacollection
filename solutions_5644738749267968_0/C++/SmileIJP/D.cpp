#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }

void solve() {
  int n = next< int >();
  vector< double > naomi(n, 0);
  vector< double > ken(n, 0);
  generate(ALL(naomi), next< double >);
  generate(ALL(ken), next< double >);

  sort(ALL(naomi));
  sort(ALL(ken));

  int y = 0;
  int lk = 0;
  for (int i = 0; i < n; ++i) {
    if (naomi[i] > ken[lk]) {
      y++;
      lk++;
    }
  }

  int z = 0;
  lk = 0;
  int rk = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (naomi[i] > ken[rk]) {
      z++;
      lk++;
    } else {
      rk--;
    }
  }
  printf("%d %d\n", y, z);
}

int main() {

//  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }


  return 0;
}

